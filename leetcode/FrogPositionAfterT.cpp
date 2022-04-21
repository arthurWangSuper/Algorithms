// leetcode 1377
#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Solution{
public:
    double frogPosition(int n, vector<vector<int>>& edges,
                        int t, int target){
        vector<double> p(n+1);
        p[1] = 1.0;
        vector<vector<int>> g(n+1);
        // 统计邻接顶点，给出的是无向
        for(const auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> seen(n+1);
        seen[1] = 1;
        // 队列 放入邻接点
        queue<int> q{{1}};

        while(t--){
            int size = q.size();
            while(size--){
                int cur = q.front();
                q.pop();
                int children = 0;
                // 统计邻接点 count
                for(int nxt:g[cur])
                    if(!seen[nxt]) ++children;
                for(int nxt:g[cur])
                    if(!seen[nxt]++) {
                        q.push(nxt);
                        p[nxt] = p[cur] /children;
                    }
                    // key :fog jumps if this node has children 当店节点已经不可在被访问
                    if(children > 0) p[cur] = 0.0;
            }
        }
        return p[target];
    }
};