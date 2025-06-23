#ifndef GOODS_H
#define GOODS_H
#pragma once

#include "config.h"
#include "promotion.h"

#include <string>
#include <set>
#include <fstream>
#include <cstdint>

using std::ostream;
using std::set;
using std::string;

class Goods
{
private:
    string name;
    float price;
    uint32_t stock;          // 库存
    const uint32_t id;       // 区分不同商品的唯一标识，不可修改
    string description;      // 商品描述
    promotion_tag promo_tag; // 促销标签

public:
    Goods(Config &cfg,
          const string &name,
          float price,
          uint32_t stock = 0,
          const string &description = "",
          const promotion_tag &promo_tag = promotion_tag());
    Goods(const string &name,
          float price,
          uint32_t stock,
          uint32_t id,
          const string &description,
          const promotion_tag &promo_tag);
    const string &get_name() const { return name; }
    float get_price() const { return price; }
    uint32_t get_stock() const { return stock; }
    const uint32_t get_id() const { return id; }
    const promotion_tag &get_promotion() const { return promo_tag; }
    const string &get_description() const { return description; }
    const string &get_info() const;
    void set_name(const string &new_name) { name = new_name; }
    void set_price(float new_price) { price = new_price; }
    void set_stock(uint32_t new_stock) { stock = new_stock; }
    void set_description(const string &new_description) { description = new_description; }
    // 重载<，为了使用set容器
    bool operator<(const Goods &other) const { return id < other.id; }
};

class GoodsManager
{
private:
    set<Goods> goods_set; // 商品集合
    string filepath;
    bool change;

public:
    GoodsManager();
    GoodsManager(const string &path);
    ~GoodsManager();
    void list_goods() const;
    void add_goods(const Goods &good);
    bool remove_goods(uint32_t id);
    bool update_goods(uint32_t id,
                      const string &name, bool update_name,
                      float price, bool update_price,
                      int stock, bool update_stock,
                      const string &description, bool update_description,
                      const promotion_tag &promo_tag, bool update_promo_tag);
    void search_goods(const string &words) const;
    const string &search_goods(uint32_t id) const;
    const Goods &search_goods(uint32_t id, bool) const;
    void save(const string &path) const;
};

#endif // GOODS_H