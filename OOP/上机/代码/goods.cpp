#include "goods.h"
#include "functions.h"
#include "config.h"
#include "promotion.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

using std::cout;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::stof;  // 字符串转浮点数
using std::stoul; // 字符串转无符号整数
using std::string;
using std::to_string; // 数字转字符串
using std::vector;

const char endl = '\n';

/* 商品ID分配函数 */
uint32_t auto_id(Config &cfg)
{
    uint32_t id = stoul(cfg.get_goods_id());
    cfg.set_goods_id(to_string(id + 1));
    return id;
}

/* 新建商品用法 */
Goods::Goods(Config &cfg,
             const string &name,
             float price,
             uint32_t stock,
             const string &description,
             const promotion_tag &promo_tag)
    : id(auto_id(cfg)), // const成员变量初始化在参数列表中进行
      name(name),       // 其他变量顺便也写在参数列表里
      price(price),
      stock(stock),
      description(description),
      promo_tag()
{
}

/* 读取已有商品用法 */
Goods::Goods(const string &name,
             float price,
             uint32_t stock,
             uint32_t id,
             const string &description,
             const promotion_tag &promo_tag)
    : name(name), // 其他变量顺便也写在参数列表里
      price(price),
      stock(stock),
      id(id), // const成员变量初始化在参数列表中进行
      description(description),
      promo_tag(promo_tag)
{
}

/* GoodsManager无参数构造函数，委托GoodsManager(const string &path)构造函数 */
GoodsManager::GoodsManager() : GoodsManager::GoodsManager("./data/goods.csv") {}

/* GoodsManager有参构造 */
GoodsManager::GoodsManager(const string &path)
{
    change = false; // 初始化未修改标志
    filepath = path;
    ifstream file(path, ifstream::in);
    if (!file.is_open())
    {
        goods_set.clear();
        // 不存在文件，创建新文件
        ofstream file(path, ofstream::out);
        file.close();
        return;
    }
    string line;
    vector<string> tmp;  // 存放一行里面的信息
    getline(file, line); // 跳过第一行
    int start, end;
    while (getline(file, line)) // 读取每一行
    {
        line = strip(line); // 去除换行符
        start = 0;
        end = line.find(',', start);
        for (int i = 0; i < 13; ++i)
        {
            tmp.push_back(line.substr(start, end - start));
            start = end + 1;
            end = line.find(',', start);
        }
        promotion_tag tmp_tag = {
            stoul(tmp[5]),
            stoul(tmp[6]),
            stoul(tmp[7]),
            stoul(tmp[8]),
            stoul(tmp[9]),
            stoul(tmp[10]),
            strtoll(tmp[11].c_str(), nullptr, 10),
            strtoll(tmp[12].c_str(), nullptr, 10),
        };
        goods_set.insert(Goods(tmp[0], stof(tmp[1]), stoul(tmp[2]), stoul(tmp[3]), tmp[4], tmp_tag)); // 插入商品
        tmp.clear();
    }
}

GoodsManager::~GoodsManager()
{
    if (change)
        save(filepath);
}

const string &Goods::get_info() const
{
    static string goods_info;
    goods_info.clear();
    goods_info = "name: " + name + endl +
                 "price: " + to_string(price) + endl +
                 "stock: " + to_string(stock) + endl +
                 "id: " + to_string(id) + endl +
                 "description: " + description + endl +
                 "promotion: " + endl;
    if (promo_tag.is_discount)
        goods_info += "    discount: %" + to_string(promo_tag.discount) + " off" + endl +
                      "    end time: " + strtime(promo_tag.discount_end_time) + endl;
    if (promo_tag.is_reduction)
        goods_info += "    reduction: every " + to_string(promo_tag.spend) +
                      " minus " + to_string(promo_tag.reduction) + endl +
                      "    end time: " + strtime(promo_tag.reduction_end_time) + endl;
    if (!promo_tag.is_discount && !promo_tag.is_reduction)
        goods_info += "    none\n";
    if (promo_tag.is_discount && promo_tag.is_reduction)
    {
        if (promo_tag.both)
            goods_info += "    discounts are stackable";
        else
            goods_info += "    discounts are not stackable";
    }
    return goods_info;
}

/* 添加商品 */
void GoodsManager::add_goods(const Goods &goods)
{
    goods_set.insert(goods);
    change = true; // 修改标志置为true
}

/* 打印商品信息 */
void GoodsManager::list_goods() const
{
    cout << "----------------------------------------------------------------" << endl;
    for (auto const &goods : goods_set)
    {
        cout << "name:        " << goods.get_name() << endl
             << "price:       " << goods.get_price() << endl
             << "stock:       " << goods.get_stock() << endl
             << "id:          " << goods.get_id() << endl
             << "description: " << goods.get_description() << endl
             << "promotion: " << endl;
        if (goods.get_promotion().is_discount)
            cout << "    discount: %" << to_string(goods.get_promotion().discount) << " off\n"
                 << "    end time: " + strtime(goods.get_promotion().discount_end_time) + endl;
        if (goods.get_promotion().is_reduction)
            cout << "    reduction: every " << to_string(goods.get_promotion().spend)
                 << " minus " << to_string(goods.get_promotion().reduction) << endl
                 << "    end time: " + strtime(goods.get_promotion().reduction_end_time) + endl;
        if (!goods.get_promotion().is_discount && !goods.get_promotion().is_reduction)
            cout << "    none\n";
        if (goods.get_promotion().is_discount && goods.get_promotion().is_reduction)
        {
            if (goods.get_promotion().both)
                cout << "    discounts are stackable\n";
            else
                cout << "    discounts are not stackable\n";
        }
        cout << "----------------------------------------------------------------" << endl;
    }
}

