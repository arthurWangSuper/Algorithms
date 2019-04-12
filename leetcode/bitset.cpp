#include <iostream>

using namespace std;

int add(int a,int b)
{
    int Xor = 0;
    int Add = 0;
    do {
        Xor = a^b;
        Add = (a&b)<<1;
        a = Xor;
        b = Add;
    }while(Add != 0);

    return a;
}
int multi(int a,int b)
{
    int res = 0;
    while(b!=0)
    {
        if((b&1) == 1)
        {
            res = add(res,a);
        }
        a<<=1;
        b>>=1;
    }
    return res;
}

bool isNeg(int val)
{
    return val<0;
}
int negnum(int num)
{
    return add(~num,1);
}
int minus(int a,int b)
{
    return add(a,negnum(b));
}

int div(int a,int b)
{
    int x = isNeg(a)?negnum(a):a;
    int y = isNeg(b)?negnum(b):b;

    int res = 0;

    for(int i =31;i>-1;i=minus(i,1))
    {
        if((x>>i) >= y){
            res |= (1<<i);
            x = minus(x,y<<i);
        }
    }
    return isNeg(a)^isNeg(b)?negnum(res):res;
}
 int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == INT_MIN)
        return 1;
    else if(divisor == INT_MIN)
        return 0;
    else if(dividend == INT_MIN){
        int res = (dividend+1)/divisor;      
        return add(res,div(minus(dividend,multi(res,divisor)),divisor));
    }
    else 
        return div(dividend,divisor);   
}

int main(int argc,char**argv)
{
    cout<<"add is:"<<add(99,65)<<endl;
    cout<<"minus is:"<<minus(99,65)<<endl;
    cout<<"mul is:"<<multi(100,4)<<endl;
    cout<<"div is:"<<divide(10,3)<<endl;
    return 0;
}
