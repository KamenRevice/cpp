// https: // kamacoder.com/problempage.php?pid=1006

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        float sum = 0;
        int count = 0;
        int flag = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
            {
                sum += 4;
                count++;
                continue;
            }
            if (s[i] == 'B')
            {
                sum += 3;
                count++;
                continue;
            }
            if (s[i] == 'C')
            {
                sum += 2;
                count++;
                continue;
            }
            if (s[i] == 'D')
            {
                sum += 1;
                count++;
                continue;
            }
            if (s[i] == 'F')
            {
                sum += 0;
                count++;
                continue;
            }
            if (s[i] == ' ')
            {
                continue;
            }

            flag = 0;
            cout << "Unknow" << endl;

            break;
        }
        if (flag)
            cout << fixed << setprecision(2) << sum / count << endl;
    }
    return 0;
}