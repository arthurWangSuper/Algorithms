#include <iostream>
#include <vector>

using std::vector;

// up-to-bottom
class Solution{
public:
    int numberOfArrays(string s, int k){
        constexpr int kMod = 1e9 + 7;
        const int n = s.length();
        vector<int> mem(n, -1);
        // dp(i) return # of ways for s[i:n]
        function<int(int)> dp = [&](int i){
            if(i == n ) return 1;
            if(s[i] == '0') return 0;
            if( mem[i] >= 0) return mem[i];
            long sum = 0;
            int ans = 0;

            for(int j = i+1; j <= n;++j){
                num = num*10+(s[j-1] - '0');
                if(num > k) break;
                ans = (ans + dp(j)) % kMod;
            }
            return mem[i] = ans;
        };
    }
};
// bottom-to-up
class Solution{
public:
    int numberOfArrays(string s, int k){
        constexpr int kMod = 1e9 + 7;
        const int n = s.length();
        // # of ways for s[i:n]
        vector<int> dp(n+1);
        dp.back() = 1;
        for(int i = n-1;i >= 0;--i)
        {
            if(s[i] == '0') continue;
            long num = 0;
            for(int j = i+1; j <= n; ++j)
            {
                num = num*10 + (s[j-1] - '0');
                if(num > k) break;
                dp[i] = (dp[i] + dp[j]) %kMod;
            }
        }
        return dp[0];
    }
};
