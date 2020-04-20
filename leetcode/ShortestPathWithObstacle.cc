#include <iostream>
#include <vector>

using namespace std;

class SolutionBFS{
public:
    int shortPath(vector<vector<int>> &grid,int k)
    {
        const vector<int> dirs{0,1,0,-1,0};
        const int n = grid.size();
        const int m = grid[0].size();

        vector<vector<int>> seen(n,vector<int>(m,INT_MAX));
        queue<tuple<int,int,int>> q;

        int steps = 0;
        q.emplace(0,0,0);
        seen[0][0] = 0;

        while(!q.empty()){
            int size = q.size();
            // 注意此处的结构
            while(size--){
                int cx,cy,co;
                tie(cx,cy,co) = q.front();
                q.pop();

                if(cx == m-1 && cy == n-1)
                    return steps;
                for(int i=0;i<4;++i)
                {
                    int x = cx + dirs[i];
                    int y = cy + dirs[i+1];

                    if(x<0 || y<0 || x>= m|| y>=m) continue;
                    int o = co+grid[y][x];
                    if(o>=seen[y][x] || o > k) continue;
                    seen[y][x] = o;
                    q.emplace(x,y,o);
                }
            }
            ++steps;
        }
        return -1;
    }
};
// top-down
class SolutionDP_TD{
public:
    int shortestPath(vector<vector<int>>& grid, int K){
        constexpr int kInf = 1e9;
        const vector<int> dirs{0,1,0,-1,0};
        const int m = grid.size();
        const int n = grid[0].size();
        // 标记是否求解过这个问题，就不是很清楚了 相当于是一个padding的过程，因为dirs中有向左向右向下的问题，所以大一圈
        vector<vector<vector<int>>> mem(m+2,vector<vector<int>>(n+2,vector<int>(K+1,-1)));
        
        vector<vector<int>> seen(m+2, vector<int>(n+2));

        function<int(int,int,int)> dp = [&](int x,int y,int k){
            if(x<1 || x>n || y<1 || y> m || k<0 || seen[y][x]) return kInf;
            if( x==1&&y==1 ) return 0;
            // 已经计算过了
            if(mem[y][x][k] != -1) return mem[y][x][k];
            // 表示正在访问
            seen[y][x] = 1;
            int ans = kInf;

            for(int i=0; i<4; ++i)
                ans = min(ans,1+dp(x+dirs[i],y+dirs[i+1],k-grid[y-1][x-1]));
            // 做backtracking
            seen[y][x] = 0;
            return mem[y][x][k] = ans;
        };
        const int ans = dp(n,m,K);

        return ans>=kInf?-1:ans;
    }
};
// bottom-up
class SolutionDP_BU{
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    constexpr int kInf = 1e9;
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<vector<int>>> dp(m + 2, vector<vector<int>>(n + 2, vector<int>(k + 1, kInf)));
    dp[1][1][0] = 0;
    for (int s = 0; s < 3; ++s)
      for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
          const int o = grid[i - 1][j - 1];
          for (int z = 0; z + o <= k; ++z)
            dp[i][j][z + o] = min(dp[i][j][z + o],
                                  min({dp[i - 1][j][z],
                                       dp[i][j - 1][z],
                                       dp[i + 1][j][z],
                                       dp[i][j + 1][z]}) + 1);
        }
    int ans = *min_element(begin(dp[m][n]), end(dp[m][n]));
    return ans >= kInf ? -1 : ans;
  }
};