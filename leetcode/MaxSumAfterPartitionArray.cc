// leetcode 1043: Partition Array for Maximum Sum
// Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  
// After partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning.

#include <iostream>

using namespace std;

class solution{
public:
    int maxSumAfterPartitioning(vector<int>& A，int K){
        int n = A.size();
        vector<int> dp(n+1,0);

        for(int i=0;i<n;++i){
            int m=INT_MIN;
            for(int k=1;k<=K&&i-k>=0;++k){
                m = max(m,A[i-k]);
                dp[i] = max(dp[i],dp[i-k]+m*k);
            }
        }
        return dp[n];
    }    
};