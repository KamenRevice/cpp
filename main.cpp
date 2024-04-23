/*
 * @Description:
 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2023-12-08 16:06:55
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-15 14:48:33
 */

#include <bits/stdc++.h>

using namespace std;


/**
 * @description: 广度优先搜索
 * @return {*}
 * @author: kaiju
 */
int dir[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 }; // 表示四个方向
// gird是一个二维数组，表示地图
// visited标记访问过的节点，防止重复访问
// x,y表示开始搜索的坐标
void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y)
{
    queue<pair<int, int>> que; // 定义队列
    que.push({ x, y });          // 将起始节点加入队列
    visited[x][y] = true;      // 标记起始节点已经访问
    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();                               // 取出队列的头部元素
        int curx = cur.first, cury = cur.second; // 取出坐标
        for (int i = 0; i < 4; i++)
        {
            int nextx = curx + dir[i][0], nexty = cury + dir[i][1]; // 计算下一个节点的坐标
            if (nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size())
                continue;
            ; // 坐标越界，直接跳过
            if (!visited[nextx][nexty])
            {                                 // 如果下一个节点没有访问过
                que.push({ nextx, nexty });     // 队列添加该节点为下一轮要遍历的节点
                visited[nextx][nexty] = true; // 只要加入队列就立刻标记，避免重复访问
            }
        }
    }
}

/**
 * @description: 深度优先搜索
 * @return {*}
 * @param {vector<vector<int>>} grid
 * @param {vector<vector<bool>>} visited
 * @param {int} x
 * @param {int} y
 */
void dfs(vector<vector<int>>& graph, vector<bool>& visited, int cur) {
    visited[cur] = true; // 标记当前节点已经访问
    //处理当前节点x,y
    for (int i = 0;i < graph[cur].size();i++) {
        int next = graph[cur][i];
        if (!visited[next]) {// 如果下一个节点没有访问过
            dfs(graph, visited, next); // 递归访问下一个节点
        }
    }
}

void dfsTraversal(vector<vector<int>>& grahp) {
    int n = grahp.size();
    vector<bool> visited = vector<bool>(n, false);
    for (int i = 0;i < n;i++) {
        if (!visited[i]) {
            dfs(grahp, visited, i);
        }
    }
}


int main()
{
    vector<vector<int>> grid = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    return 0;
}

