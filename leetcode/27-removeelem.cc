/*
解题思路：从左开始找等于val的元素，从右开始找不等于val的元素，交换
	right 相当于右游标,保证右游标·
坑在于：注意left与right的边界，返回的是数组的长度·
*/

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int left = 0;
        int right = len;
    
        while(left < right) {
            while(left < right && nums[left] != val) {
                    left++;
            }
            while(left < right && nums[right-1] == val) {
                    right--;
            }
            if(left < right){
                nums[left] = nums[right-1];
                nums[right-1] = val;
            }
        }
        return left;
    }
};

int main(){

}
