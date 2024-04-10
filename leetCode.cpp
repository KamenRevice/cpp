/*
 * @Description:
 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2023-11-16 16:27:27
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-07 16:20:07
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
            return false;
        stack<char> st;
        for (char c : s)
        {
            if (c == '(')
                st.push(')');
            else if (c == '[')
                st.push(']');
            else if (c == '{')
                st.push('}');
            else if (st.empty() || c != st.top())
                return false;
            else
                st.pop();
        }
        return st.empty();
    }
};

int main()
{
    Solution solution;

    string s = "){";

    //  开始
    auto start = chrono::steady_clock::now();
    //

    auto ans = solution.isValid(s);

    cout << ans << endl;

    // 结束
    auto end = chrono::steady_clock::now();
    // 时间差异
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}