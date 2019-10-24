// Leetcode 1155

// 注意优化：
// 1 从line 18看出来，当前dp值只与前一行有关
// 2 滚动数组
#include <iostream>
#include <vector>

class Solution{
public:
    int NumOfDiceRollsWithTargetSum(int d,int f,int target){
        constexpr int kMod = 1e9+7;
        //需要注意的是dp数组的维度都代表了什么
        std::vector<std::vector<int>> dp(d+1,std::vector<int>(target+1));
        dp[0][0] = 1;
        for(int i=0;i<=d;i++)
            for(int j=0;j<=f;j++)
                for(int k=j;k<=target;k++)
                    dp[i][j]=(dp[i][j]+dp[i-1][k-j])%kMod;

        return dp[d][target];
    }
};