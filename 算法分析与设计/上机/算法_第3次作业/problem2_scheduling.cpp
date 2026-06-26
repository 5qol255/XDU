#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 作业结构体：name 为作业名，time 为运行时间。
struct Job {
    string name;
    int time;
};

int main() {
    vector<Job> jobs = {{"j1", 15}, {"j2", 8}, {"j3", 3}, {"j4", 10}};

    // 最短处理时间优先（SPT）可以使平均完成时间最小。
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.time < b.time;
    });

    int currentTime = 0;
    double completionTimeSum = 0;

    cout << "Schedule order:";
    for (const auto& job : jobs) {
        cout << ' ' << job.name;
    }
    cout << "\n\n";

    for (const auto& job : jobs) {
        currentTime += job.time;
        completionTimeSum += currentTime;
        cout << job.name << " running time = " << job.time
             << ", completion time = " << currentTime << '\n';
    }

    cout << fixed << setprecision(2);
    cout << "Average completion time: " << completionTimeSum / jobs.size() << '\n';

    return 0;
}
