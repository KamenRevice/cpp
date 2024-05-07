#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 检测环
void detectCycles(int start, vector<int>& edges, vector<bool>& visited, vector<bool>& inStack, vector<int>& stack, vector<vector<int>>& cycles) {
    int current = start;
    // 循环直到遇到已访问过的节点
    while (!visited[current]) {
        visited[current] = true;
        inStack[current] = true;
        stack.push_back(current);
        current = edges[current]; // 转移到下一个节点
    }

    if (inStack[current]) {  // 检测到一个环
        auto it = find(stack.begin(), stack.end(), current);
        if (it != stack.end()) {
            // 将环的节点添加到 cycles 中
            cycles.emplace_back(it, stack.end());
        }
    }

    // 标记栈中的所有节点为不在环中
    for (int x : stack) {
        inStack[x] = false;
    }
    stack.clear(); // 清空栈
}

// 找到最佳环
vector<int> findBestCycle(int n, vector<int>& edges) {
    vector<bool> visited(n, false);
    vector<bool> inStack(n, false);
    vector<vector<int>> cycles;
    vector<int> stack;

    // 对于每个节点，检测是否存在环
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            detectCycles(i, edges, visited, inStack, stack, cycles);
        }
    }

    // 找到具有最高内聚力值的环
    int bestIndex = -1;
    int bestValue = INT_MIN;
    int maxMember = INT_MIN;

    for (int i = 0; i < cycles.size(); ++i) {
        const auto& cycle = cycles[i];
        int L = cycle.size(); // 环的长度
        unordered_set<int> uniqueVisitors;
        // 统计环中访问过的节点（不包括环中的节点）
        for (int node : cycle) {
            int target = edges[node];
            if (find(cycle.begin(), cycle.end(), target) == cycle.end()) {
                uniqueVisitors.insert(target);
            }
        }
        int V = uniqueVisitors.size(); // 访问过的节点数
        int H = L - V; // 内聚力值
        int currentMaxMember = *max_element(cycle.begin(), cycle.end()); // 最大成员编号

        // 比较基于内聚力值和最大成员的大小
        if (H > bestValue || (H == bestValue && currentMaxMember > maxMember)) {
            bestIndex = i;
            bestValue = H;
            maxMember = currentMaxMember;
        }
    }

    if (bestIndex != -1) {
        auto& bestCycle = cycles[bestIndex];
        // 将环旋转使最小节点为起始节点
        rotate(bestCycle.begin(), min_element(bestCycle.begin(), bestCycle.end()), bestCycle.end());
        return bestCycle;
    }
    return {}; // 没有找到环
}

int main() {
    int n;
    cin >> n;
    vector<int> edges(n);
    // 读取每个节点的连接节点
    for (int i = 0; i < n; ++i) {
        cin >> edges[i];
    }

    // 找到最佳环并输出
    vector<int> bestCycle = findBestCycle(n, edges);
    for (size_t i = 0; i < bestCycle.size(); ++i) {
        if (i > 0) cout << " ";
        cout << bestCycle[i];
    }
    cout << endl;

    return 0;
}