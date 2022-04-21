// Leetcode 1326 Given an integer n and 
// an integer array ranges of length n+1 where ranges[i] means the i-th tap can water the area [i - ranges[i]], i+ ranges[i]]
// if it was open

// similar with 1024 Video Stitching && 45 Jump Game II

// Greedy
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::vector;
using std::pair;
using std::begin;
using std::end;

// LC 1024
class Solution_1024{
public:
    int minTaps(int n, vector<int> &ranges){
        vector<pair<int, int>> t;
        // o(n) reduction
        for(int i =0;i <= n; ++i)
        {
            t.emplace_back(i - ranges[i], i + ranges[i]);
        }

        // same to Leetcode 1024 
        std::sort(begin(t), end(t));
        int ans = 0;
        int i = 0, l = 0, e = 0;//end
        while(e < n){
            // Extend to the right most w.r.t t[i].first < = l
            // make sure overlap
            while(i <= n && t[i].first <= l)
            {
                e = std::max(e, t[i++].second);
            }
            if(l == e) return -1;  
            l = e;
            ++ans;
        }
        return ans;
    }
};

// LC 45
class Solution_45{
public:
    int minTaps(int n, vector<int> &ranges){
        vector<int> nums(ranges.size());
        for(int i = 0; i<= n; ++i){
            int s = std::max(0, i - ranges[i]);
            nums[s] = i + ranges[i];
        }
        // 45. Jump Game II
        int steps = 0;
        int l = 0; // 上次能跳到的位置
        int e = 0; // 当前能跳到的最远位置
        for(int i = 0; i <= n; ++i){
            if(i > e) return -1;
            if(i > l) {++steps; l = e;}  //重新跳
            e = std::max(e, nums[i]);
        }
        return steps;
    }
};