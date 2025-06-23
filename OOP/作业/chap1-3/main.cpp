/*
一. 简答题（共1题）
1. (简答题)
假设预先有编辑好的文本文件，其内容为若干英文单词。约定每个单词都由至少一个可打印字符构成，单词之间用空白字符分隔（空格、制表符'\t'、换行符等都是空白符号）。
请编写一个 C++程序，它满足以下要求：
（1）[10分]具体的文件路径（含文件名）不能写死在源代码中，必须通过命令行参数形式传递给 main 函数，或者从标准输入设备(cin)读取文件路径。
（2）[40分]从文件中读取其中所有单词并放到内存中。要求文件操作必须使用 例程库的 ifstream 或 fstream 类型，每一个单词的文本必须使用例程库的 string 类型存储。
（3）[30分] 请使用 C++标准库中恰当的容器存储所有单词(和相关信息)，如 map, set， vector,  list等容器存储所有单词。需要你自学教材 3.7~3.8 给出的相关例子。
（4）[10分]从文件中读到的所有单词，按照单词的字典顺序输出。对于重复出现的单词，可仅输出一遍。
（5）【选做】（10分）按单词进行数量统计，若N个输入单词有相同文本则将它们视作一个单词且其出现次数为N。并输出单词在输入文件中的总数量、每个不同单词的出现次数。
【提示：如果你完成了第 5 条要求，那么对于第 4 条要求的排序输出可合并到第 5 条的输出中体现即可】
---
输入样例文件内容：
z1   z0   f
b  ,3
a    a
输出样例（对于上面的输入文件）：
对第4条要求，按字典顺序输出所有单词（每个重复单词仅输出一遍）：
 ,3  a  b  f  z0  z1
单词总数量：7
对第5条要求，各单词出现次数（按单词的字典顺序排列）：
,3  1
a  2
b  1
f  1
z0 1
z1 1
 */
// 完成日期：2025/3/7
// 编译器：g++
// 测试环境：Windows11
// 编码：utf8
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream fin;
    ofstream fout;
    vector<string> dict;

    // 要求1
    if (argc <= 1)
    {
        cerr << "Please enter filepath.\n";
        return 1;
    }
    else
        fin.open(argv[1], ios::in);
    if (!fin.good())
    {
        cerr << "Unable to open file!\n";
        return 1; // 文件打开失败
    }

    // 要求2,3
    for (string word; fin >> word;)
        dict.push_back(word);
    fin.close();

    // 要求4,5
    fout.open("output.txt", ios::out);

    if (!dict.empty())
    {
        if (!fout.good())
        {
            cerr << "Write file exception, only output to console.\n";
            sort(dict.begin(), dict.end()); // 默认升序
            string tmp = dict[0];
            int cnt = 0;
            for (const auto &it : dict)
                if (it != tmp)
                {
                    cout << tmp << ' ' << cnt << '\n';
                    tmp = it;
                    cnt = 1;
                }
                else
                    ++cnt;
            cout << tmp << ' ' << cnt << endl;
        }
        else
        {
            sort(dict.begin(), dict.end()); // 默认升序
            string tmp = dict[0];
            int cnt = 0;
            for (const auto &it : dict)
                if (it != tmp)
                {
                    cout << tmp << ' ' << cnt << '\n';
                    fout << tmp << ' ' << cnt << '\n';
                    tmp = it;
                    cnt = 1;
                }
                else
                    ++cnt;
            cout << tmp << ' ' << cnt << endl;
            fout << tmp << ' ' << cnt << endl;
        }
    }
    return 0;
}