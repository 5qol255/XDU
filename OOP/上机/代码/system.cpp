#define elif else if

#include "system.h"
#include "config.h"
#include "user.h"
#include "functions.h"
#include "goods.h"
#include "shoppinglist.h"
#include "order.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <cstdint>

using std::cerr;
using std::cin;
using std::cout;
using std::exception;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::pair;
using std::runtime_error; // 抛出运行时异常
using std::stoul;
using std::string;
using std::unordered_map; // 无序映射表
using std::vector;

const char endl = '\n';

System::System(Config &cfg)
    : config(cfg),                                                            // 引用传递设置类
      running(false),                                                         // 系统运行状态
      admin(true, false, cfg.get_admin_username(), cfg.get_admin_password()), // 创建管理员账户
      is_admin_active(false),                                                 // 管理员默认不活跃
      guest(false, true),                                                     // 创建访客账户
      is_guest_active(true),                                                  // 访客默认活跃
      current(),                                                              // 创建普通账号
      is_current_active(false),                                               // 普通账号默认不活跃
      account_map(),                                                          // 创建账号映射表
      goods_manager(cfg.get_goods_path()),                                    // 创建商品管理器
      shopping_list(cfg.get_shopping_list_path(), goods_manager),             // 创建购物车
      order_manager(cfg.get_order_list_path(), goods_manager)                 // 创建订单管理器
{
    /* 解绑stdio */
    std::ios::sync_with_stdio(false);
    /* 加载账号映射表 */
    load_account_map();
    /* 初始化随机数种子 */
    srand(time(nullptr));
    cout << "System has been initialized." << endl;
}

void System::load_account_map()
{
    ifstream file(config.get_accounts_path(), ifstream::in);
    if (!file.is_open())
        cerr << "Failed to open data file." << endl;
    else
    {
        string line;
        int start, end;
        vector<string> tmp;
        getline(file, line);        // 跳过第一行
        while (getline(file, line)) // 读取每一行
        {
            line = strip(line); // 去除换行符
            start = 0;
            end = line.find(',', start);
            for (int i = 0; i < 4; ++i) // 解析行
            {
                tmp.push_back(line.substr(start, end - start));
                start = end + 1;
                end = line.find(',', start);
            }
            account_map[tmp[0]] = UserInfo{tmp[1], tmp[2], tmp[3]}; // 存入映射表
            tmp.clear();
        }
        file.close();
    }
}

void System::save_account_map() const
{
    ofstream file(config.get_accounts_path(), ofstream::out);
    if (!file.is_open())
        cerr << "Failed to open data file." << endl;
    else
    {
        file << "username,password,shoppinglist_path" << endl;
        for (auto const &item : account_map)
            file << item.first << ','
                 << item.second.password << ','
                 << item.second.shopping_list_file << ','
                 << item.second.order_list_file << endl;
        file.close();
    }
}

System::~System()
{
    cout << "System has exited." << endl;
}

void System::run(const string &welcome_msg)
{
    cout << welcome_msg << endl;
    running = true;
    string input;
    while (running)
    {
        order_manager.update_all_order_status(); // 更新订单状态
        cout << ">>> ";
        if (!get_input(*this, input))            // 读取用户输入
            stop();                              // 退出系统
        order_manager.update_all_order_status(); // 更新订单状态
        handle_input(input);                     // 处理用户输入
    }
}

void System::handle_input(const string &input)
{
    if (input.empty())
        return;
    // 账号相关指令
    elif (input == "help") help();
    elif (input == "exit") exit();
    elif (input == "li") login();
    elif (input == "li su") login(true);
    elif (input == "lo") logout();
    elif (input == "sp") sign_up();
    elif (input == "cp") change_password();
    elif (input == "ca") change_account();
    elif (input == "ca su") change_account(true);
    // 商品相关指令
    elif (input == "adg") goods_add();
    elif (input == "rmg") goods_remove();
    elif (input == "vig") goods_view();
    elif (input == "upg") goods_update();
    elif (input == "shg") goods_search();
    // 购物车相关指令
    elif (input == "ads") shopping_list_add();
    elif (input == "sbs") shopping_list_sub();
    elif (input == "sts") shopping_list_set();
    elif (input == "rms") shopping_list_remove();
    elif (input == "cls") shopping_list_clear();
    elif (input == "vis") shopping_list_view();
    // 订单相关指令
    elif (input == "plo") order_place();
    elif (start_with(input, "buy")) order_place(true, input);
    elif (input == "vio") order_check();
    elif (input == "sho") order_find();
    elif (input == "rmo") order_remove();
    elif (input == "clo") order_cancel();
    elif (input == "cho") order_change();
    else cout
        << "Unknown command: " << input << endl
        << "Enter \"help\" to show available commands." << endl;
}

