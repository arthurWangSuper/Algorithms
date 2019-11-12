// LeetCode 417. Pacific Atlantic Water Flow
class SolutionDP {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};

        const int n=matrix.size();
        const int m=matrix[0].size();

        // 滚动数组最好
        vector<vector<int>> dp(n,vector<int> m);

        for(int x=0;x<m;++x){
            dp[0][x] |= 1;
            dp[n-1][x] |=2;
        }

        for(int y=0;y<n;++y){
            dp[y][0] |= 1;
            dp[y][m-1] |= 2;
        }

        const vector<int> dirs{0,-1,0,1,0};

        while(true){
            bool changed = false;
            for(int y=0;y<n;++y)
                for(int x=0;x<m;++x)
                    for(int d=0;d<4;++d){
                        const int tx = x + dirs[d];
                        const int ty = y + dirs[d+1];
                        if(tx<0||ty<0||tx==m||ty==n
                        || matrix[y][x]<matrix[ty][tx]  //保证水往高处流
                        || (dp[y][x]|dp[ty][tx]) == dp[y][x]) //保证有变化，无变化则推出
                            continue;
                        dp[y][x] = dp[ty][tx];
                        changed = true;
                    }
            if(!changed) break;
        }

        vector<pair<int,int>> ans;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if(dp[i][j] == 3)  ans.emplace_back(i,j);

        return ans;
    }
};
