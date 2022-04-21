// Leetcode 1371 Find Longest Substring Containing Vowels In Even Counts
// Vowels = ['a', 'e', 'i', 'o', 'u']

// 思路：建立 类似于位图的东西 5位2进制，
// 利用hash_map state->当前索引号，两次出现一致状态相减即可，表示从奇变偶了

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;

class Solution{
public:
    int findTheLongestSubstring(string s){
        const char *vowels = "aeiou";
        vector<int> idx(1<<5, INT_MAX);
        idx[0] = -1;
        int state = 0;
        int ans = 0;

        for(int i = 0;i < s.length();++i){
            for(int j=0; j < 5; ++j)
                if(s[i] == vowels[j]) state ^= 1<<j;
            if(idx[state] == INT_MAX) idx[state] = i;
            ans = max(ans, i-idx[state]);
        }
        return ans;
    }
};