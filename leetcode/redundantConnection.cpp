//
//  redundantConnection.cpp
//  
//
//  Created by wangtao on 2019/8/22.
//

// leetcode 684
//In this problem, a tree is an undirected graph that is connected and has no cycles.

//The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, …, N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

//The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

//Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//c++/DFS
class Solution{
public:
    //图的表示，邻接表
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        unordered_map<int,vector<int>> graph;
        for(const auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            
            unordered_set<int> visited;
            if(hasPath(u,v,graph,visited))
                return edge;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
private:
    bool hasPath(int curr,int goal,const unordered_map<int,vector<int>> &graph,
                 unordered_set<int>& visited){
        if(curr == goal) return true;
        visited.insert(curr);
        //如果是两个孤立点
        if(!graph.count(curr)||!graph.count(goal)) return false;
        //查看没有被访问过的邻接点 DFS的思想
        for(int next:graph.at(curr)){
            if(visited.count(next)) continue;
            if(hasPath(next,goal,graph,visited)) return true;
        }
        return false;
    }
};

//c++/Union Find
class UnionFindSet{
public:
    UnionFindSet(int n){
        ranks_ = vector<int>(n+1,0);
        parents_ = vector<int>(n+1,0);
        
        for (int i = 0; i<parents_.size(); ++i) {
            parents_[i] = i;
        }
        bool Union(int u,int v){
            int pu = Find(u);
            int pv = Find(v);
            if(pu == pv) return false;
            
            if(ranks_[pv] > ranks_[pu])
                parents_[pu] = pv;
            else if(ranks_[pu] > ranks_[pv])
                parents_[pv] = pu;
            else{
                parents_[pv] = pu;
                ranks_[pv] += 1;
            }
            return true;
        }
        int Find(int u){
            if(u != parents_[u])
                parents_[u] = Find(parents_[u]);
            return parents_[u];
        }
    }
    
private:
    vector<int> parents_;
    vector<int> ranks_;
 };
