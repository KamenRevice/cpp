/*
 * @Description: https://kamacoder.com/problempage.php?pid=1007
 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2024-03-15 11:12:42
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-10 11:52:06
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<int> data(n);

        for (int i = 0; i < n; i++)
        {
            cin >> data[i];
        }
        int sum = accumulate(data.begin(), data.end(), 0);
        int avg = sum / n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (data[i] > avg)
            {
                ans += data[i] - avg;
            }
        }
        cout << ans << endl
             << endl;
    }

    return 0;
}