void System::exit()
{
    running = false;
}

void System::help() const
{
    cout << "Available commands:" << endl
         << "    help:  show help information" << endl
         << "    exit:  exit the system" << endl
         << "    li:    login" << endl
         << "    li su: login as admin" << endl
         << "    lo:    logout" << endl
         << "    sp:    sign up" << endl
         << "    cp:    change password" << endl
         << "    ca:    change account" << endl
         << "    ca su: change account as admin" << endl
         << "    vig:   view available goods" << endl
         << "    shg:   search for goods" << endl
         << "    ads:   add a kind of goods to shopping list" << endl
         << "    sbs:   subtract amount of a kind of goods in shopping list" << endl
         << "    sts:   set amount of a kind of goods in shopping list" << endl
         << "    rms:   remove a kind of goods from shopping list" << endl
         << "    cls:   clear shopping list" << endl
         << "    vis:   view shopping list" << endl
         << "    buy:   buy [id] [amount]: place an order for specific goods" << endl
         << "    plo:   place an order" << endl
         << "    vio:   check order status" << endl
         << "    sho:   search for orders" << endl
         << "    rmo:   remove an order(if possible)" << endl
         << "    clo:   cancel an order(if possible)" << endl
         << "    cho:   change receiver, address and phone of an order" << endl;
    if (is_admin_active) // 管理员特供指令
        cout << "    adg:   add a kind of goods" << endl
             << "    rmg:   remove a kind of goods" << endl
             << "    upg:   update goods information" << endl;
}

void System::login(bool is_admin)
{
    if (is_current_active) // 普通用户已登录
    {
        cout << "You are already logged in as " << current.get_username() << "." << endl;
        return;
    }
    if (is_admin_active) // 管理员登录
    {
        cout << "You are already logged in as admin." << endl;
        return;
    }
    string username, password;
    cout << "Please enter your username: ";
    get_input(*this, username);
    cout << "Please enter your password: ";
    get_input(*this, password);
    if (!is_admin) // 普通用户登录
    {
        auto const it = account_map.find(username);
        if (it == account_map.cend()) // 用户不存在
        {
            cout << "User not registered. Please sign up." << endl;
            return;
        }
        if (it->second.password == password) // 密码正确
        {
            current.set_username(username);
            current.set_pwd(password);
            is_current_active = true;
            is_admin_active = false;
            is_guest_active = false;
            shopping_list.set_filename(it->second.shopping_list_file); // 设置购物清单文件名
            order_manager.set_filename(it->second.order_list_file);    // 设置订单清单文件名
            cout << "Login successful." << endl;
        }
        else // 密码错误
            cout << "Wrong password. Please try again." << endl;
    }
    else // 管理员登录
    {
        if (admin.get_username() == username && admin.get_pwd() == password) // 用户名密码正确
        {
            is_current_active = false;
            is_admin_active = true;
            is_guest_active = false;
            cout << "Login successful." << endl
                 << "Welcome " << admin.get_username() << '!' << endl;
        }
        else // 用户名或密码错误
            cout << "Wrong username or password. Please try again." << endl;
    }
}

void System::logout()
{
    if (is_guest_active) // 当前用户未登录
    {
        cout << "You are not logged in." << endl;
        return;
    }
    current.set_username("");
    current.set_pwd("");
    is_current_active = false;
    is_admin_active = false;
    is_guest_active = true;
    cout << "Logout successful." << endl;
}

