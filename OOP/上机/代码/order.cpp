#include "order.h"
#include "goods.h"
#include "config.h"

#include <string>
#include <map>
#include <list>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdint>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::list;
using std::localtime;
using std::map;
using std::ofstream;
using std::stoul;
using std::string;
using std::time_t;
using std::to_string;
using std::vector;

const char endl = '\n';

uint32_t Order::generate_id(Config &cfg)
{
    uint32_t id = stoul(cfg.get_order_id());
    cfg.set_order_id(to_string(id + 1));
    return id;
}

Order::Order(GoodsManager *gm, const string &receiver, const string &address, const string &phone)
    : order_id(0),
      order_time(0),
      paid_time(0),
      order_receiver(receiver),
      order_address(address),
      order_phone(phone),
      order_status(OrderStatus::UNPLACED),
      item_list(),
      order_total(0),
      sub_stock(false),
      goods_manager(gm)
{
}

Order::Order(GoodsManager *gm, uint32_t order_id, time_t order_time, time_t paid_time,
             const string &receiver, const string &address, const string &phone,
             OrderStatus order_status, const vector<OrderItem> &item_list, double order_total)
    : order_id(order_id),
      order_time(order_time),
      paid_time(paid_time),
      order_receiver(receiver),
      order_address(address),
      order_phone(phone),
      order_status(order_status),
      item_list(item_list),
      order_total(order_total),
      sub_stock(true),
      goods_manager(gm)
{
}

Order Order::load_order(GoodsManager *gm, const string &line)
{
    vector<string> tokens;
    vector<OrderItem> item_list;
    istringstream ss(line);
    string tmp;
    // 读取并解析
    while (getline(ss, tmp, ','))
        tokens.push_back(tmp);
    for (auto pos = 7; pos < tokens.size() - 1; pos += 4)
    {
        auto id = static_cast<uint32_t>(stoul(tokens[pos]));
        auto name = tokens[pos + 1];
        auto price = stof(tokens[pos + 2]);
        auto amount = static_cast<uint32_t>(stoul(tokens[pos + 3]));
        item_list.push_back(OrderItem(id, name, price, amount));
    }
    return Order(gm,
                 static_cast<uint32_t>(stoul(tokens[0])),
                 static_cast<time_t>(stoll(tokens[1])),
                 static_cast<time_t>(stoll(tokens[2])),
                 tokens[3],
                 tokens[4],
                 tokens[5],
                 static_cast<OrderStatus>(stoi(tokens[6])),
                 item_list,
                 stod(tokens.back()));
}

const string &Order::check_status() const
{
    static vector<string> status_str = {
        "UNPLACED", "UNPAID", "PAID", "UNSHIPPED", "SHIPPING", "DELIVERED", "CANCELLED"};
    return status_str[order_status];
}

const string &Order::get_order_time() const
{
    char buffer[64];
    std::strftime(buffer, 64, "%Y-%m-%d %H:%M:%S", localtime(&order_time));
    static string str;
    str = buffer;
    return str;
}

const string &Order::get_paid_time() const
{
    char buffer[64];
    std::strftime(buffer, 64, "%Y-%m-%d %H:%M:%S", localtime(&paid_time));
    static string str;
    str = buffer;
    return str;
}

bool Order::change_receiver(const string &receiver)
{
    if (order_status <= OrderStatus::UNSHIPPED)
    {
        order_receiver = receiver;
        return true;
    }
    return false;
}

bool Order::change_address(const string &address)
{
    if (order_status <= OrderStatus::UNSHIPPED)
    {
        order_address = address;
        return true;
    }
    return false;
}

bool Order::change_phone(const string &phone)
{
    if (order_status <= OrderStatus::UNSHIPPED)
    {
        order_phone = phone;
        return true;
    }
    return false;
}

bool Order::add_goods(uint32_t goods_id, uint32_t amount)
{
    auto const goods = goods_manager->search_goods(goods_id, true);
    if (goods.get_id() == 0)
        return false;
    item_list.push_back(OrderItem(goods, amount));
    return true;
}

double Order::update_total()
{
    order_total = 0;
    for (auto const &item : item_list)
    {
        auto price = item.price;
        if (item.tag.is_discount && order_time <= item.tag.discount_end_time)
            price *= (1.0 - item.tag.discount / 100.0);
        auto item_total = price * item.amount;
        if (item.tag.is_reduction && order_time <= item.tag.reduction_end_time)
            item_total -= (uint32_t(item_total / item.tag.spend) * item.tag.reduction);
        order_total += item_total;
    }
    return order_total;
}

bool Order::pay()
{
    if (order_status == OrderStatus::UNPAID)
    {
        order_status = OrderStatus::PAID;
        paid_time = time(nullptr);
        for (auto const &item : item_list) // 检测库存是否够用
        {
            auto goods = goods_manager->search_goods(item.goods_id, true);
            if (goods.get_stock() <= item.amount) // 至少剩一件
                return false;
        }
        for (auto const &item : item_list) // 扣除库存
        {
            auto goods = goods_manager->search_goods(item.goods_id, true);
            uint32_t new_stock = goods.get_stock() - item.amount;
            goods_manager->update_goods(item.goods_id,
                                        "", false,
                                        0, false,
                                        new_stock, true,
                                        "", false,
                                        goods.get_promotion(), false);
        }
        return sub_stock = true;
    }
    return false;
}

bool Order::place_order(Config &cfg)
{
    order_id = generate_id(cfg);
    if (order_status != OrderStatus::UNPLACED)
        return false;
    order_status = OrderStatus::UNPAID;
    order_time = time(nullptr);
    update_total();
    return true;
}

