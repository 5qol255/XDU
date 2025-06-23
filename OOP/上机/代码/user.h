#ifndef USER_H
#define USER_H
#pragma once

#include "config.h"

#include <string>
#include <iostream>

using std::cout;
using std::string;

class User
{
private:
    bool is_admin;   // 是否为管理员
    bool is_guest;   // 是否为访客
    string username; // 用户名
    string pwd;      // 密码

public:
    User();
    User(bool is_admin_user, bool is_guest_user);
    User(bool is_admin_user, bool is_guest_user, const string &un, const string &pd);
    void set_username(const string &new_username) { username = new_username; } // 修改用户名
    void set_pwd(const string &new_pwd) { pwd = new_pwd; }                     // 修改密码
    const string &get_username() const { return username; }                    // 获取用户名
    const string &get_pwd() const { return pwd; }                              // 获取密码
};

#endif // USER_H