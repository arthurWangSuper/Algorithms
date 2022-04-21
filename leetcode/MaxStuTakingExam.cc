// Leetcode 1349 Maximum Students Taking Exam
// Given a m*n matrix seats that represent seats distributions.
// if a seats is broken, it is denoted by '#'character otherwise 
// it is denoted by '.' character

// stu can see the answers of those sitting next to the left,
// upper left and upper right, but cannot see the answers of 
// the students sitting directly in front or behind him.

// 数据规模小，但是硬搜索会超时

// 画画图还是有助于理解题目的

// row(i) 只与 row(i-1)有关
#include <iostream>
#include <vector>
#include <algorithm>

using std::max;
using std::vector;
using std::begin;
using std::end;


class Solution{
public:
    int maxStudents(vector<vector<char>> &seats){
            int m = seats.size();
            int n = seats[0].size();

            vector<vector<int>> dp(m+1,vector<int>(1 << n));//binary string

            for(int i = 0;i < m; ++i) // row_i 
                for(int l = 0; l < (1<<n); ++l) // row_(i-1)'s state  枚举所有的状态
                    for(int c = 0; c < (1<<n); ++c){  // row_i's state
                        bool flag = true;
                        for(int j = 0; j < n && flag ; ++j){ //检查某一位具体的座位
                            if(!(c & (1 << j))) continue; 
                            if(seats[i][j] == '#') flag = false; //
                            bool lt = j == 0 ? false :(c & (1 << (j - 1))); // 左
                            bool rt = j == n-1 ? false:(c & (1 << (j + 1))); // 右
                            bool ul = (j == 0 || i == 0) ? false:(l & (1 << (j - 1))); // 左前
                            bool ur = (j== n - 1 || i == 0) ? false:(l & 1 << (j + 1)); // 右前
                            if(lt || rt || ul || ur) flag = false;
                        }
                        if(flag)
                            dp[i+1][c] = max(dp[i+1][c], dp[i][l] + __builtin_popcount(c));
                    }
        return *max_element(begin(dp[m], end(dp[m])));
    }
};

class Solution{
public:
    int maxStudents(vector<vector<char>>& seats){
        const int m = seats.size();
        const int n = seats[0].size();
        vector<int> s(m+1);
        for(int i = 1; i <= m; ++i)
            for(int j = 0; j < n; ++j)
                s[i] |= (seats[i-1][j] == '#') << j; //mask

        vector<vector<int>> dp(m+1, vector<int>(1<<n));
        for(int i = 1; i <= m; ++i)
            for(int c = 0; c < (1 << n); ++c){
                if(c & (c >> 1)|| c & s[i]) continue; //连续 或者是 坏的座位
                for(int l = 0; l < (1 << n); ++l){
                    if(!(l & s[i-1]) && !(l & (c >> 1))&& !((l >> 1) & c))
                        dp[i][c] = max(dp[i][c], dp[i-1][l] + __builtin_popcount(c));
                }
            }
        return *max_element(begin(dp[m], end(dp[m])));
    }
};