/*
 * @Description: 
 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2024-04-24 19:51:29
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-24 20:01:46
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Player {
    int id;                     // 球员编号
    int totalGoals;             // 总进球数
    int longestStreak;          // 最长连续进球
    vector<int> misses;         // 射失的次序列表

    Player(int id, const string& sequence)
            : id(id), totalGoals(0), longestStreak(0) {
        int currentStreak = 0;
        bool isGoal = false;

        for (int i = 0; i < sequence.length(); i++) {
            if (sequence[i] == '1') {
                totalGoals++;
                if (isGoal) {
                    currentStreak++;
                } else {
                    isGoal = true;
                    currentStreak = 1;
                }
            } else {
                if (isGoal) {
                    longestStreak = max(longestStreak, currentStreak);
                    isGoal = false;
                }
                misses.push_back(i + 1); // 射失的次序，从1开始
            }
        }
        if (isGoal) {
            longestStreak = max(longestStreak, currentStreak);
        }
    }
};

// 自定义排序函数
bool compare(const Player& a, const Player& b) {
    if (a.totalGoals != b.totalGoals) return a.totalGoals > b.totalGoals;
    if (a.longestStreak != b.longestStreak) return a.longestStreak > b.longestStreak;
    for (size_t i = 0; i < min(a.misses.size(), b.misses.size()); i++) {
        if (a.misses[i] != b.misses[i]) return a.misses[i] > b.misses[i];
    }
    return a.misses.size() < b.misses.size(); // 更少的射失意味着更晚首次射失
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Player> players;

    for (int i = 1; i <= n; i++) {
        string sequence;
        cin >> sequence;
        players.emplace_back(i, sequence);
    }

    sort(players.begin(), players.end(), compare);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << players[i].id;
    }
    cout << endl;

    return 0;
}