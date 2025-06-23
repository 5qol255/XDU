#include "config.h"
#include "functions.h"

#include <fstream>
#include <string>

using std::ifstream;
using std::ofstream;
using std::string;
using std::to_string;

const char endl = '\n';

Config::Config() : Config("./config.ini") {}

Config::Config(const string &filepath)
{
    change = false;
    this->filepath = filepath;
    ifstream file(filepath, ifstream::in);
    if (!file.is_open())
    {
        // Handle error
        config["admin_username"] = "";
        config["admin_pwd"] = "";
        config["accounts_path"] = "";
        config["goods_path"] = "";
        config["goods_id"] = to_string(0);
        config["shopping_list_path"] = "./data/shopping_list.sl";
        config["order_list_path"] = "./data/order_list.ol";
        config["order_id"] = to_string(0);
        change = true;
        // 不存在则创建文件
        ofstream file(filepath, ofstream::out);
        file.close();
        return;
    }
    string line;
    int epos;
    // admin
    getline(file, line); // admin段，跳过
    getline(file, line); // 管理员username
    line = strip(line);
    epos = line.find('=');
    config["admin_username"] = line.substr(epos + 1);
    getline(file, line); // 管理员password
    line = strip(line);
    epos = line.find('=');
    config["admin_pwd"] = line.substr(epos + 1);
    // accounts_path
    getline(file, line); // accounts_path段，跳过
    getline(file, line); // 数据库路径
    line = strip(line);
    epos = line.find('=');
    config["accounts_path"] = line.substr(epos + 1);
    // goods_path
    getline(file, line); // goods_path段，跳过
    getline(file, line); // 商品信息文件路径
    line = strip(line);
    epos = line.find('=');
    config["goods_path"] = line.substr(epos + 1);
    // goods_id
    getline(file, line); // goods_id段，跳过
    getline(file, line); // 商品id
    line = strip(line);
    epos = line.find('=');
    config["goods_id"] = line.substr(epos + 1);
    // shopping_list_path
    getline(file, line); // shopping_list_path段，跳过
    getline(file, line); // 购物清单文件路径
    line = strip(line);
    epos = line.find('=');
    config["shopping_list_path"] = line.substr(epos + 1);
    // order_list_path
    getline(file, line); // order_list_path段，跳过
    getline(file, line); // 订单清单文件路径
    line = strip(line);
    epos = line.find('=');
    config["order_list_path"] = line.substr(epos + 1);
    // order_id
    getline(file, line); // order_id段，跳过
    getline(file, line); // 订单id
    line = strip(line);
    epos = line.find('=');
    config["order_id"] = line.substr(epos + 1);
    file.close();
}

Config::~Config()
{
    if (change)
        save();
}

const string &Config::get(const string &key) const
{
    auto const &it = config.find(key);
    static const string empty_str = "";
    if (it == config.cend())
        return empty_str;
    return it->second;
}

void Config::set(const string &key, const string &value)
{
    change = true;
    config[key] = value;
}

void Config::save() const
{
    ofstream file(filepath, ofstream::out);
    if (!file.is_open())
    {
        // Handle error
        return;
    }
    file << "[admin]\n"
         << "admin_username=" << get_admin_username() << endl
         << "admin_pwd=" << get_admin_password() << endl
         << "[accounts_path]" << endl
         << "accounts_path=" << get_accounts_path() << endl
         << "[goods_path]" << endl
         << "goods_path=" << get_goods_path() << endl
         << "[goods_id]" << endl
         << "goods_id=" << get_goods_id() << endl
         << "[shopping_list_path]" << endl
         << "shopping_list_path=" << get_shopping_list_path() << endl
         << "[order_list_path]" << endl
         << "order_list_path=" << get_order_list_path() << endl
         << "[order_id]" << endl
         << "order_id=" << get_order_id() << endl;
    file.close();
}