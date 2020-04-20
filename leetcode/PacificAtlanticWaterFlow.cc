/* leetcode 417
*/

#include<iostream>
#include<vector>

using namespace std;

class SolutionDFS{
public:
    vector<pair<int,int>> pacificAtlantic(vector<vector<int>>& matrix){
        if(matrix.empty()) return {};

        const int n = matrix.size();
        const int m = matrix[0].size();

        vector<vector<int>> p(n,vector<int>(m));
        vector<vector<int>> a(n,vecor<int>(m));

        for(int x=0;x<m;++x){
            dfs(matrix,x,0,0,p);    //top
            dfs(matrix,x,n-1,0,a);  // bottom
        }

        for(int y = 0;y<n;++y){
            dfs(matrix,0,y,0,p);    //left
            dfs(matrix,m-1,y,0,a);  //right
        }

        // 合并
        vector<pair<int,int>> ans;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if(p[i][j]&&a[i][j]) ans.emplace_back(i,j);
    }
private:
    // v:可以访问到的标志
    void dfs(vector<vector<int>>& b,int x,int y,int h,vector<vector<int>>& v){
        
        if(x<0 || y<0 || x==b[0].size()|| y==b.size()) return ;
        // 判断是否可以访问到
        if(v[y][x] || b[y][x] < h) return ;
        
        v[y][x] = true;
        dfs(b,x+1,y,b[y][x],v);
        dfs(b,x-1,y,b[y][x],v);
        dfs(b,x,y+1,b[y][x],v);
        dfs(b,x,y-1,b[y][x],v);
    
    }

};

clas SolutinBFS{
public:
    vector<pair<int,int>> pacificAtlantic(vector<vector<int>>& matrix){{
        if(matrix.empty()) return {};

        const int n = matrix.size();
        const int m = matrix[0].size();

        const vector<int> dirs{0,1,0,-1,0};

        auto bfs = [&](queue<pair<int,int>> &q,vector<vector<int>>& v){
                while(!q.empty()){
                    const int y = q.front().first;
                    const int x = q.front().second;
                    q.pop();
                    const int h = matrix[y][x];
                    v[y][x] = true;

                    for(int i = 0; i<4; ++i){
                        int tx = x+dirs[i];
                        int ty = y+dirs[j];
                        if(tx < 0||ty < 0||tx == m||ty == n|| matrix[ty][tx]<h) continue;
                        q.push({ty,tx});
                    }
                }
        };
        queue<pair<int,int>> qp;
        queue<pair<int,int>> qa;
        vector<vector<int>> vp(n,vector<int>(m));
        vector<vector<int>> va(n,vector<int>(m));

        for(int x=0;x<m;++x){
            qp.push({0,x});
            qa.push({n-1,x});
        }

        for(int y=0;y<n;++y){
            qp.push({y,0});
            qa.push({y,m-1});
        }

        bfs(qp,vp);
        bfs(qa,va);

        // 合并
        vector<pair<int,int>> ans;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if(vp[i][j]&&va[i][j]) ans.emplace_back(i,j);

    }
};