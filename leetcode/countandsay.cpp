#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

class Solution {
public:
    string countAndSay(int n) {
        string ret = org;
        stringstream ss;
        for(int i = n; i > 1; i--) {
            char ch = ret[0];
            int cnt = 0;
            for(auto& elem:ret){
                if(ch == elem){
                    cnt++;
                } else {
                    ss<<cnt;
                    ss<<ch;
                    cnt = 1;
                    ch = elem;
                }
            }
            ss << cnt;
            ss << ch;
            ret = ss.str();

            printf("ret = %s\n",ret.c_str());
            ss.str("");
        }
        return ret;
    }
private:
    string org = "1";
};

int main(){
    Solution* pS = new Solution();
    string str = pS->countAndSay(4);
    cout<<"ret: "<<str<<endl;
}