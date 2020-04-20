// Leetcode 1284 Minimum Number of Flips to Convert Binary Matrix to Zero Matrix

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution{
public:
    int minFlips(vector<vector<int>>& mat){
        const int m = mat.size();
        const int n = mat[0].size();
        const vector<int> dirs{0,1,0,-1,0,0};
        // (x,y)为 坐标
        function<int(int,int,int)> flip = [&](int s,int x,int y){
            for(int i=0;i<5;++i){
                const int tx = x+dirs[i];
                const int ty = y+dirs[i+1];
                // 检查是否越界
                if(tx < 0 || tx >= n || ty <0 || ty >= m) continue;
                s ^= (1<<ty*n+tx);
            }
            return s;
        };

        int steps = 0;
        queue<int> q;
        // 一共有2^(m*n)中状态
        vector<int> seen(1<<(n*m));
        int start = 0;
        for(int y=0;y<m;++y)
            for(int x=0;x<n;++x){
                start |= (mat[y][x]<<(y*n+x));
            }
        q.push(start);
        seen[start] = 1;

        while(!q.empty()){
            int size = q.size();
            while(size--)
            {
                int s=q.front();
                if(s == 0) return steps;
                q.pop();
                
                for(int y=0;y<m;++y)
                    for(int x=0;x<n;++x){
                        int t=flip(s,x,y);
                        if(seen[t]) continue;
                        seen[t]=1;
                        q.push(t);
                    }
            }
            ++steps;
        }
    return -1;
    }
};