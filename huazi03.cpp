/*
 * @Description:云上故障逃生
 在云上多个业务节点之间选择最快的逃生节点集，并考虑每个节点的剩余业务容量。
 有一个网络时延表，表示每个节点到其他节点的通信延迟；
 还有一个剩余业务容量表，表示每个节点的剩余业务容量。
 在一个节点故障时，需要选择一个或多个逃生节点，确保逃生路径的时延最小，并且逃生节点集各节点剩余容量的总和足够容纳故障节点的业务量，
 当故障节点与多个节点最短距离相同，优先选择编号较小的节点容灾，如果逃生节点集合中多个节点最短距离相同时按编号从小到大的顺序排列。
 输入：
 第1行n表示云上业务节点数，2<=n<=10000，节点编号从0开始，依次递增；
 第2到1+n行表示业务节点间的网络时延矩阵表delayMatrix,
 delayMatrix[i][j]表示节点i到节点j的通信时延;
 1)如果节点i和节点j之间没有直接相连的边，则delayMatrix[i][j] = -1，第i个节点和它自己也没有边，所以delayMatrix[i][i] = -1;
 2）节点间有边时延范围为1<=delayMatrix[i][j]<=1000，矩阵元素间使用空格分割，另输入保证delayMatrix[i][j] = delayMatrix[j][i]；
 第2+n行表示各业务节点的剩余容量表remainingCapacity，其中remainingCapacity[i]表示节点i的剩余业务容量，业务量的范围1<=remainingCapacity[i]<=100，数组间元素使用空格分隔；
 第3+n行表示故障业务节点编号faultyNode，表示发生故障的节点，取值范围0<=faultyNode<=n-1；
 第4+n行表示受损业务节点需要迁移的业务量，受损业务量的范围(0-1000]
 输出：
 返回符合条件的逃生路径节点编号列表（以空格间隔），当所有节点都不够故障节点业务容灾的时候输出所有容灾节点
 示例1：
    输入：
        4
        -1 5 -1 8
        5 -1 1 3
        -1 1 -1 4
        8 3 4 -1
        10 20 15 25
        2
        12
    输出：1

 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2024-04-18 10:37:17
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-18 10:37:25
 */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// Dijkstra算法找出故障节点到所有其他节点的最短路径
vector<int> dijkstra(const vector<vector<int>>& delayMatrix, int src, int n) {
    vector<int> dist(n, INT_MAX); // 存储到各节点的最短距离
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 最小堆
    pq.push({ 0, src });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; ++v) {
            if (delayMatrix[u][v] > 0) {
                int newDist = dist[u] + delayMatrix[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({ newDist, v });
                }
            }
        }
    }
    return dist;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> delayMatrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> delayMatrix[i][j];
        }
    }

    vector<int> remainingCapacity(n);
    for (int i = 0; i < n; ++i) {
        cin >> remainingCapacity[i];
    }

    int faultyNode, neededCapacity;
    cin >> faultyNode >> neededCapacity;

    auto distances = dijkstra(delayMatrix, faultyNode, n);

    vector<pair<int, int>> candidates;
    for (int i = 0; i < n; ++i) {
        if (i != faultyNode && distances[i] != INT_MAX) {
            candidates.push_back({ distances[i], i });
        }
    }

    sort(candidates.begin(), candidates.end()); // 按距离和节点编号排序

    vector<int> result;
    int totalCapacity = 0;
    for (auto& p : candidates) {
        if (totalCapacity >= neededCapacity) break;
        int node = p.second;
        if (remainingCapacity[node] > 0) {
            result.push_back(node);
            totalCapacity += remainingCapacity[node];
        }
    }

    if (totalCapacity < neededCapacity) {
        result.clear();
        for (int i = 0; i < n; ++i) {
            if (i != faultyNode) {
                result.push_back(i);
            }
        }
    }

    if (result.empty()) {
        cout << "0" << endl;
    }
    else {
        for (int i = 0; i < result.size(); ++i) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}
