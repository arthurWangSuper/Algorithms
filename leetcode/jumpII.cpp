#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int jump(vector<int>& nums) {
        size_t len = nums.size();
        int sum = 0;
        for(int i = 0; i < len;) {
            int num = nums[i];
            int step = 0;
            int next_pos = 0;
            for(int j =1; j <= num && i+j < len; j++){
                if(nums[i+j] > step){
                    step = nums[i+j];
                    next_pos = i+j;
                }
            }
            if(step > 0){
                i = next_pos;
                sum++;
                if(next_pos == len-1) {
                    break;
                }
            } else {
                return 0;
            }
        }
        return sum;
    }
};