// leetcode 130  Surrounded Regions
// Given a 2D board contain 'X' and 'O'，capture all regions surrounded by 'x'
// A region is captured by flipping all 'O's into 'X's in that surrounded region
#include<iostream>
#include<vector>
#include<functional>

using namespace std;

class SolutionDFS{
    void slove(vector<vector<char>> &board ){
            if(board.empty()) return;

            int m = board.size();
            int n = board[0].size();

            function<void(int,int)> dfs = [&](int x,int y){
                if(x<0 || x>n || y<0|| y>m || board[x][y] != 'O') return;

                board[x][y] = 'G'; // 作用为标记为已经访问过 剪枝

                dfs(x,y+1);
                dfs(x,y-1);
                dfs(x+1,y);
                dfs(x-1,y);
            };

            for(int x=0;x<n;++x)
                dfs(x,0),dfs(x,m-1);
            for(int y=0;y<m;++y)
                dfs(0,y),dfs(n-1,y);
            
            map<char,char> trans{{'O','X'},{'G','O',},{'X','X'}};
            
            for(int x =0;x<n;++x)
                for(int y=0;y<m;++y)
                    board[x][y] = trans[board[x][y]];
        
            return ; 
    }
};