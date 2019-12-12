// leetcode: 1283 Find the Smallest Divisor Given a Threshold
// Created by k on 19-12-12.

//  Given an array of integers nums and an integer threshold, 
//  we will choose a positive integer divisor and divide all the array by it and sum the result of the division. 
//  Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
//  Each result of division is rounded to the nearest integer greater than or equal to that element. 
//  (For example: 7/3 = 3 and 10/2 = 5). It is guaranteed that there will be an answer.

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        auto calc = [&](int divisor){
            int sum = 0;

            for(auto num:nums)
                sum += num%divisor?num/divisor+1:num/divisor;
            return sum;
        };

        sort(nums.begin(),nums.end());
        size_t length = nums.size();
        int divisor = nums[length-1];
        int min = 0;
        int max = nums[length-1];
        // 注意停止条件以及上下边界的调整
        while(min<max){
            if(calc(divisor)>threshold)
            {
                min = divisor+1;
            }
            else if(calc(divisor)<threshold){
                max = divisor;
            }
            else{
                return divisor;
            }
            divisor = (min+max)/2;
        }
        return divisor;
    }
};

int main(){

    Solution *pS = new Solution();

    vector<int> ivec = {1,2,5,9};

    cout<<pS->smallestDivisor(ivec,6)<<endl;

    return 0;
}
