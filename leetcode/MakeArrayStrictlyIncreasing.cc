// leetcode 1187
// Given two integer arrays arr1 and arr2, 
// return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
// In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
// If there is no way to make arr1 strictly increasing, return -1.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int makeArrayIncreasing(vector<int>& a,vector<int>& c){
        constexpr int kInf = 1e9;
        int m = a.size();
        // sort b and make it unique
        sort(c.begin(),c.end());
        vector<int> b;
        for(int i=0;i<c.size();++i){
            if(!b.empty()&&c[i]==b.back()) continue;
                b.push_back(c[i]);
        }
        int n = b.size();

        vector<int> keep(m,kInf);
        keep[0]=0;
        // swap[i][j] := min steps to make a[0~i] valid by a[i] = b[j]
        vector<int> swap(n,1);
        for(int i = 0;i < n;++i){
            int min_keep = kInf;
            int min_swap = kInf;

            vector<int> temp(n,kInf);
            for(int j=0;j<n;j++){
                //case 4
                if(j>0) min_swap = min(min_swap,swap[j-1]+1);

                if(a[i] > b[j]) min_keep = min(min_keep,swap[j]);//保留或者是换
                if(a[i] > a[i-1]) keep[i] = keep[i-1];
                if(b[j] > a[i-1]) temp[j] = keep[i-1]+1;
                
                temp[j] = min(temp[j],min_swap);
                keep[i] = min(keep[i],min_keep);
            }
            temp.swap(swap);
        }
        //最后一个元素保留和交换的最小值
        int s = *min_element(begin(swap),end(swap));
        int k = keep.back();
        int ans = min(s,k);
        return ans >= kInf ? -1:ans;
    }
};