#ifndef ORDER_H
#define ORDER_H
#pragma once

#include "goods.h"
#include "promotion.h"
#include "config.h"

#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <cstdint>

using std::map;
using std::pair;
using std::string;
using std::time_t;
using std::vector;

enum OrderStatus : int
{
    UNPLACED,  // 未下单
    UNPAID,    // 未支付
    PAID,      // 已支付
    UNSHIPPED, // 未发货
    SHIPPING,  // 运输中
    DELIVERED, // 已送达
    CANCELLED  // 已取消
};

struct OrderItem // 订单项，保存下单时商品的快照
{
    uint32_t goods_id;
    string name;
    float price;
    uint32_t amount;
    promotion_tag tag;
    OrderItem(uint32_t id, const string &n, float p, uint32_t a)
        : goods_id(id), name(n), price(p), amount(a), tag() {}
    OrderItem(uint32_t id, const string &n, float p, uint32_t a, const promotion_tag &t)
        : goods_id(id), name(n), price(p), amount(a), tag(t) {}
    OrderItem(const Goods &g, uint32_t a) : amount(a)
    {
        goods_id = g.get_id();
        name = g.get_name();
        price = g.get_price();
        tag = g.get_promotion();
    }
};

class Order
{
private:
    uint32_t order_id;           // 订单号
    time_t order_time;           // 创建订单时间
    time_t paid_time;            // 支付时间
    string order_receiver;       // 订单收件人
    string order_address;        // 订单地址
    string order_phone;          // 订单联系方式
    OrderStatus order_status;    // 订单状态
    vector<OrderItem> item_list; // 订单列表
    double order_total;          // 订单总价
    bool sub_stock;              // 是否已经扣除库存
    GoodsManager *goods_manager; // 商品管理器
private:
    static uint32_t generate_id(Config &cfg); // 生成订单号
    Order(GoodsManager *gm,
          uint32_t order_id,
          time_t order_time,
          time_t paid_time,
          const string &receiver,
          const string &address,
          const string &phone,
          OrderStatus order_status,
          const vector<OrderItem> &item_list,
          double order_total); // 私有构造函数，仅供内部使用

public:
    Order(GoodsManager *gm,
          const string &receiver = "",
          const string &address = "",
          const string &phone = ""); // 创建新订单

    static Order load_order(GoodsManager *gm, const string &line); // 读取已有订单
    /* 状态查询 */
    OrderStatus check_status(bool) const { return order_status; }
    const string &check_status() const;
    uint32_t get_id() const { return order_id; }
    const string &get_order_time() const;
    const string &get_paid_time() const;
    time_t get_order_time(bool) const { return order_time; };
    time_t get_paid_time(bool) const { return paid_time; };
    double get_total() const { return order_total; }
    const string &get_receiver() const { return order_receiver; }
    const string &get_address() const { return order_address; }
    const string &get_phone() const { return order_phone; }
    const vector<OrderItem> &get_item_list() const { return item_list; }
    /* 订单操作 */
    double update_total();
    bool change_receiver(const string &receiver);
    bool change_address(const string &address);
    bool change_phone(const string &phone);
    bool add_goods(uint32_t goods_id, uint32_t amount);
    bool remove_goods(uint32_t goods_id);
    bool place_order(Config &cfg);
    bool pay();
    bool cancel_order();
    bool update_status();
};

class OrderManager
{
private:
    vector<Order> order_list;    // 订单列表
    string filename;             // 订单文件名
    GoodsManager &goods_manager; // 商品管理器
    bool change;                 // 是否需要保存

public:
    OrderManager(const string &filename, GoodsManager &goods_manager);
    ~OrderManager();
    void set_filename(const string &new_filename); // 设置存档文件名
    void remove_order(uint32_t order_id);
    void add_order(const Order &order);
    void view_order(uint32_t order_id = 0) const;
    pair<vector<Order>::iterator, bool> find_order(uint32_t order_id);
    void update_all_order_status();
    void load();
    void save() const;
};

#endif // ORDER_H