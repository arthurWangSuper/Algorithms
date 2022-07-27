#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::reverse;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ivec;
        string ret;
        for(int i = 0; i < num1.size(); i++){
            int a = num1[i] - '0';
            for(int j =0 ; j < num2.size(); j++){
                int b = num2[j] - '0';
                if(i+j+1 > ivec.size()){
                    ivec.push_back(0);
                }
                int ret = a * b;
                ivec[i+j] += ret;  
            }
        }
        // need to reverse the vector
        reverse(ivec.begin(),ivec.end());

        for(int i = 0; i < ivec.size(); i++){
            if(ivec[i] > 9) {
                if(i+1 == ivec.size()){
                    ivec.push_back(ivec[i]/10);
                } else {
                    ivec[i+1] += ivec[i]/10;
                }
            }
            ivec[i] = ivec[i]%10;
        }

        for(int i = ivec.size()-1;i >=0; i--){
            char ch = ivec[i] + '0';
            ret.push_back(ch);
        }
        int pos = 0;
        for(auto elem:ret){
            if(elem == '0'){
                pos++;
            } else {
                break;
            }
        }
        ret = ret.substr(pos);
        if(ret.length() == 0){
            ret = "0";
        }
        return ret;
    }
};


int main(int argc, char **argv){
    string a,b;
    if(argc > 2) { 
        a = argv[1];
        b = argv[2];
    }
    Solution *pS = new Solution();
    cout << pS->multiply(a, b) << endl;
    return 0;
}