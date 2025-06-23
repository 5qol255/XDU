#include "functions.h"
#include "system.h"

#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>

using std::cerr;
using std::cin;
using std::equal;
using std::exception;
using std::getline;
using std::max;
using std::min;
using std::mktime;
using std::runtime_error;
using std::string;
using std::stringstream;
using std::vector;

const char endl = '\n';

string strip(const string &str)
{
    auto start = str.find_first_not_of(" \t\n\r\f\v"); // 找到第一个非空白位置
    if (start == string::npos)
        return "";                                  // 全空白字符串返回空串
    auto end = str.find_last_not_of(" \t\n\r\f\v"); // 找到最后一个非空白位置
    return str.substr(start, end - start + 1);      // 截取有效部分
}

float jaro_winkler_similarity(const string &s1, const string &s2)
{
    int len1 = s1.length();
    int len2 = s2.length();

    // 处理空字符串情况
    if (len1 == 0 || len2 == 0)
        return 0.0f;
    // 完全相同的情况
    if (s1 == s2)
        return 1.0f;

    // 计算匹配窗口距离
    int match_distance = (max(len1, len2) / 2) - 1;

    // 初始化匹配标记数组
    vector<bool> s1_matches(len1, false);
    vector<bool> s2_matches(len2, false);

    int matches = 0;

    // 遍历s1的每个字符寻找匹配
    for (int i = 0; i < len1; ++i)
    {
        int start = max(0, i - match_distance);
        int end = min(len2 - 1, i + match_distance);
        for (int j = start; j <= end; ++j)
            if (!s2_matches[j] && s1[i] == s2[j])
            {
                s1_matches[i] = true;
                s2_matches[j] = true;
                matches++;
                break;
            }
    }

    // 无匹配则返回0
    if (matches == 0)
        return 0.0f;

    // 收集匹配的字符
    vector<char> s1_chars, s2_chars;
    for (int i = 0; i < len1; ++i)
        if (s1_matches[i])
            s1_chars.push_back(s1[i]);
    for (int j = 0; j < len2; ++j)
        if (s2_matches[j])
            s2_chars.push_back(s2[j]);

    // 计算换位数目
    float transpositions = 0.0f;
    for (int i = 0; i < s1_chars.size(); ++i)
        if (s1_chars[i] != s2_chars[i])
            transpositions += 1.0f;
    transpositions /= 2.0f;

    // 计算Jaro相似度
    float m = static_cast<float>(matches);
    float jaro = (m / len1 + m / len2 + (m - transpositions) / m) / 3.0f;

    // 计算前缀匹配长度（最多4个字符）
    int prefix_len = 0;
    int max_prefix = min(4, min(len1, len2));
    for (; prefix_len < max_prefix; ++prefix_len)
        if (s1[prefix_len] != s2[prefix_len])
            break;

    // 应用Winkler调整
    float jaro_winkler = jaro + prefix_len * 0.1 * (1.0 - jaro);
    // 确保结果不超过1
    return min(jaro_winkler, 1.0f);
}

float jaro_similarity(const string &s1, const string &s2)
{
    int len1 = s1.length();
    int len2 = s2.length();

    // 处理空字符串情况
    if (len1 == 0 || len2 == 0)
        return 0.0f;
    // 完全相同的情况
    if (s1 == s2)
        return 1.0f;

    // 计算匹配窗口距离
    int match_distance = (max(len1, len2) / 2) - 1;

    // 初始化匹配标记数组
    vector<bool> s1_matches(len1, false);
    vector<bool> s2_matches(len2, false);

    int matches = 0;

    // 遍历s1的每个字符寻找匹配
    for (int i = 0; i < len1; ++i)
    {
        int start = max(0, i - match_distance);
        int end = min(len2 - 1, i + match_distance);
        for (int j = start; j <= end; ++j)
            if (!s2_matches[j] && s1[i] == s2[j])
            {
                s1_matches[i] = true;
                s2_matches[j] = true;
                matches++;
                break;
            }
    }

    // 无匹配则返回0
    if (matches == 0)
        return 0.0f;

    // 收集匹配的字符
    vector<char> s1_chars, s2_chars;
    for (int i = 0; i < len1; ++i)
        if (s1_matches[i])
            s1_chars.push_back(s1[i]);
    for (int j = 0; j < len2; ++j)
        if (s2_matches[j])
            s2_chars.push_back(s2[j]);

    // 计算换位数目
    float transpositions = 0.0f;
    for (int i = 0; i < s1_chars.size(); ++i)
        if (s1_chars[i] != s2_chars[i])
            transpositions += 1.0f;
    transpositions /= 2.0f;

    // 计算Jaro相似度
    float m = static_cast<float>(matches);
    float jaro = (m / len1 + m / len2 + (m - transpositions) / m) / 3.0f;

    return jaro;
}

bool start_with(const string &str, const string &prefix)
{
    // 先检查长度防止越界访问
    if (prefix.size() > str.size())
        return false;
    // 使用标准算法比较字符序列
    return equal(prefix.begin(), prefix.end(), str.begin());
}

const string &strtime(time_t t)
{
    static string format;
    format.clear();
    std::tm *temp = std::localtime(&t);
    char buffer[32];
    std::strftime(buffer, 32, "%Y-%m-%d %H:%M:%S", temp);
    format = buffer;
    return format;
}

template <> // 字符串特化
bool get_input<string>(System &sys, string &input)
{
    try // 尝试读取整行输入
    {
        if (!getline(cin, input))
        {
            input.clear();
            if (cin.eof())
                throw runtime_error("EOF detected. Exiting...");
            else
                throw runtime_error("Failed to read input.");
        }
        else
        {
            input = strip(input); // 去除前后空白
            return true;
        }
    }
    catch (const runtime_error &err)
    {
        cerr << err.what() << endl
             << "The system has stopped unexpectedly." << endl;
        sys.stop();
        return false;
    }
    catch (const exception &err)
    {
        cerr << "Unknown error: " << err.what() << endl
             << "The system has stopped unexpectedly." << endl;
        sys.stop();
        return false;
    }
}

template <> // uint32_t特化
bool get_input<uint32_t>(System &sys, uint32_t &input)
{
    string line;
    if (!get_input(sys, line))
        return false;
    if (line.empty())
        return false;
    long long tmp;
    if (sscanf(line.c_str(), "%lld", &tmp) == 1 && tmp >= 0)
    {
        input = tmp;
        return true;
    }
    return false;
}

template <>
bool get_input<time_t>(System &sys, time_t &input)
{
    string line;
    if (!get_input(sys, line))
        return false;
    if (line.empty())
        return false;
    tm tmp = {};
    if (sscanf(line.c_str(), "%d-%d-%d %d:%d:%d",
               &tmp.tm_year, &tmp.tm_mon, &tmp.tm_mday,
               &tmp.tm_hour, &tmp.tm_min, &tmp.tm_sec) != 6)
        return false;
    else
    {
        tmp.tm_year -= 1900;
        tmp.tm_mon--;
        input = mktime(&tmp);
        return true;
    }
}