/* 保存商品信息到文件 */
void GoodsManager::save(const string &path) const
{
    ofstream file(path, ofstream::out);
    if (!file.is_open())
    {
        return;
    }
    file << "name,price,stock,id,description,"
         << "is_discount,is_reduction,both,discount,spend,reduction,"
         << "discount_end_time,reduction_end_time" << endl;
    for (auto const &goods : goods_set)
    {
        file << goods.get_name() << ','
             << goods.get_price() << ','
             << goods.get_stock() << ','
             << goods.get_id() << ','
             << goods.get_description() << ','
             << goods.get_promotion() << endl;
    }
    file.close();
}

bool GoodsManager::remove_goods(uint32_t id)
{
    for (auto it = goods_set.begin(); it != goods_set.end(); ++it)
        if (it->get_id() == id) // 这里删除完之后直接返回，不存在迭代器失效问题
        {
            goods_set.erase(it);
            change = true;
            change = true; // 修改标志置为true
            return true;
        }
    return false;
}

bool GoodsManager::update_goods(uint32_t id,
                                const string &name, bool update_name,
                                float price, bool update_price,
                                int stock, bool update_stock,
                                const string &description, bool update_description,
                                const promotion_tag &promo_tag, bool update_promo_tag)
{
    auto it = goods_set.begin();
    for (; it != goods_set.end(); ++it)
        if (it->get_id() == id)
            break;
    if (it == goods_set.cend())
        return false;
    auto name_ = update_name ? name : it->get_name();
    auto price_ = update_price ? price : it->get_price();
    auto stock_ = update_stock ? stock : it->get_stock();
    auto description_ = update_description ? description : it->get_description();
    auto id_ = it->get_id();
    auto promo_tag_ = update_promo_tag ? promo_tag : it->get_promotion();
    goods_set.erase(it);
    goods_set.insert(Goods(name_, price_, stock_, id_, description_, promo_tag_));
    change = true; // 修改标志置为true
    return true;
}

void GoodsManager::search_goods(const string &words) const
{
    bool is_find = false;
    cout << "----------------------------------------------------------------" << endl;
    for (auto const &goods : goods_set)
        if (goods.get_name().find(words) != string::npos ||
            goods.get_description().find(words) != string::npos) // 名称或描述中直接包含搜索词
        {
            is_find = true;
            cout << "name:        " << goods.get_name() << endl
                 << "price:       " << goods.get_price() << endl
                 << "stock:       " << goods.get_stock() << endl
                 << "id:         " << goods.get_id() << endl
                 << "description: " << goods.get_description() << endl
                 << "promotion: " << endl;
            if (goods.get_promotion().is_discount)
                cout << "    discount: %" << to_string(goods.get_promotion().discount) << " off\n"
                     << "    end time: " + strtime(goods.get_promotion().discount_end_time) + endl;
            if (goods.get_promotion().is_reduction)
                cout << "    reduction: every " << to_string(goods.get_promotion().spend)
                     << " minus " << to_string(goods.get_promotion().reduction) << endl
                     << "    end time: " + strtime(goods.get_promotion().reduction_end_time) + endl;
            if (!goods.get_promotion().is_discount && !goods.get_promotion().is_reduction)
                cout << "    none\n";
            if (goods.get_promotion().is_discount && goods.get_promotion().is_reduction)
            {
                if (goods.get_promotion().both)
                    cout << "    discounts are stackable\n";
                else
                    cout << "    discounts are not stackable\n";
            }
            cout << "----------------------------------------------------------------" << endl;
        }
        else // 启用模糊搜索
        {
            is_find = true;
            auto simlarity1 = jaro_similarity(words, goods.get_name());
            auto simlarity2 = jaro_similarity(words, goods.get_description());
            if (simlarity1 > 0.75 || simlarity2 > 0.75)
            {
                cout << "name:       " << goods.get_name() << endl
                     << "price:      " << goods.get_price() << endl
                     << "stock:      " << goods.get_stock() << endl
                     << "id:         " << goods.get_id() << endl
                     << "description:" << goods.get_description() << endl
                     << "promotion: " << endl;
                if (goods.get_promotion().is_discount)
                    cout << "    discount: %" << to_string(goods.get_promotion().discount) << " off\n"
                         << "    end time: " + strtime(goods.get_promotion().discount_end_time) + endl;
                if (goods.get_promotion().is_reduction)
                    cout << "    reduction: every " << to_string(goods.get_promotion().spend)
                         << " minus " << to_string(goods.get_promotion().reduction) << endl
                         << "    end time: " + strtime(goods.get_promotion().reduction_end_time) + endl;
                if (!goods.get_promotion().is_discount && !goods.get_promotion().is_reduction)
                    cout << "    none\n";
                if (goods.get_promotion().is_discount && goods.get_promotion().is_reduction)
                {
                    if (goods.get_promotion().both)
                        cout << "    discounts are stackable\n";
                    else
                        cout << "    discounts are not stackable\n";
                }
                cout << "----------------------------------------------------------------" << endl;
            }
        }
    if (!is_find)
        cout << "No goods found." << endl
             << "----------------------------------------------------------------" << endl;
}

const string &GoodsManager::search_goods(uint32_t id) const
{
    static string empty = "";
    bool is_find = false;
    for (auto const &goods : goods_set)
        if (goods.get_id() == id)
            return goods.get_info();
    return empty;
}

const Goods &GoodsManager::search_goods(uint32_t id, bool) const
{
    static Goods empty("", 0, 0, 0, "", promotion_tag{});
    for (auto const &goods : goods_set)
        if (goods.get_id() == id)
            return goods;
    return empty;
}
