#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

struct item
{
    int w, v;
    double vw;
    bool operator>(const item& other) const
    {
        return vw > other.vw;
    }
};

int main()
{
    int n, W;
    cin >> n >> W;
    vector<item> items(n + 1);
    for (int i = 1;i <= n;i++)
        cin >> items[i].v;
    for (int i = 1;i <= n;i++)
        cin >> items[i].w;
    for (int i = 1;i <= n;i++)
        items[i].vw = static_cast<double>(items[i].v) / static_cast<double>(items[i].w);
    sort(items.begin() + 1, items.end(), greater<item>());

    double ans = 0;
    int w = 0;
    for (int i = 1;i <= n;i++)
    {
        if (items[i].w < W - w)
        {
            w += items[i].w;
            ans += items[i].v;
        }
        else
        {
            ans += items[i].vw * (W - w);
            break;
        }
    }
    cout << fixed << setprecision(2) << ans;
    // printf("%.2lf", ans);
    return 0;
}