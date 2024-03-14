#include <iostream>
#include <vector>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
int m, n;
struct node
{
    int w;
    int h;
};

vector<node> v;

int fun(int x)
{
    int k = m, height = 0, sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (i == x) // 删除
            continue;
        if (v[i].w < k)
        { // 不能等于，因为等于即当前行排满，应更新k，但没有更新
            k -= v[i].w;
            height = max(height, v[i].h);
        }
        else
        {
            int tmp = ceil(1.0 * v[i].h * k / v[i].w);
            height = max(height, tmp);
            k = m;
            sum += height;
            height = 0;
        }
    }
    return sum + height;
}

int main()
{
    cin >> m >> n;
    int a, b;
    while (n--)
    {
        cin >> a >> b;
        v.push_back({a, b});
    }
    int ans = INF;
    for (int i = 0; i < v.size(); i++)
    {
        ans = min(ans, fun(i));
    }
    cout << ans << endl;
    return 0;
}
