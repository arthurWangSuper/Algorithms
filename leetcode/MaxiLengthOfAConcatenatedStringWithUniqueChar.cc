#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution{
public:
    int maxiLength(vector<string>& arr){
        vector<int> a;

        for(const string& x:arr)
        {
            int mask = 0;
            for(char c:x) mask |= 1<<(c-'a');
            if(__builtin_popcount(mask) != x.length()) continue;
            a.push_back(mask);
        }

        int ans = 0;
        
        function<void(int,int)> dfs = [&](int s,int mask){
            ans = max(ans,__builtin_popcount(mask));
            for(int i = 0;i<a.size();++i)
                if((mask&a[i]) == 0)
                    dfs(i+1,mask|a[i]);
        };
        dfs(0,0);
        return ans;
    }
};