/*
 * @Description:
 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2023-11-16 16:27:27
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-29 14:56:01
 */

#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> v;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) {
            int j = i, k = 0;
            v.clear();
            while (j < m && k < n) {
                v.push_back(mat[j][k]);
                j++;
                k++;
            }
            sort(v.begin(), v.end(), greater<int>());
            j = i, k = 0;
            while (!v.empty()&& j < m && k < n) {
                mat[j][k] = v.back();
                v.pop_back();
                j++;
                k++;
            }
        }

        for (int i = 0; i < n; i++) {
            int j = 0, k = i;
            v.clear();
            while (j < m && k < n) {
                v.push_back(mat[j][k]);
                j++;
                k++;
            }
            sort(v.begin(), v.end(), greater<int>());
            j = 0, k = i;
            while (!v.empty() && j < m && k < n) {
                mat[j][k] = v.back();
                v.pop_back();
                j++;
                k++;
            }
        }
        return mat;
    }
};


int main()
{
    Solution solution;

    vector<vector<int>> mat = { {3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2} };

    //  开始
    auto start = chrono::steady_clock::now();
    //

    auto ans = solution.diagonalSort(mat);

    for (int i = 0;i < ans.size();i++) {

        for (int j = 0;j < ans[i].size();j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    // 结束
    auto end = chrono::steady_clock::now();
    // 时间差异
    auto diff = end - start;

    cout << endl;
    cout << "运行耗时:：" <<
        chrono::duration<double, milli>(diff).count() << " ms" << endl;
    return 0;
}