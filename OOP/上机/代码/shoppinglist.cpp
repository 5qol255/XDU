#include "shoppinglist.h"
#include "goods.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;

const char endl = '\n';

ShoppingList::ShoppingList(const string &filename, const GoodsManager &goods_manager)
    : filename(filename), changed(false), goods_manager(goods_manager)
{
    load();
}

void ShoppingList::load()
{
    shopping_list.clear();
    ifstream in(filename, ifstream::in);
    if (!in.is_open())
    {
        ofstream out(filename, ofstream::out); // 不存在则新建文件
        out.close();
        return;
    }
    int id, amount;
    while (in >> id >> amount)
        if (goods_manager.search_goods(id) != "") // 商品存在
            shopping_list[id] = amount;
        else
            changed = true; // 商品不存在，标记为需要保存
    in.close();
}

ShoppingList::~ShoppingList()
{
    if (changed)
        save();
}

void ShoppingList::save() const
{
    ofstream out(filename, ofstream::out);
    if (!out.is_open())
    {
        cout << "Failed to save shopping list to file " << filename << endl;
        return;
    }
    for (const auto &item : shopping_list)
        out << item.first << ' ' << item.second << endl;
    out.close();
}

void ShoppingList::set_filename(const string &new_filename)
{
    if (changed)
        save();
    filename = new_filename;
    changed = false;
    load();
    cout << "Filename has been changed to " << filename << endl;
}

void ShoppingList::add(uint32_t id, uint32_t amount)
{
    if (goods_manager.search_goods(id) == "") // 商品不存在
    {
        cout << "Item " << id << " not found in goods manager." << endl;
        return;
    }
    if (shopping_list.find(id) == shopping_list.end())
        shopping_list[id] = amount;
    else
        shopping_list[id] += amount;
    changed = true;
    cout << "success" << endl;
}

void ShoppingList::sub(uint32_t id, uint32_t amount)
{
    if (shopping_list.find(id) == shopping_list.end())
    {
        cout << "Item " << id << " not found in shopping list." << endl;
        return; // 购物车里没有直接返回
    }
    if (shopping_list[id] <= amount)
        shopping_list.erase(id); // 购物车里的数量小于等于要减的数量，直接删除
    else
        shopping_list[id] -= amount;
    changed = true;
    cout << "success" << endl;
}

void ShoppingList::set(uint32_t id, uint32_t amount)
{
    if (shopping_list.find(id) == shopping_list.end())
    {
        cout << "Item " << id << " not found in shopping list." << endl;
        return; // 购物车里没有直接返回
    }
    if (amount == 0)
        shopping_list.erase(id); // 要设置的数量为0，直接删除
    else
        shopping_list[id] = amount;
    cout << "success" << endl;
    changed = true;
}

void ShoppingList::remove(uint32_t id)
{
    if (shopping_list.erase(id))
    {
        changed = true;
        cout << "Item " << id << " has been removed from shopping list." << endl;
    }
    else
        cout << "Item " << id << " not found in shopping list." << endl;
}

void ShoppingList::clear()
{
    shopping_list.clear();
    changed = true;
    cout << "Shoppinglist has been cleared successfully." << endl;
}

void ShoppingList::list() const
{
    if (shopping_list.empty())
        cout << "Shopping list is empty." << endl;
    else
    {
        cout << "Shopping list:" << endl
             << "----------------------------------------------------------------" << endl;
        for (const auto &item : shopping_list) // 遍历购物车
            cout << goods_manager.search_goods(item.first) << endl
                 << "amount : " << item.second << endl
                 << "----------------------------------------------------------------" << endl;
    }
}