void System::sign_up()
{
    if (is_current_active) // 当前用户已登录
    {
        cout << "You are already logged in as " << current.get_username() << "." << endl;
        return;
    }
    if (is_admin_active) // 管理员登录
    {
        cout << "You are already logged in as admin." << endl;
        return;
    }
    string username, password, confirm_password;
    cout << "Please enter your username: ";
    get_input(*this, username);
    auto const it = account_map.find(username);
    if (it != account_map.cend()) // 用户已存在
    {
        cout << "User already registered. Please try another username." << endl;
        return;
    }
    cout << "Please enter your password: ";
    get_input(*this, password);
    cout << "Please cofirm your password: ";
    get_input(*this, confirm_password);
    if (password != confirm_password) // 两次密码不一致
    {
        cout << "Passwords do not match. Please try again." << endl;
        return;
    }
    string shoppinglist_path = "data/" + username + ".sl";
    ofstream file(shoppinglist_path, ofstream::out); // 创建购物清单文件
    file.close();
    string orderlist_path = "data/" + username + ".ol";
    file.open(orderlist_path, ofstream::out); // 创建订单清单文件
    file.close();
    account_map[username] = UserInfo{password, shoppinglist_path, orderlist_path}; // 存入账户信息映射表
    cout << "Sign up successful." << endl;
    // 保存数据
    save_account_map();
}

void System::change_account(bool is_admin)
{
    if (is_guest_active) // 当前用户未登录
    {
        cout << "You are not logged in. Please login first." << endl;
        return;
    }
    logout();
    login(is_admin);
}

void System::change_password()
{
    if (is_guest_active) // 当前用户未登录
    {
        cout << "You are not logged in. Please login first." << endl;
        return;
    }
    if (is_admin_active) // 管理员
    {
        string old_password, new_password, confirm_password;
        cout << "Please enter your old password: ";
        get_input(*this, old_password);
        if (old_password != admin.get_pwd()) // 旧密码错误
        {
            cout << "Wrong password. Please try again." << endl;
            return;
        }
        cout << "Please enter your new password: ";
        get_input(*this, new_password);
        cout << "Please cofirm your new password: ";
        get_input(*this, confirm_password);
        if (new_password != confirm_password) // 两次密码不一致
        {
            cout << "Passwords do not match. Please try again." << endl;
            return;
        }
        admin.set_pwd(new_password);
        config.set_admin_password(new_password); // 更新配置文件
        cout << "Password changed successfully." << endl;
    }
    else
    {
        string old_password, new_password, confirm_password;
        cout << "Please enter your old password: ";
        get_input(*this, old_password);
        if (old_password != current.get_pwd()) // 旧密码错误
        {
            cout << "Wrong password. Please try again." << endl;
            return;
        }
        cout << "Please enter your new password: ";
        get_input(*this, new_password);
        cout << "Please cofirm your new password: ";
        get_input(*this, confirm_password);
        if (new_password != confirm_password) // 两次密码不一致
        {
            cout << "Passwords do not match. Please try again." << endl;
            return;
        }
        current.set_pwd(new_password);
        account_map[current.get_username()].password = new_password; // 更新账户信息映射表
        save_account_map();                                          // 保存数据
        cout << "Password changed successfully." << endl;
    }
}

// ==============================

void System::goods_view() const
{
    cout << "Available goods:" << endl;
    goods_manager.list_goods(); // 只向管理员输出商品id信息
}

void System::goods_add()
{
    if (!is_admin_active)
    {
        cout << "You are not authorized to add goods." << endl;
        return;
    }
    cout << "Please enter the name of the goods: ";
    string name;
    get_input(*this, name);
    cout << "Please enter the price of the goods: ";
    float price;
    get_input(*this, price);
    cout << "Please enter the stock of the goods: ";
    uint32_t stock;
    get_input(*this, stock);
    cout << "Please enter the description of the goods: ";
    string description;
    get_input(*this, description);
    // 促销信息
    cout << "Do you want to add a promotion tag? (y/n): ";
    string yes_or_no;
    bool r = get_input(*this, yes_or_no);
    bool update_tag = r && (yes_or_no == "Y" || yes_or_no == "y");
    promotion_tag tag;
    if (update_tag)
    {
        cout << "Set discount? (y/n): ";
        r = get_input(*this, yes_or_no);
        if (r && (yes_or_no == "Y" || yes_or_no == "y"))
        {
            cout << "Please enter discount(Press enter to cancel discount): ";
            tag.is_discount = get_input(*this, tag.discount);
            if (tag.is_discount)
            {
                cout << "Please enter the end time(%Y-%m-%d %H:%M:%S, default one day): ";
                if (!get_input(*this, tag.discount_end_time))
                    tag.discount_end_time = time(nullptr) + 3600 * 24; // 默认一天
            }
        }
        cout << "Set reduction? (y/n): ";
        r = get_input(*this, yes_or_no);
        if (r && (yes_or_no == "Y" || yes_or_no == "y"))
        {
            cout << "Please enter new reduction(Press enter to cancel reduction): \n"
                 << "spend: ";
            tag.is_reduction = get_input(*this, tag.spend);
            if (tag.is_reduction)
            {
                cout << "reduction: ";
                get_input(*this, tag.reduction);
                cout << "Please enter the end time(%Y-%m-%d %H:%M:%S, default one day): ";
                if (!get_input(*this, tag.reduction_end_time))
                    tag.reduction_end_time = time(nullptr) + 3600 * 24; // 默认一天
            }
        }
        cout << "stackable? (y/n): ";
        r = get_input(*this, yes_or_no);
        tag.both = r && (yes_or_no == "Y" || yes_or_no == "y");
    }
    goods_manager.add_goods(Goods(config, name, price, stock, description, tag));
    cout << "Goods added successfully." << endl;
}

