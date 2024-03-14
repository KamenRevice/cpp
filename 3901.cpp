#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int n = 20;

char s[25][25];

const int dx[] = {-1, 0, 1, -1};
const int dy[] = {-1, -1, -1, 0};

inline bool in(int x, int y)
{
    return x >= 1 && y >= 1 && x <= 20 && y <= 20;
}

bool judge(int x, int y)
{
    if (s[x][y] == '.')
    {
        return 0;
    }
    for (int i = 0; i < 4; i++)
    {
        bool flag = 1;
        for (int j = -2; j <= 2; j++)
        {
            int ux = dx[i] * j + x, uy = y + dy[i] * j;
            if (!in(ux, uy))
            {
                flag = 0;
                break;
            }
            if (s[ux][uy] != s[x][y])
            {
                flag = 0;
            }
        }
        if (flag == 1)
        {
            return 1;
        }
    }
    return 0;
}

bool isWin()
{
    // 枚举中心点
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (judge(i, j))
            {
                return 1;
            }
        }
    }
    return 0;
}

bool isCountVaild()
{
    int Ocount = 0, Xcount = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i][j] == 'o')
                Ocount++;
            if (s[i][j] == 'x')
                Xcount++;
        }
    }
    return abs(Ocount - Xcount) <= 1;
}

int main()
{
    for (int i = 1; i <= 20; i++)
    {
        scanf("%s", s[i] + 1);
    }
    if (isWin() || !isCountVaild())
    {
        puts("No");
    }
    else
    {
        puts("Yes");
    }
    return 0;
}