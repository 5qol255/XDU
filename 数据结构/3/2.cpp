#include <bits/stdc++.h>
using namespace std;

int main()
{
    string targetWord;
    string filePath;
    unordered_map<int, int> lineOccurrences;
    int totalCount = 0;

    // 输入要统计的单词
    cout << "请输入要统计的单词：";
    cin >> targetWord;

    // 输入文本文件的路径
    cout << "请输入文本文件的路径：";
    cin >> filePath;

    // 打开文件
    ifstream file(filePath);
    if (!file.is_open())
    {
        cerr << "无法打开文件。" << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;

    // 逐行读取文件
    while (getline(file, line))
    {
        istringstream lineStream(line);
        string word;
        int lineCount = 0;

        // 分割当前行成单词并统计目标单词的出现次数
        while (lineStream >> word)
        {
            if (word == targetWord)
            {
                lineCount++;
                totalCount++;
            }
        }

        // 如果当前行中有目标单词出现，则记录行号和出现次数
        if (lineCount > 0)
        {
            lineOccurrences[lineNumber] = lineCount;
        }

        lineNumber++;
    }

    file.close();

    // 输出统计结果
    cout << "单词 '" << targetWord << "' 在文件中总共出现了 " << totalCount << " 次。" << endl;
    cout << "出现该单词的行号及每行出现次数如下：" << endl;
    for (const auto &pair : lineOccurrences)
    {
        cout << "行号: " << pair.first << ", 出现次数: " << pair.second << endl;
    }

    return 0;
}