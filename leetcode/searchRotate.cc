#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int bSearch(vector<int>& nums, int left, int right,int target){
        int ret = -1;
        while(left <= right){
            int pos = (left+right)/2;
            int num = nums[pos];
            if(num == target) {
                ret= pos;
                break;
            } else if(num > target) {
                right = pos -1;
            } else {
                left = pos +1;
            }
        }
        return ret;
    }
    int search(vector<int>& nums, int target) {
        // find the index
        size_t len = nums.size();
        int pos = len-1;
        for(int i= 0; i< len-1;i++){
            if(nums[i] > nums[i+1]){
                pos = i;
                break;
            }
        }
        int left = 0;
        int right = len-1;

        if(nums[0] <= target) {
            right = pos;
        } else if(nums[len-1] >= target) {
            left = pos +1;
        } else {
            return -1;
        }
        printf("pos = %d, left = %d, right = %d\n", pos, left, right);
        return bSearch(nums, left,right,target);
    }
    int search2(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        int ret = -1;
        while(left <= right){
           
            int pos = (left+right)/2;
            int num = nums[pos];
            printf("pos = %d, num = %d, left = %d, right = %d\n", pos, num, left,right);
            if(num == target) {
                ret= pos;
                break;
            } else if(num > target) {
                // 如果num比目标大，按理应该是向左继续搜索
                if(nums[right] < nums[pos] && nums[right] >= target) {
                    // 判断是否落在右半区
                    left = pos+1;
                } else {
                    right = pos-1;
                }
            } else {
                // 向右边搜索
                if(nums[left] > nums[pos] && target >= nums[left]){
                    // 看看是不是落在左半区
                    right = pos-1;
                } else {
                    left = pos+1;
                }
            }
        }
        return ret;
    }
};

int main(){
    vector<int> ivec = {4,5,6,7,8,1,2,3};
    int target = 8;
    Solution *pS = new Solution();
    int pos = pS->search2(ivec,target);
    printf("pos is %d\n",pos);
}