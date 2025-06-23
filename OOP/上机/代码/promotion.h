#ifndef DISCOUNT_H
#define DISCOUNT_H

#pragma once

#include <cstdint>
#include <iostream>
#include <ctime>
using std::ostream;

struct promotion_tag
{
    bool is_discount = false;      // 是否参与折扣
    bool is_reduction = false;     // 是否参与满减
    bool both = false;             // 是否同时参与折扣和满减
    uint32_t discount = 100;       // 折扣力度
    uint32_t spend = 0;            // 满
    uint32_t reduction = 0;        // 减
    time_t discount_end_time = 0;  // 折扣结束时间
    time_t reduction_end_time = 0; // 满减结束时间
    friend ostream &operator<<(ostream &os, const promotion_tag &p)
    {
        os << p.is_discount << ','
           << p.is_reduction << ','
           << p.both << ','
           << p.discount << ','
           << p.spend << ','
           << p.reduction << ','
           << p.discount_end_time << ','
           << p.reduction_end_time;
        return os;
    }
};

#endif // DISCOUNT_H