// Leetcode 1191 k-concatenation Maximum Sum

// Given an integer array arr and an integer k, modify the array by repeating it k times.
// For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].
// Return the maximum sub-array sum in the modified array. 
//Note that the length of the sub-array can be 0 and its sum in that case is 0.
// As the answer can be very large, return the answer modulo 10^9 + 7

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int kConcatenationMaxSum(vector<int> &arr,int k){
        constexpr int kMod = 1e9+7;

        auto maxSum = [&arr](int r){
            long sum = 0;
            long ans = 0;
            for(int i=0;i<r;++i){
                for(long a:arr){
                    sum = max(0L,sum += a);
                    ans = max(ans, sum);
                }
            }
            return ans;
        };
        if(k < 3) return maxSum(k)%kMod;
        long sum = accumulate(begin(arr),end(arr),0L);
        long ans1 = maxSum(1);
        long ans2 = maxSum(2);

        return max(ans1,ans2+sum*(k-2),ans2)%kMod;    
    }
};