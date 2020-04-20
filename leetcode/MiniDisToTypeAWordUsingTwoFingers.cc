// Leetcode 1320
// 画出树形图 有利于理解这个问题

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class SolutionA{
public:
    int minimumDistance(string word)
    {
        constexpr int kRest = 27;
        const int n = word.length();
        vector<vector<int>> mem(n,vector<int>(27));
        // 计算两个点的距离
        auto cost = [&](int c1,int c2){
            if(c1 == kRest) return 0;
            return abs(c1/6-c2/6)+abs(c1%6-c2%6);
        };

        // min cost to type word[i:n]. o is the last position of the other finger(remains finger)
        // the current finger is at word[i-1].

        function<int (int,int)> dp = [&](int i,int o){
            if(i == n) return 0;
            if(mem[i][o]) return mem[i][o];
            int p= i==0 ? kRest:word[i-1] - 'A';
            int c = word[i] -'A';
            return mem[i][o] = min(dp(i+1,o)+cost(p,c) //use the same finger to type, the other finger remains
                        ,dp(i+1,p)+cost(o,c));  //use the other finger to type, the prev finger remains 
        };

        return dp(0,kRest);
    }
};
// 其实不是很理解这个东西
class SolutionB {
public:
    int minimumDistance(string word)
    {
        constexpr int kRest = 26;
        const int n = word.length();

        // dp[i][j]:min cost to type word[0:i]
        // one finger is at word[i-1], another finger is at j
        vector<vector<int>> dp(n+1,vector<int>(27,INT_MAX));

        dp[0][kRest] = 0;

        // 计算两个点的距离
        auto cost = [&](int c1,int c2) {
            if(c1 == kRest) return 0;
            return abs(c1/6-c2/6)+abs(c1%6-c2%6);
        };

        for(int i = 0;i < n;i++) {
            int p = (i == 0) ? kRest:word[i-1] - 'A';
            int c =  word[i] - 'A';

            for(int j = 0; j <= 26; ++j) {
                dp[i+1][j] = min(dp[i+1][j],dp[i][j]+cost(p,c)); // same finger
                dp[i+1][p] = min(dp[i+1][p],dp[i][j]+cost(j,c)); // other finger
            }
        }
        return *min_element(begin(dp[n]),end(dp[n]))
    }
};

class SolutionC{
public:
    int minimumDistance(string word)
    {
        constexpr int kRest = 26;
        const int n = word.length();
        vector<vector<vector<int>>> mem(n,vector<vector<int>>(27,vector<int>(27,-1)));
        // 计算两个点的距离
        auto cost = [&](int c1,int c2){
            if(c1 == kRest) return 0;
            return abs(c1/6-c2/6)+abs(c1%6-c2%6);
        };

        // min cost to type word[i:n]. o is the last position of the other finger(remains finger)
        // the current finger is at word[i-1].

        function<int (int,int,int)> dp = [&](int i,int l,int r){
            if(i == n) return 0;
            if(mem[i][l][r] >= 0) return mem[i][l][r];
    
            int c = word[i] -'A';
            return mem[i][l][r] = min(dp(i+1,c,r)+cost(l,c) 
                        ,dp(i+1,l,c)+cost(r,c));   
        };

        return dp(0,kRest,kRest);
    }
};