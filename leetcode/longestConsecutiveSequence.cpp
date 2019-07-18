//Given an unsorted array of integers,find the length of the longest consecutive elements sequence
//Your algotithm should run in O(n) complexity ===Hashtable or Hashset

#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

//记录每个节点和相邻节点 最后进行计算
class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        unordered_map<int,int> h;

        int ans = 0;

        for(int num:nums){
            //解决重复问题
            if(h.count(num)) continue;

            auto it_l = h.find(num-1);
            auto it_r = h.find(num+1);

            int l = it_l != h.end()?it_l->second:0;
            int r = it_r != h.end()?it_r->second:0;
            int t = l+r+1;

            h[num] = h[num-l] = h[num+r] = t;
            ans = std::max(ans,t);
        }
        return ans;
    }
};
class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        unordered_set<int> h(nums.begin(),nums.end());
        int ans =0;

        for(int num:nums){
            if(!h.count(num-1)){
                int l=0;
                while(h.count(num++)) ++i;
                ans = max(ans,1);
            }
        }
        return ans;
    }
};

int main()
{
     vector<int> ivec{1,3,4,5,6,7,3,9,11};
     Solution *pSo = new Solution;
     cout<<"length is: "<<pSo->longestConsecutive(ivec)<<endl;
    return 0;
}
