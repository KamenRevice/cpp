
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 4, 5, 10};
    unordered_map<int, int> mp;

    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            int num = v[i] * v[j];
            if (mp[num] != 0)
            {

                count += mp[num] * 8;

                cout << num << ":"
                     << mp[num] << endl;
                cout << count << endl;
            }
            mp[num]++;
        }
    }
}