void System::goods_remove()
{
    if (!is_admin_active)
    {
        cout << "You are not authorized to remove goods." << endl;
        return;
    }
    cout << "Please enter the id of the goods to remove: ";
    uint32_t id = 0u;
    if (!get_input(*this, id)) // 保证id输入有效
    {
        cout << "Invalid input. Please try again." << endl;
        return;
    }
    if (goods_manager.remove_goods(id))
        cout << "Goods removed successfully." << endl;
    else
        cout << "Failed to remove goods. No such kind of goods." << endl;
}

void System::goods_update()
{
    if (!is_admin_active)
    {
        cout << "You are not authorized to update goods." << endl;
        return;
    }
    // 输入id
    cout << "Please enter the id of the goods to update: ";
    uint32_t id = 0u;
    if (!get_input(*this, id) || id == 0) // 保证id输入有效
    {
        cout << "Invalid input. Please try again." << endl;
        return;
    }
    // 更新名称
    cout << "Please enter the new name of the goods(Press enter to skip): ";
    string name;
    get_input(*this, name);
    bool update_name = !name.empty();
    // 更新价格
    cout << "Please enter the new price of the goods(Press enter to skip): ";
    float price = 0.0f;
    bool update_price = get_input(*this, price);
    // 更新库存
    cout << "Please enter the new stock of the goods(Press enter to skip): ";
    uint32_t stock = 0u;
    bool update_stock = get_input(*this, stock);
    // 更新描述
    cout << "Please enter the new description of the goods(Press enter to skip): ";
    string description;
    get_input(*this, description);
    bool update_description = !description.empty();
    // 更新促销信息
    cout << "Do you want to update the promotion tag? (y/n): ";
    string yes_or_no;
    bool r = get_input(*this, yes_or_no);
    bool update_tag = r && (yes_or_no == "Y" || yes_or_no == "y");
    promotion_tag tag;
    if (update_tag)
    {
        cout << "Change discount? (y/n): ";
        r = get_input(*this, yes_or_no);
        if (r && (yes_or_no == "Y" || yes_or_no == "y"))
        {
            cout << "Please enter new discount(Press enter to cancel discount): ";
            tag.is_discount = get_input(*this, tag.discount);
            if (tag.is_discount)
            {
                cout << "Please enter the end time(%Y-%m-%d %H:%M:%S, default one day): ";
                if (!get_input(*this, tag.discount_end_time))
                    tag.discount_end_time = time(nullptr) + 3600 * 24; // 默认一天
            }
        }
        cout << "Change reduction? (y/n): ";
        r = get_input(*this, yes_or_no);
        if (r && (yes_or_no == "Y" || yes_or_no == "y"))
        {
            cout << "Please enter new reduction(Press enter to cancel reduction): \n"
                 << "spend: ";
            tag.is_reduction = get_input(*this, tag.spend);
            if (tag.is_reduction)
            {
                cout << "reduction: ";
                tag.is_reduction = get_input(*this, tag.reduction);
                cout << "Please enter the end time(%Y-%m-%d %H:%M:%S, default one day): ";
                if (!get_input(*this, tag.reduction_end_time))
                    tag.reduction_end_time = time(nullptr) + 3600 * 24; // 默认一天
            }
        }
        cout << "stackable? (y/n): ";
        r = get_input(*this, yes_or_no);
        tag.both = r && (yes_or_no == "Y" || yes_or_no == "y");
    }
    bool result = goods_manager.update_goods(id,
                                             name, update_name,
                                             price, update_price,
                                             stock, update_stock,
                                             description, update_description,
                                             tag, update_tag);
    if (result)
        if (update_name || update_price || update_stock || update_description || update_tag)
            cout << "Goods updated successfully." << endl;
        else
            cout << "Nothing to update." << endl;
    else
        cout << "Failed to update goods. No such kind of goods." << endl;
}

