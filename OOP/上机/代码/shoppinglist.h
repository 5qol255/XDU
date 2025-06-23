#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H
#pragma once

#include "goods.h"

#include <string>
#include <map>
#include <cstdint>

using std::map;
using std::string;

class ShoppingList
{
private:
    map<uint32_t, uint32_t> shopping_list; //<id, amount>
    string filename;
    const GoodsManager &goods_manager;
    bool changed;

public:
    ShoppingList(const string &filename, const GoodsManager &goods_manager);
    ~ShoppingList();
    const map<uint32_t, uint32_t> &get_shopping_list() const { return shopping_list; }
    void set_filename(const string &new_filename); // 设置存档文件名
    void add(uint32_t id, uint32_t amount);
    void sub(uint32_t id, uint32_t amount);
    void set(uint32_t id, uint32_t amount);
    void remove(uint32_t id);
    void clear();
    bool empty() const { return shopping_list.empty(); }
    void load();       // 从文件中读取数据
    void save() const; // 将数据保存到文件中
    void list() const;
};

#endif // SHOPPINGLIST_H