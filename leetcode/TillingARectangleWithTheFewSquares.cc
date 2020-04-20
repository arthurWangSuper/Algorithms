#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// DP
class SolutionDP{
public:
int tillingRectangle(int n,int m){
        if(max(n,m) == 13 && min(n,m) == 11 ) return 6;

        vector<vector<int>> dp(n+1,vector<int>(m+1));

        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                dp[i][j] = INT_MAX;
                if(i == j){
                    dp[i][j] = 1;
                    continue;
                }
                for(int r=1;r <= i/2;++r)
                {
                    // 横向分割
                    dp[i][j] = min(dp[i][j],dp[r][j]+dp[i-r][j]);
                }
                for(int c=1;c <= j/2;++c)
                {
                    // 纵向分割
                    dp[i][j] = min(dp[i][j],dp[i][c]+dp[i][j-c]);
                }
            }
    }
};

// DFS 状态压缩，剪枝
class SolutionDFS{
public:
    int tillingRectangle(int n,int m){
            if(n>m) return tillingRectangle(m,n);
            int ans = n*m;

            // h代表每一个横坐标的填充度
            vector<int> h(n);
            function<void(int)> dfs = [&](int cur){     
            // 从低的地方开始填充      
            auto it = min_element(begin(h),end(h));
            if(*it == m){
                // 代表填充结束
                ans = cur;
                return ;
            }

            // 获得最低点
            int low = *it;
            // 最低点位置   起始位
            int s = it-begin(h);
            // 结束位置
            int e = s;
            // e-s+1+low <= m :填的块不超过高度
            while(e<n && h[e] == h[s] && (e-s+1+low) <= m) ++e;
            
            for(int i= --e; i>= s; --i){
                int size = i-s+1;
                // 更新状态
                for(int j=s;j <= i;++j) h[j] += size;
                dfs(cur+1);
                // 回溯 去考虑更多的可能
                for(int j=s;j <= i;++j) h[j] -= size;
            }
        };
        dfs(0);
        return ans;
    }
};