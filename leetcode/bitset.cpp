#include <iostream>

using namespace std;

int bitadd(int a,int b)
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
int bitmul(int a,int b)
{
    int res = 0;
    while(b!=0)
    {
        if((b&1) == 1)
        {
            res = bitadd(res,a);
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
    return bitadd(~num,1);
}
int bitminus(int a,int b)
{
    return bitadd(a,negnum(b));
}

int bitdiv(int a,int b)
{
    int x = isNeg(a)?negnum(a):a;
    int y = isNeg(b)?negnum(b):b;

    int res = 0;

    for(int i =31;i>-1;i=bitminus(i,1))
    {
        if((x>>i) >= y){
            res |= (1<<i);
            x = bitminus(x,y<<i);
        }
    }
    return isNeg(a)^isNeg(b)?negnum(res):res;
}

int main(int argc,char**argv)
{
    cout<<"add is:"<<bitadd(99,65)<<endl;
    cout<<"minus is:"<<bitminus(99,65)<<endl;
    cout<<"mul is:"<<bitmul(100,4)<<endl;
    cout<<"div is:"<<bitdiv(100,4)<<endl;
    return 0;
}
