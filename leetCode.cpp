#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximumSwap(int num)
    {
        vector<int> cnt;
        int mx = 0;
        while (num)
        {
            int tmp = num % 10;
            mx = max(mx, tmp);
            cnt.push_back(tmp);
            num = num / 10;
        }
        int n = cnt.size();
        auto mxit = find(cnt.rbegin(), cnt.rend(), mx);
        for (auto it = cnt.rbegin(); it != cnt.rend(); it++)
        {
            if (*it < *mxit)
            {
                swap(*it, *mxit);
                break;
            }
        }
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            int tmp = cnt[j] * (pow(10, j));
            ans += tmp;
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    int num = 2736;

    //  开始
    auto start = chrono::steady_clock::now();
    //
    // cout << solution.maximumSwap(num) << endl;
    // 结束
    auto end = chrono::steady_clock::now();
    // 时间差异
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}