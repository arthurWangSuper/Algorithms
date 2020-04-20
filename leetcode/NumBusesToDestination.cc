// leetcode 815 Bus Routes 
// BFS方案

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution{
public:
    int numBusesToDestination(vector<vector<int>>& routes,int S,int T){
        if(S == T) return 0;
        // 首先做映射
        unordered_map<int,vector<int>> m; // stop->bus
        for(int i=0;i<routes.size();++i)
            for(auto& stop:routes[i])
                m[stop].push_back(i);
        // 记录当前bus 是否已经乘坐，防止重复访问
        vector<int> ride(routes.size(),0);
        queue<int> q;
        q.push(S);
        int buses = 0;

        while(!q.empty()){
            // 读取当前队列中的元素个数，相当于说这一步中可以到达的所有stop
            int size = q.size();
            ++buses;
            while(size--){
                int curr = q.front();
                q.pop();
                for(const int bus:m[curr]){
                    // 减少重复访问
                    if(ride[bus]) continue;
                    ride[bus] = 1;
                    for(int stop:routes[bus]){
                        if(stop == T) return buses;
                        q.push(stop);
                    }
                }
            }
        }
        

    }
};