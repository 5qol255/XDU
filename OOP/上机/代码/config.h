#ifndef CONFIG_H
#define CONFIG_H
#pragma once

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

string strip(const string &str);

class Config
{
private:
    string filepath;
    unordered_map<string, string> config;
    const string &get(const string &key) const;
    void set(const string &key, const string &value);
    void save() const;
    bool change;

public:
    Config();
    Config(const string &filepath);
    ~Config();
    const string &get_admin_username() const { return get("admin_username"); }
    const string &get_admin_password() const { return get("admin_pwd"); }
    const string &get_accounts_path() const { return get("accounts_path"); }
    const string &get_goods_path() const { return get("goods_path"); }
    const string &get_goods_id() const { return get("goods_id"); }
    const string &get_shopping_list_path() const { return get("shopping_list_path"); }
    const string &get_order_list_path() const { return get("order_list_path"); }
    const string &get_order_id() const { return get("order_id"); }
    void set_admin_username(const string &value) { set("admin_username", value); }
    void set_admin_password(const string &value) { set("admin_pwd", value); }
    void set_accounts_path(const string &value) { set("accounts_path", value); }
    void set_goods_path(const string &value) { set("goods_path", value); }
    void set_goods_id(const string &value) { set("goods_id", value); }
    void set_shopping_list_path(const string &value) { set("shopping_list_path", value); }
    void set_order_list_path(const string &value) { set("order_list_path", value); }
    void set_order_id(const string &value) { set("order_id", value); }
};

#endif // CONFIG_H