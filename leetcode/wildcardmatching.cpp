#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
// meet * need process
// meet ? we must need a char to match
class Solution {
public:
    bool isMatch(string s, string p){
        size_t slen = s.length();
        size_t plen = p.length();
        int ps = 0;
        int pp = 0;
        while( ps < slen && pp < plen ){
            if(s[ps] == s[pp]){
                ps ++;
                pp ++;
            }
        }
    }
};