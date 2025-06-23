#include "user.h"

#include <string>

using std::string;

User::User() : User(false, false) {}

User::User(bool is_admin_user, bool is_guest_user) : User(is_admin_user, is_guest_user, "", "") {}

User::User(bool is_admin_user, bool is_guest_user, const string &un, const string &pd)
{
    is_admin = is_admin_user;
    is_guest = is_admin_user ? false : is_guest_user;
    username = un;
    pwd = pd;
}