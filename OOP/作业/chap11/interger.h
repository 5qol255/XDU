#ifndef INTERGER_H
#define INTERGER_H

#pragma once

#include <string>
#include <iostream>
using namespace std;

class Integer
{
    int value;

public:
    // 构造函数
    Integer(int v = 0) : value(v) {}
    Integer(const string &s) : value(stoi(s)) {}
    Integer(const Integer &i) : value(i.value) {}
    Integer &operator=(const Integer &other)
    {
        if (*this != other)
            value = other.value;
        return *this;
    }
    Integer &operator=(int other)
    {
        value = other;
        return *this;
    }
    // 类型转换
    operator int() const { return value; }
    operator char() const { return (char)value; }
    operator bool() const { return value != 0; }
    operator float() const { return (float)value; }
    operator double() const { return (double)value; }
    operator string() const { return to_string(value); }
    static int parse(const string &str) { return stoi(str); }
    // 逻辑运算
    int cmp(const Integer &other) const
    {
        if (value < other.value)
            return -1;
        else if (value > other.value)
            return 1;
        else
            return 0;
    }
    friend bool operator==(const Integer &self, const Integer &other) { return self.cmp(other) == 0; }
    friend bool operator!=(const Integer &self, const Integer &other) { return self.cmp(other) != 0; }
    friend bool operator<(const Integer &self, const Integer &other) { return self.cmp(other) == -1; }
    friend bool operator<=(const Integer &self, const Integer &other) { return self.cmp(other) != 1; }
    friend bool operator>(const Integer &self, const Integer &other) { return self.cmp(other) == 1; }
    friend bool operator>=(const Integer &self, const Integer &other) { return self.cmp(other) != -1; }
    // 一元运算符
    Integer operator+() const { return *this; }
    Integer operator-() const { return Integer(-value); }
    Integer &operator++()
    {
        ++value;
        return *this;
    }
    Integer operator++(int)
    {
        Integer temp = *this;
        ++value;
        return temp;
    }
    Integer &operator--()
    {
        --value;
        return *this;
    }
    Integer operator--(int)
    {
        Integer temp = *this;
        --value;
        return temp;
    }
    Integer &operator+=(const Integer &other)
    {
        value += other.value;
        return *this;
    }
    Integer &operator-=(const Integer &other)
    {
        value -= other.value;
        return *this;
    }
    Integer &operator*=(const Integer &other)
    {
        value *= other.value;
        return *this;
    }
    Integer &operator/=(const Integer &other)
    {
        if (other.value == 0)
            throw runtime_error("Division by zero");
        value /= other.value;
        return *this;
    }
    Integer &operator%=(const Integer &other)
    {
        if (other.value == 0)
            throw runtime_error("Modulo by zero");
        value %= other.value;
        return *this;
    }
    // 二元运算符
    friend Integer operator+(const Integer &self, const Integer &other)
    {
        return Integer(self.value + other.value);
    }
    friend Integer operator-(const Integer &self, const Integer &other)
    {
        return Integer(self.value - other.value);
    }
    friend Integer operator*(const Integer &self, const Integer &other)
    {
        return Integer(self.value * other.value);
    }
    friend Integer operator/(const Integer &self, const Integer &other)
    {
        if (other.value == 0)
            throw runtime_error("Division by zero");
        return Integer(self.value / other.value);
    }
    friend Integer operator%(const Integer &self, const Integer &other)
    {
        if (other.value == 0)
            throw runtime_error("Modulo by zero");
        return Integer(self.value % other.value);
    }
    // 输入输出
    friend ostream &operator<<(ostream &os, const Integer &i) { return os << i.value; }
    friend istream &operator>>(istream &is, Integer &i) { return is >> i.value; }
};

#endif // INTERGER_H