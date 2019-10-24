//leetcode 1201. Ugly Number III
// Write a program to find the n-th ugly number.
// Ugly numbers are positive integers which are divisible by a or b or c.
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>

using namespace std;
//最小公倍数，先用辗转相除法求得公约数
int lcm(int valA,int valB){
    int a = valA;
    int b = valB;
    if(valA<valB){
        swap(valA,valB);
    }
    while(valA%valB){
        valA = valA%valB;
        swap(valA,valB);
    }
    return a/valB*b;//先除再乘 防止溢出
}
class Solution{
public:
    int nthUglyNumber(int n,long a,long b,long c){
        long l = 1;
        long r = 2*10e9;
        long ab = lcm(a,b);
        long ac = lcm(a,c);
        long bc = lcm(b,c);
        long abc = lcm(a,bc);
        while(l<r){
            long m = l+(r-l)/2;
            long k = m/a+m/b+m/c-m/ab-m/bc-m/ac+m/abc;
            //这种写法保证了最后得到的是nth number，其正好是n，比起小的都是包含n-1
            if(k >= n) r=m;
            else l=m+1;
        }
        return l;
    }
};

int main(){
    Solution sol;
    //cout<<sol.nthUglyNumber(1000000000,2,217983653,336916467)<<endl;
    cout<<sol.nthUglyNumber(5,2,11,13)<<endl;
}