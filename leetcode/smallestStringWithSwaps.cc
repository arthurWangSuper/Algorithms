//leetcode 1202
/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    string smallestStringWithSwap(string s,vector<vector<int>>& pair){
        vector<vector<int>> g(s.length);
        // 建立邻接表
        for(const auto& e:pairs){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        unordered_set<int> seen;
        vector<int> idx;
        string tmp;
        function<void(int)> dfs=[&](int cur){
            if(seen.count(cur)) return;
            seen.insert(cur);
            idx.push_back(cur);
            tmp += s[cur];
            for(int nxt:g[cur]) dfs(nxt);
        };

        for(int i=0;i<s.length();++i){
            if(seen.count(i)) continue;
            idx.clear();
            tmp.clear();
            dfs(i);
            //排序 字符和index都进行排序
            sort(begin(tmp),end(tmp));
            sort(begin(idx),end(idx));

            for(int k=0;k<idx.size();++k)
                s[idx[k]] = tmp[k];
        }
        return s;
    }
};