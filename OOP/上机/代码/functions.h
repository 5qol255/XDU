#include "system.h"

#include <string>
#include <ctime>
#include <sstream>

using std::string;
using std::stringstream;

string strip(const string &str);
float jaro_winkler_similarity(const string &s1, const string &s2);
float jaro_similarity(const string &s1, const string &s2);
bool start_with(const string &str, const string &prefix);
const string &strtime(time_t t);

template <typename T> // 读取用户输入模板
bool get_input(System &sys, T &input)
{
    string line;
    if (!get_input(sys, line))
        return false;
    if (line.empty())
        return false;
    stringstream ss(line);
    T tmp;
    if (ss >> tmp)
        return true;
    return false;
}
template <> // 字符串特化
bool get_input<string>(System &sys, string &input);
template <> // uint32_t特化
bool get_input<uint32_t>(System &sys, uint32_t &input);
template <> // time_t特化
bool get_input<time_t>(System &sys, time_t &input);