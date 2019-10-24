// leetcode 1000 
/*
There are N piles of stones arranged in a row.  
The i-th pile has stones[i] stones.
A move consists of merging exactly K consecutive piles into one pile,
and the cost of this move is equal to the total number of stones in these K piles.
Find the minimum cost to merge all piles of stones into one pile.  
If it is impossible, return -1.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int mergeStones(vector<int>& stones,int K){
        const int n = stones.size();
        if((n-1)%(K-1)) return -1; //先确定是否有解
        const int kInf = 1e9;
        vector<int> sums(n+1);
        for(int i=0;i<n;i++)
            sums[i+1] = sums[i]+stones[i];
        //dp[i][j][k] := min cost to merge subarray i-j into k piles
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(K+1,kInf)));
        for(int i=0;i<n;++i)
            dp[i][i][1]=0;
        for(int l=2;l <= n;++l) //subproblem length
            for(int i=0;i<=n-1;++i){//start
                int j = i+l-1;//end;
                for(int k=2;k <=K;++k)
                    for(int m=i;m<j;m += K-1)
                        dp[i][j][k] = min(dp[i][j][k],dp[i][m][1]+dp[m+1][j][k-1]);
                    dp[i][j][1] = dp[i][j][K] +sums[j+1] - sums[i];
            }
        return dp[0][n-1][1];   
    }
}