void System::goods_search()
{
    cout << "Please enter the keyword to search for: ";
    string keyword;
    if (get_input(*this, keyword))
        goods_manager.search_goods(keyword);
    else
        cout << "Invalid input. Please try again." << endl;
}

// ==============================

void System::shopping_list_add()
{
    uint32_t id, amount;
    cout << "Please enter the id of the goods to add: ";
    if (!get_input(*this, id))
    {
        cout << "Invalid input. Please try again." << endl;
        return;
    }
    cout << "Please enter the amount of the goods to add: ";
    if (!get_input(*this, amount))
        amount = 1u;
    shopping_list.add(id, amount);
}

void System::shopping_list_sub()
{
    uint32_t id, amount;
    cout << "Please enter the id of the goods to subtract: ";
    if (!get_input(*this, id)) // 保证id输入有效
    {
        cout << "Invalid input. Please try again." << endl;
        return;
    }
    cout << "Please enter the amount of the goods to subtract: ";
    if (!get_input(*this, amount))
        amount = 1u;
    shopping_list.sub(id, amount);
}

void System::shopping_list_set()
{
    uint32_t id, amount;
    cout << "Please enter the id of the goods to set: ";
    if (!get_input(*this, id)) // 保证id输入有效
    {
        cout << "Invalid input. Please try again." << endl;
        return;
    }
    cout << "Please enter the amount of the goods to set: ";
    if (!get_input(*this, amount))
    {
        cout << "Invalid input. Please try again." << endl;
        return;
    }
    if (amount <= 0)
    {
        cout << "Are you sure want to remove this item from shopping list? (y/n): " << endl;
        string tmp;
        get_input(*this, tmp);
        if (tmp == "y" || tmp == "Y")
            shopping_list.remove(id);
        else
        {
            cout << "Operation cancelled." << endl;
            return;
        }
    }
    shopping_list.set(id, amount);
}

void System::shopping_list_remove()
{
    cout << "Please enter the id of the goods to remove: ";
    uint32_t id = 0u;
    if (!get_input(*this, id)) // 保证id输入有效
    {
        cout << "Invalid input. Please try again." << endl;
        return;
    }
    shopping_list.remove(id);
}

void System::shopping_list_clear()
{
    shopping_list.clear();
}

void System::shopping_list_view() const
{
    shopping_list.list();
}

// ==============================

void System::order_place(bool flag, const string &ins)
{
    if (is_guest_active) // 未登录拒绝
    {
        cout << "You are not logged in. Please login first." << endl;
        return;
    }
    // 生成订单
    Order order(&goods_manager);
    if (flag == false) // 从购物车下单
    {
        if (shopping_list.empty()) // 空购物车拒绝
        {
            cout << "Your shopping list is empty. Please add some goods first." << endl;
            return;
        }
        // 填写信息
        string receiver, address, phone;
        cout << "Please enter the receiver's name: ";
        get_input(*this, receiver);
        order.change_receiver(receiver);
        cout << "Please enter the receiver's address: ";
        get_input(*this, address);
        order.change_address(address);
        cout << "Please enter the receiver's phone number: ";
        get_input(*this, phone);
        order.change_phone(phone);
        // 遍历购物车
        for (auto const &item : shopping_list.get_shopping_list())
            order.add_goods(item.first, item.second); // 添加商品
        // 询问是否清空购物车
        cout << "Do you want to remove these items from shopping list? (y/n): " << endl;
        string tmp;
        get_input(*this, tmp);
        if (tmp == "y" || tmp == "Y")
            shopping_list_clear();
    }
    else // 直接下单
    {
        vector<string> args;
        istringstream ss(ins);
        string arg;
        ss >> arg; // 跳过buy字段
        while (ss >> arg)
            args.push_back(arg);
        if (args.size() & 1 || args.size() < 2) // 奇数个参数或少于两个参数拒绝
        {
            cout << "Arguments mistake. Please try again." << endl;
            return;
        }
        // 填写信息
        string receiver, address, phone;
        cout << "Please enter the receiver's name: ";
        get_input(*this, receiver);
        order.change_receiver(receiver);
        cout << "Please enter the receiver's address: ";
        get_input(*this, address);
        order.change_address(address);
        cout << "Please enter the receiver's phone number: ";
        get_input(*this, phone);
        order.change_phone(phone);
        // 遍历参数添加商品
        for (auto it = args.begin(); it != args.end(); it += 2)
            order.add_goods(stoul(*it), stoul(*(it + 1)));
    }
    // 下单
    order.place_order(config);
    // 输出总价
    cout << "Order summary:" << order.get_total() << endl;
    // 支付
    cout << "Order created successfully. Please pay for it. Y/N: " << endl;
    string tmp;
    get_input(*this, tmp);
    if (tmp == "y" || tmp == "Y") // 支付
    {
        bool result = order.pay();
        if (result == false) // 支付失败
        {
            cout << "Stocks not enough. Order cancelled." << endl;
            order.cancel_order();
        }
        else // 支付成功
            cout << "Payment successful." << endl;
    }
    else // 取消支付
    {
        cout << "Payment failed. Order cancelled." << endl;
        order.cancel_order();
    }
    order_manager.add_order(order); // 保存订单
}

