// leetcode 5 Given a string s, find the longest palindromic substring in s
// you may assume that the maxium length of s is 1000 => 根据100万规则，算法要想通过 复杂度应该为O(n^2)
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    string longestPalindrome(string str){
        const int n = str.length();
        auto getLen = [&](int l,int r){
            while( l>=0 && r <= n && str[l] == str[r]){
                --l;
                ++r;
            }
            return r-l-1; // 注意此处
        };
        int len = 0;
        int start = 0;
        for(int i=0;i<n;i++){
            int cur = max(getLen(i,i),getLen(i,i+1)); // 两种类型，长度为奇数或者偶数
            if(cur>len){
                len = cur;
                start = i - (len-1)/2; //注意start的计算
            }
        }
        return str.substr(start,len);
    }
};