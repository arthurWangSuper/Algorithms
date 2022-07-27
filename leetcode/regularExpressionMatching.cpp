// leetcode-10 Regular Expression Matching 
// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
// '.' Matches any single character
// '*' Matches zero or more of the preceding element. * must behind a character

// 解题思路：
// preceding + '*' 有可能匹配 0个，1个，2个

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Solution{
public:
    bool isMatch(string s, string p){
        size_t slen = s.size();
        size_t plen = p.size();
        auto matches = [&](int i, int j) {
            if(i == 0) {
                return false;
            } else if(p[j-1] == '.'){
                return true;
            }
            return s[i-1] == p[j-1];
        };

        vector<vector<int>> dp = vector<vector<int>>(slen+1,vector<int>(plen+1));
        dp[0][0] = true; // empty string is matching
        for(int i = 0; i <= slen; i++){
            for(int j = 1; j <= plen; j++) { // because * must behind a character so loop is begin from 1 
                if(p[j] == '*'){
                    dp[i][j] |= dp[i][j-2]; // zero match
                    if(matches(i,j-1)){     // match first char
                        dp[i][j] = dp[i-1][j];
                    }
                } else {
                    if(matches(i,j)){
                        dp[i][j] |= dp[i-1][j-1];
                    }
                }
            }
        }
        return dp[slen][plen];

    }
};

int main(int argc, char **argv){
    string s = argv[1];
    string p = argv[2];

    Solution *pS = new Solution();
    bool ret = pS->isMatch(s,p);
    std::cout<<"s: "<<s<<" p: "<<p<<" ret: "<<ret<<endl;
    return 0;
}