void System::order_cancel()
{
    if (is_guest_active) // 未登录拒绝
    {
        cout << "You are not logged in. Please login first." << endl;
        return;
    }
    cout << "Please enter the id of the order to cancel: ";
    uint32_t id = 0u;
    if (!get_input(*this, id)) // 保证id输入有效
    {
        cout << "Invalid input. Please try again." << endl;
        return;
    }
    auto it = order_manager.find_order(id);
    if (it.second == false) // 订单不存在
    {
        cout << "No such order." << endl;
        return;
    }
    if (it.first->cancel_order()) // 取消成功
        cout << "Order cancelled successfully." << endl;
    else // 取消失败
        cout << "Failed to cancel order. Your order has shipped." << endl;
}

void System::order_change()
{
    cout << "Please enter the id of the order to change: ";
    uint32_t id = 0u;
    if (!get_input(*this, id)) // 保证id输入有效
    {
        cout << "Invalid input. Please try again." << endl;
        return;
    }
    auto it = order_manager.find_order(id);
    if (it.second == false) // 订单不存在
    {
        cout << "No such order." << endl;
        return;
    }
    elif (it.first->check_status(true) >= OrderStatus::SHIPPING) // 订单已发货
    {
        cout << "Order has shipped." << endl;
        return;
    }
    string receiver, address, phone;
    cout << "Please enter the new receiver's name(press enter to skip): ";
    get_input(*this, receiver);
    cout << "Please enter the new receiver's address(press enter to skip): ";
    get_input(*this, address);
    cout << "Please enter the new receiver's phone number(press enter to skip): ";
    get_input(*this, phone);
    if (!receiver.empty())
        it.first->change_receiver(receiver);
    if (!address.empty())
        it.first->change_address(address);
    if (!phone.empty())
        it.first->change_phone(phone);
    cout << "Order changed successfully." << endl;
}

void System::order_check() const
{
    if (is_guest_active) // 未登录拒绝
    {
        cout << "You are not logged in. Please login first." << endl;
        return;
    }
    order_manager.view_order(0);
}

void System::order_find()
{
    if (is_guest_active) // 未登录拒绝
    {
        cout << "You are not logged in. Please login first." << endl;
        return;
    }
    uint32_t id = 0u;
    cout << "Please enter the id of the order to check: ";
    if (!get_input(*this, id)) // 保证id输入有效
    {
        cout << "Invalid input. Please try again." << endl;
        return;
    }
    order_manager.view_order(id);
}

void System::order_remove()
{
    if (is_guest_active) // 未登录拒绝
    {
        cout << "You are not logged in. Please login first." << endl;
        return;
    }
    uint32_t id = 0u;
    cout << "Please enter the id of the order to remove: ";
    if (!get_input(*this, id)) // 保证id输入有效
    {
        cout << "Invalid input. Please try again." << endl;
        return;
    }
    auto it = order_manager.find_order(id);
    if (it.second == false) // 订单不存在
    {
        cout << "No such order." << endl;
        return;
    }
    if (it.first->check_status(true) != OrderStatus::DELIVERED &&
        it.first->check_status(true) != OrderStatus::CANCELLED) // 订单未完成
        cout << "Order has not finished. Cannot remove it." << endl;
    else
    {
        order_manager.remove_order(id);
        cout << "Order removed successfully." << endl;
    }
}
