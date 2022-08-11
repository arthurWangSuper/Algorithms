#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    vector<vector<int>> permute1(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        size_t len = nums.size();
        ret.push_back(nums);

        auto nextPermute = [len](vector<int> elem){
                // find the next
                int pos = -1;
                for(int i = 0; i < len-1; i++) {
                    if(elem[i] < elem[i+1]){
                        pos = i;
                    }
                }
                // find the smallest (i, npos)
                if(pos == -1) {
                        return vector<int>();
                } else {
                        int minpos = pos+1;
                        int min = elem[pos+1];
                        for(int i = pos+1; i < len; i++){
                                if(elem[i] < min && elem[i] > elem[pos]){
                                        minpos = i;
                                        min = elem[i];
                                }
                        }
                        // swap
                        std::swap(elem[pos], elem[minpos]);
                        std::sort(elem.begin()+pos+1,elem.end());
                }
                return elem;
        };
        while(true){
                    vector<int> next = nextPermute(nums);
                    if(!next.size()){
                        break;
                    }
                ret.push_back(next);
                nums.swap(next);
                vector<int>().swap(next);
        }

        return ret;
    }

    vector<vector<int>> permute(vector<int>& nums) { 
        vector<vector<int>> ret;
        backstrace(nums, 0, ret);
        return ret;
    } 

    vector<vector<int>> permuteUniq(vector<int>& nums) { 
        vector<vector<int>> ret;
        vector<int> perm;
        sort(nums.begin(), nums.end());
        vector<int> vis;
        vis.resize(nums.size());
        backstraceUnique(nums, vis, perm, ret, nums.size());
        return ret;
    } 

private:
     void backstrace(vector<int> nums, int first, vector<vector<int>>& ret){
        int len = nums.size();
        if(first == len -1){
            ret.push_back(nums);
        }
        for(int i = first; i < len ; i++){
            // i 从 first而不是first+1
            std::swap(nums[i], nums[first]);
            backstrace(nums, first+1, ret);
            std::swap(nums[first], nums[i]);
        }
    } 
    void backstraceUnique(vector<int>& nums, vector<int>& vis, vector<int>& perm, vector<vector<int>>& ret, int len){
        
        if(perm.size() == len){
            ret.push_back(perm);
        }

        for(int i = 0; i < len ; i++){
            // 第二个条件，保证相同字符相对顺序不会变化
            if(vis[i] || (i > 0 && nums[i-1] == nums[i] && !vis[i-1])){
                continue;
            }
            perm.push_back(nums[i]);
            vis[i] = 1;
            backstraceUnique(nums, vis,perm, ret, len);
            vis[i] = 0;
            perm.pop_back();
        }
    } 
};

int main(int argc, char** argv){
    vector<int> ivec{1,1,1,2};
    Solution *pS = new Solution();
    vector<vector<int>> ret = pS->permuteUniq(ivec);
    for(auto& vec:ret){
        for(auto& elem:vec){
            printf("%d ",elem);
        }
        printf("\n");
    }
    return 0;
}