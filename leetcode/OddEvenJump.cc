//leetcode 975
//During odd numbered jumps,you jump to the index j such that A[i] <= A[j] is the smallest possible value.
//During even numbered jumps,you jump to the index j such that A[i] >= A[j] and A[j] is the largest possible value

//解题思路：dp + binary search 
//第一次跳为 upper 第二次为 down
//建立 online BST
// lower_bound upper_bound :二分搜索  time complex(log(n))
#include <iostream>
#include <map>
#include <vector>

using std::vector;
using std::map;

class Solution{     
public:
    int oddEvenJumps(vector<int>& A){
        const int n = A.size();
        //第二维度 0 - up jump ;1- down jump
        vector<vector<int>> dp(n,vector<int>(2));
        dp[n-1][0] = dp[n-1][1] = 1;
        //存储每个下一跳的index？？？
        map<int,int> m;
        m[A[n-1]] = n-1;
        int ans = 1;

        for(int i = n-2;i>=0;--i){
            // 查找第一个大于等于x的值的地址
            auto o = m.lower_bound(A[i]);
            if(o != m.end()) dp[i][0] = dp[o->second][1];
            // 查找最后一个比其大的
            auto e = m.upper_bound(A[i]);
            if(e != m.begin()) dp[i][1] = dp[prev(e)->second][0];
            // 如果可以跳到最后格，注意是第一跳必须是up jump
            if(dp[i][0]) ++ans;
            // 记录第一次出现值及其索引
            m[A[i]] = i;
        }
        return ans;
    }
};