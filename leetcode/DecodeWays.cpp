//leetcode 91

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

//DP
//if isValid s[i] isValid s[i-1]s[i] return 0;
// dp[i] = dp[i-1] if isValid s[i]
// dp[i] = dp[i-2]+dp[i-1] if isValid s[i]s[i-1]
class Solution1{
public:
    int numDecodings(string s){
        if(s.empty()||s[0]=='0')
            return 0;
        if(s.length()==1) 
            return 1;

        const int n = s.length();
        int w1 = 1;
        int w2 = 1;

        for(int i=1;i<n;++i){
            int w = 0;
            if(!isValid(s[i])&&!isValid(s[i-1],s[i])) return 0;
            if(isValid(s[i])) w=w1;
            if(isValid(s[i-1],s[i])) w +=w2;
            w2=w1;
            w1=w;
        }
        return w1;
    }
private:
    bool isValid(const char c) {return c!=0;}
    bool isValid(const char c1,const char c2)
    {
        const int num = (c1-'0')*10+(c2-'0');
        return num>=10&&num<=26;
    }
};
//recusive
class Solution2{
public:
    int numDecodings(string s){
        if(s.length()==0) return 0;
        m_ways[" "] =1;

        return ways(s);
    }
private:
    int ways(const string &s){
        if(m_ways.count(s)) return m_ways[s];
        if(s[0]=='0') return 0;
        if(s.length()==1) return 1;

        int w = ways(s.substr(1));
        const int prefix = stoi(s.substr(0,2));
        if(prefix<=26)
            w += ways(s.substr(2));
        m_ways[s] = w;
        return w;
    }
    unordered_map<string,int> m_ways;
};

int main()
{
    string str = "10122203";
    Solution1 *pS1=new Solution1();
    Solution2 *pS2=new Solution2();

    cout<<"pS1 solution: "<<pS1->numDecodings(str)<<endl;
    cout<<"pS2 solution: "<<pS2->numDecodings(str)<<endl;

    return 0;
}