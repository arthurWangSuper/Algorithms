//Leetcode 1395 
#include <iostream>
#include <vector>

using namespace std;
// brute force
class Solution{
public:
    int numTeams(vector<int> &rating){
        size_t n = rating.size();
        int ans = 0;

        for(int i = 0;i<n;i++)
            for(int j=i;j<n;j++)
                for(int k=j;k<n;k++)
                    if(rating[i] < rating[j] && rating[j] <rating[j] ||
                        rating[i] > rating[j] && rating[j] > rating[j])
                            ++ans;
        return ans;
    }
};

// Math
// for a soldier j, there are l people on his left side has smaller ratings 
// and there are r people on his right side has greater ratings.Then for j 
// in the middle, there are 
// l*r tulpes s.t i < j <k
// (l*r) + (j-l)*(n-r-l-1) tuples s.t. i > j > k

class Solution{
public:
    int numTeams(vector<int> &rating){
        size_t n = rating.size();
        int ans = 0;
        
        for(int j = 0;j < n; ++j){
            int l = 0;
            int r = 0;
            for(int i = 0; i < j; i++)
            {
                if(rating[i] < rating[j]) ++l;
            }
            for(int k = j+1; k < n; k++)
            {
                if(rating[j] < rating[k]) ++l;
            }
            ans += (l*r) + (j-l)*(n-r-l-1);
        }
    }
};