bool Order::cancel_order()
{
    if (order_status > OrderStatus::UNSHIPPED)
        return false;
    if (order_status == OrderStatus::UNPAID)
    {
        paid_time = time(nullptr); // 取消订单时，支付时间设置为取消时间
        order_status = OrderStatus::CANCELLED;
        return true;
    }
    order_status = OrderStatus::CANCELLED;
    if (sub_stock)
        for (auto const &item : item_list) // 增加库存
        {
            auto goods = goods_manager->search_goods(item.goods_id, true);
            uint32_t new_stock = goods.get_stock() + item.amount;
            goods_manager->update_goods(item.goods_id,
                                        "", false,
                                        0, false,
                                        new_stock, true,
                                        "", false,
                                        goods.get_promotion(), false);
        }
    item_list.clear();
    return true;
}

/* 重载 ++ 运算符，方便更新状态 */
OrderStatus &operator++(OrderStatus &other)
{
    if (other != OrderStatus::DELIVERED)
        return other = OrderStatus(int(other) + 1);
    return other;
}

bool Order::update_status()
{
    // 已送达或已取消订单状态不再更新
    if (order_status == OrderStatus::DELIVERED || order_status == OrderStatus::CANCELLED)
        return false;
    auto sub = time(nullptr) - paid_time; // 计算时间差
    if (sub < 10)                         // 时间太短，不更新状态
        return false;
    else if (sub < 20) // 状态更新一次
        ++order_status;
    else if (sub < 30) // 状态更新两次
        ++ ++order_status;
    else if (sub < 40) // 状态更新三次
        ++ ++ ++order_status;
    else // 状态更新三次以上，订单完成
        order_status = OrderStatus::DELIVERED;
    return true;
}

OrderManager::OrderManager(const string &filename, GoodsManager &goods_manager)
    : order_list(), filename(filename), goods_manager(goods_manager), change(false)
{
    load();
}

OrderManager::~OrderManager()
{
    if (change)
        save();
}

void OrderManager::load()
{
    order_list.clear();
    ifstream in(filename, ifstream::in);
    if (!in.is_open())
    {
        ofstream out(filename, ofstream::out); // 不存在则新建文件
        out.close();
        return;
    }
    string line;
    while (getline(in, line))
        order_list.push_back(Order::load_order(&goods_manager, line));
    in.close();
}

void OrderManager::save() const
{
    ofstream out(filename, ofstream::out);
    if (!out.is_open())
    {
        cout << "Failed to save order list to file " << filename << '.' << endl;
        return;
    }
    for (const auto &item : order_list)
    {
        out << item.get_id() << ','
            << item.get_order_time(true) << ','
            << item.get_paid_time(true) << ','
            << item.get_receiver() << ','
            << item.get_address() << ','
            << item.get_phone() << ','
            << item.check_status(true) << ',';
        for (auto const &order_item : item.get_item_list())
            out << order_item.goods_id << ','
                << order_item.name << ','
                << order_item.price << ','
                << order_item.amount << ',';
        out << item.get_total() << endl;
    }
    out.close();
}

void OrderManager::set_filename(const string &new_filename)
{
    if (change)
        save();
    filename = new_filename;
    change = false;
    load();
    cout << "Filename has been changed to " << filename << endl;
}

void OrderManager::remove_order(uint32_t order_id)
{
    for (auto it = order_list.begin(); it != order_list.end(); ++it)
        if (it->get_id() == order_id)
        {
            order_list.erase(it);
            change = true;
            break;
        }
}

void OrderManager::add_order(const Order &order)
{
    order_list.push_back(order);
    change = true;
}

void OrderManager::view_order(uint32_t order_id) const
{
    cout << "================================================================\n";
    if (order_list.empty())
        return;
    if (order_id == 0)
    {
        for (const auto &item : order_list)
        {
            cout << "id:         " << item.get_id() << endl
                 << "order_time: " << item.get_order_time() << endl
                 << "paid_time:  " << item.get_paid_time() << endl
                 << "receiver:   " << item.get_receiver() << endl
                 << "address:    " << item.get_address() << endl
                 << "phone:      " << item.get_phone() << endl
                 << "status:     " << item.check_status() << endl;
            for (auto const &order_item : item.get_item_list())
                cout << "goods_id:   " << order_item.goods_id << endl
                     << "name:       " << order_item.name << endl
                     << "price:      " << order_item.price << endl
                     << "amount:     " << order_item.amount << endl;
            cout << "total:      " << item.get_total() << endl
                 << "================================================================\n";
        }
    }
    else
        for (const auto &item : order_list)
            if (item.get_id() == order_id)
            {
                cout << "id:         " << item.get_id()
                     << "order_time: " << item.get_order_time() << endl
                     << "paid_time:  " << item.get_paid_time() << endl
                     << "receiver:   " << item.get_receiver() << endl
                     << "address:    " << item.get_address() << endl
                     << "phone:      " << item.get_phone() << endl
                     << "status:     " << item.check_status() << endl;
                for (auto const &order_item : item.get_item_list())
                    cout << "goods_id:   " << order_item.goods_id << endl
                         << "name:       " << order_item.name << endl
                         << "price:      " << order_item.price << endl
                         << "amount:     " << order_item.amount << endl;
                cout << "total:      " << item.get_total() << endl
                     << "================================================================\n";
            }
}

pair<vector<Order>::iterator, bool> OrderManager::find_order(uint32_t order_id)
{
    for (auto it = order_list.begin(); it != order_list.end(); ++it)
        if (it->get_id() == order_id)
            return pair<vector<Order>::iterator, bool>(it, true);
    return pair<vector<Order>::iterator, bool>(order_list.end(), false);
}

void OrderManager::update_all_order_status()
{
    for (auto &item : order_list)
        if (item.update_status())
            change = true;
}