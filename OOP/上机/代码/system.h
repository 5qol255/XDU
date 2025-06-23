#ifndef SYSTEM_H
#define SYSTEM_H
#pragma once

#include "config.h"
#include "user.h"
#include "goods.h"
#include "shoppinglist.h"
#include "order.h"

#include <cstdint>
#include <string>
#include <unordered_map>

using std::pair;
using std::string;
using std::unordered_map;

struct UserInfo
{
    string password;
    string shopping_list_file;
    string order_list_file;
};

class System
{
private:
    Config &config;                              // 配置信息
    bool running;                                // 系统运行状态
    User admin;                                  // 管理员
    bool is_admin_active;                        // 管理员活跃状态
    User guest;                                  // 访客
    bool is_guest_active;                        // 访客活跃状态
    User current;                                // 当前用户
    bool is_current_active;                      // 当前用户活跃状态
    unordered_map<string, UserInfo> account_map; // 账号映射表
    GoodsManager goods_manager;                  // 商品管理器
    ShoppingList shopping_list;                  // 购物车
    OrderManager order_manager;                  // 订单管理器

private:
    /* 账号相关操作 */
    void
    save_account_map() const;                   // 保存账号映射表
    void load_account_map();                    // 加载账号映射表
    void help() const;                          // 帮助信息
    void exit();                                // 退出系统
    void login(bool is_admin = false);          // 登录
    void logout();                              // 登出
    void sign_up();                             // 注册
    void change_password();                     // 修改密码
    void change_account(bool is_admin = false); // 更换账号
    /* 商品相关操作 */
    void goods_view() const; // 浏览商品
    void goods_search();     // 搜索商品
    void goods_add();        // 添加商品，需要管理员权限
    void goods_remove();     // 移除商品，需要管理员权限
    void goods_update();     // 修改商品，需要管理员权限
    /* 购物车相关操作 */
    void shopping_list_add();        // 添加商品到购物车
    void shopping_list_sub();        // 从购物车减少商品数量
    void shopping_list_set();        // 设置购物车中某种商品的数量
    void shopping_list_remove();     // 从购物车移除商品
    void shopping_list_clear();      // 清空购物车
    void shopping_list_view() const; // 查看购物车
    /* 订单相关操作 */
    void order_place(bool flag = false, const string &ins = ""); // 下订单，默认从购物车
    void order_cancel();                                         // 取消订单
    void order_change();                                         // 修改订单
    void order_check() const;                                    // 查看订单
    void order_find();                                           // 查找订单
    void order_remove();                                         // 删除订单

public:
    System(Config &cfg);
    ~System();
    void handle_input(const string &input);           // 处理用户输入
    void run(const string &welcome_msg = "Welcome!"); // 运行系统
    void stop() { running = false; }                  // 停止系统
};

#endif // SYSTEM_H