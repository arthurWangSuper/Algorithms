//
// Created by k on 19-7-27.
//

//consider a directed graph,with nodes labelled 0,1,...,n-1.
// In this graph,each edge is either red or blue,and there could be self-edges or parallel edges.

//Each [i,j] in red_edges denotes a red directed edge from node i to node j.Similarly,each[i,j] in blue directed edge from node i to node j.
//Return an array answer of length n,where each answer[x] is the length of the shortest path from node 0 to node x
// such that the edge colors alternate along the path (or -1 if such a path doesnt exist).


//constraints:
// 1<=n<=100
// red_edges.length<=400
// blue_edges.length<=400
// red_edges.length == blue_edges[i].length == 2
// 0 <= red_edges[i][j],blue_edges[i][j] < n


//Solution:BFS
//Time complexity:O(|V|+|E|)
//Space complexity:O(|V|+|E|)
#include <iostream>
#include <unordered_set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    vector<int> shortestAlternatingPaths(int n,vector<vector<int>>& red_edges,vector<vector<int>>& blue_edges){
        vector<unordered_set<int>> edge_r(n);
        vector<unordered_set<int>> edge_b(n);

        //将边节点用vector<unordered_set<int>> 来表示？？？ 为了查找效率 and 不是同一点？？？
        for(const auto& e:red_edges){
            edge_r[e[0]].insert(e[1]);
        }
        for(const auto& e:blue_edges){
            edge_b[e[0]].insert(e[1]);
        }

        unordered_set<int> seen_r;
        unordered_set<int> seen_b;

        vector<int> ans(n,-1);
        //(node,color)
        queue<pair<int,int>> q;
        //开始两条路
        q.push({0,0});
        q.push({0,1});
        seen_b.insert(0);
        seen_r.insert(0);

        int steps=0;

        while(!q.empty()){
            int size=q.size();

            while(size--){
                int p = q.front().first;
                int is_red = q.front().second;
                q.pop();
                ans[p] = ans[p]>=0?min(ans[p],steps):steps;
                //决定从那边取边
                const auto& edges =is_red?edge_r:edge_b;
                auto& seen = is_red?seen_r:seen_b;

                for(int nxt:edges[p]){
                    //是否已经遍历
                    if(seen.count(nxt)) continue;
                    seen.insert(nxt);
                    q.push({nxt,1-is_red});
                }
            }
            ++steps;
        }
        return ans;
    }
};
