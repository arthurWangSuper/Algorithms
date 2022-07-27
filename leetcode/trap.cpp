/*接雨水*/

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(len <= 2) {
            return 0;
        }
        int sum = 0;
        int min = 0, max = 0;
        for(int i = 1; i < len; i++ ){
            max = i;
            if(height[max] >= height[min]){
                for(int j = min+1;j <max;j++){
                    sum += height[min]-height[j]; 
                }
                min = i;
            } 
        }
        min = len-1;
        for(int i = len-2; i >= 0; i-- ){
            max = i;
            if(height[max] > height[min]){
                for(int j = min-1;j > max;j--){
                    sum += height[min]-height[j]; 
                }
                min = i;
            } 
        }
        return sum;
    }
};

int main(){
    vector<int> ivec = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> ivec2 = {4,2,0,3,2,5};
    Solution *pS = new Solution();
    int sum = pS->trap(ivec);
    int sum2 = pS->trap(ivec2);
    printf("sum is %d sum2 is %d\n",sum, sum2);
}