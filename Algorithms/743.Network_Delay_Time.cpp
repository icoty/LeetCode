#include "AllInclude.h"

class Solution {
    public: //  https://www.cnblogs.com/grandyang/p/8278115.html
        int networkDelayTime(vector<vector<int>>& times, int N, int K) {
            int ret = 0;
            vector<vector<int>> edges(101, vector<int>(101, -1));   // 存储边
            queue<int> q{{K}};  // 队列, 起点为k
            vector<int> dist(N + 1, INT_MAX);   //  k到1~N的距离
            dist[K] = 0;                        //  k到k的距离为0
            for (auto e : times) 
                edges[e[0]][e[1]] = e[2];       //  邻接矩阵存储u到v的权重
            while (!q.empty()) 
            {
                unordered_set<int> visited;
                for(int i = q.size(); i > 0; --i) { // 第一次进入只有一个节点K,i=1, BFS
                    int u = q.front(); q.pop();
                    for(int v = 1; v <= 100; ++v) {
                        if(edges[u][v] != -1 && dist[u] + edges[u][v] < dist[v]) {
                            if (!visited.count(v)) {
                                visited.insert(v);
                                q.push(v);
                            }
                            dist[v] = dist[u] + edges[u][v];
                        }
                    }
                }
            }

            for(int i = 1; i <= N; ++i) 
            {
                ret = max(ret, dist[i]);
            }
            return ret == INT_MAX ? -1 : ret;        
        }
};
