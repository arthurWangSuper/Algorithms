/*************************/
// find next permutation //
/*************************/

#include <cstdio>
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        size_t len = nums.size();
        int pos = -1;
        // find the last elem where nums[i] smaller than nums[i+1]
        for(int i = 0;i< len-1; i++) {
            if(nums[i] < nums[i+1]) {
                pos = i;
            }
        }
        // find min
        int pos_end = pos+1;
        int target = nums[pos_end];
        for(int i = pos+1; i < len; i++) {
            if(nums[i] > nums[pos]) {
                if(nums[i] <= target)
                {
                    target = nums[i];
                    pos_end = i;
                }
            }
        }

        // swap
        if(pos >= 0) {
            int tmp = 0;
            tmp = nums[pos];
            nums[pos] = nums[pos_end];
            nums[pos_end] = tmp;
        }
        std::sort(nums.begin()+pos+1, nums.end());
    }
};

int main(){
    vector<int> ivec = {3,2,1};
    Solution *pS = new Solution();
    pS->nextPermutation(ivec);
    for(auto &elem:ivec) {
        printf("%d,", elem);
    }
    printf("\n");
}