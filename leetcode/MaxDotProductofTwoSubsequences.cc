// leetcode 1458: Max Dot Product of Two Subsequences
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution1 {
public:
    int maxDotProduct(vector<int> & nums1, vector<int> &nums2 ){
        const int n1 = nums1.size();
        const int n2 = nums2.size();

        vector<vector<int>> dp(n1, vector<int>(n2));

        for(int i = 0; i < n1; ++i)
            for(int j = 0; j < n2; ++j){
                dp[i][j] = nums1[i] * nums2[j];
                // case 1: if dp[i-1][j-1] < 0
                if(i > 0 && j > 0) dp[i][j] += max(0,dp[i-1][j-1]);
                // case 2: without sums1[i]
                if(i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                // case 3: without sums2[j]
                if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
            } 
            return dp.back().back();
    }
};

class Solution2 {
public:
    int maxDotProduct(vector<int> & nums1, vector<int> &nums2){

        const int n1 = nums1.size();
        const int n2 = nums2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, INT_MIN/2));
        
        for(int i = 1; i <= n1; i++)
            for(int j = 1; j <= n2; j++)
            {
                    dp[i][j] = max({
                        dp[i-1][j],
                        dp[i][j-1],
                        max(0,dp[i-1][j-1]) + nums1[i-1]*nums2[j-1]
                    });
            }
            return dp[n1][n2];
    }
};