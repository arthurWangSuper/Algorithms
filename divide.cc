#include <iostream>
#include <cstdio>

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag = true;
        int dividendflag = 1;
        int divisorgflag = 1;
        // 先累加   
        int sum =  0;
        int ret = 0;
        int add = 0;
        int retadd = 1;
        if(divisor == INT_MIN && divisor != dividend){
            return 0;
        } else if(divisor == dividend) {
            return 1;
        }

        if(divisor < 0){
            divisorgflag = 0;
            divisor = -divisor;
        } 
        if(dividend < 0){
            dividendflag = 0;
            if(dividend != INT_MIN){
                dividend = -dividend;
            } else {
                dividend = dividend + divisor;
                dividend = -dividend;
                ret = 1;
            }
        }
        add = divisor;
        flag = divisorgflag^dividendflag;
        while(1){
            if(sum < dividend){
                // 处理溢出
                if(INT_MAX - ret < retadd){
                    ret = INT_MAX;
                    break;
                }
                // 处理溢出
                if(INT_MAX - sum < add || INT_MAX - add < add) {
                    add = divisor;
                    retadd = 1;
                } else {
                    // 下一次要加的
                    add = add+add;
                    retadd = retadd+retadd;
                    ret = ret + retadd;
                    sum = sum+add;
                }
            } else if(sum == dividend){
                break;
            } else if(sum - divisor < dividend){
                ret -= 1;
                break;
            } else {
                sum = sum - add;
                add = divisor;
                ret = ret - retadd;
                retadd = 1;
            }
        }
        if(flag) {
            ret = -ret;
        }
        return ret;
    }
};
