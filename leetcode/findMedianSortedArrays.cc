//leetcode 4

//Problem:

//There are two sorted arrays nums1 and nums2 of size m and n respectively.

//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).


#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2)
    {
        const int n1 = nums1.size();
        const int n2 = nums2.size();

        //Make sure n1<=n2 在小的数组上二分
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);

        const int k = (n1+n2+1)/2;
        int l = 0;
        int r = n1;

        while(l < r){
            //左侧用多少元素：m1
            //右侧用多少元素：m2
            const int m1 = l+(r-1)/2;
            const int m2 = k - m1;
            //二分法
            if(nums1[m1] < nums2[m2-1]){
                l = m1+1;
            }else
            {
                r = m1;
            }
        }
        
        const int m1 = l;
        const int m2 = k-1;  
        //处理边界条件
        const int c1 = max(m1<=0 ? INT_MIN:nums1[m1-1],
                            m2<=0 ? INT_MIN:nums2[m2-1]);

        if((n1+n2)%2 == 1) return c1;

        const int c2 = min(m1>=n1 ? INT_MAX:nums1[m1],
                            m2>=n2 ? INT_MAX:nums2[m2]);

        return (c1+c2)*0.5;
    }
};
