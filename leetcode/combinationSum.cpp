#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using std::vector;
using std::function;
using std::sort;
using std::cout;
using std::endl;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        sort(candidates.begin(),candidates.end());
        size_t len = candidates.size();
        function<void(vector<int>,int,int)> func = [&](vector<int> ivec, int pos, int rev) {
            if(pos == len) {
                return;
            }
            //cout<<pos<<" "<<rev<<endl;
            for(int i = pos; i < len; i++){
                if(candidates[i] == rev) {
                    ivec.push_back(candidates[i]);
                    ret.push_back(ivec);
                } else if(candidates[i] < rev) {
                    ivec.push_back(candidates[i]);
                    func(ivec,i,rev - candidates[i]);
                    ivec.pop_back();
                } else {
                    return;
                }
            }
        };
        vector<int> tmp;
        func(tmp,0,target);
        return ret;
    }
    vector<vector<int>> combinationSumII(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        sort(candidates.begin(),candidates.end());
        size_t len = candidates.size();
        function<void(vector<int>,int,int)> func = [&](vector<int> ivec, int pos, int rev) {
            if(pos >= len) {
                return;
            }
            for(int i = pos; i < len; i++){
                // 广度遍历时去重，深度遍历时不去重
                if((i>0 && candidates[i]== candidates[i-1])&& i!=pos ){
                    continue;
                }
                if(candidates[i] == rev) {
                    ivec.push_back(candidates[i]);
                    ret.push_back(ivec);
                } else if(candidates[i] < rev) {
                    ivec.push_back(candidates[i]);
                    // skip same elem
                    int next = i+1;
                    func(ivec,next,rev - candidates[i]);
                    ivec.pop_back();
                } else {
                    return;
                }
            }
        };
        vector<int> tmp;
        func(tmp,0,target);
        return ret;
    }
};

int main(){
    vector<int> candidates{2,5,2,1,2};
    int target = 5;
    Solution* pS = new Solution();
    vector<vector<int>> res = pS->combinationSumII(candidates,target);
    for(auto& vec:res){
        for(auto& elem:vec) {
            cout<<elem<<" ";
        }
        cout<<endl;
    }
}