#include <cstdio>

bool g_Invalid = false;

bool equal(double num1,double num2);
double PowerWithUnsignedExponent(double base, unsigned int exp);

double Power(double base, int exp){
	g_Invalid = false;
	if(equal(base, 0.0)&&exp<0)
	{
		g_Invalid = true;
		return 0;
	}
	int absExp = 0 ;	
	if(exp < 0)
		absExp = (unsigned int)(-exp);
	else 
		absExp = (unsigned int)(exp);
	
	double res = PowerWithUnsignedExponent(base, absExp);
	
	if(exp < 0)
		res = 1.0/res;
	return res;
}

double PowerWithUnsignedExponent(double base, unsigned int exp){
	if( exp == 0)
		return 1;
	if( exp == 1)
		return base;
	double res = PowerWithUnsignedExponent(base, exp >> 1);
	
	res *= res;
	//处理exp为奇数or偶数的问题
	if((exp & 0x1) == 1)
		res *= base;
	
	return res;
}

bool equal(double num1,double num2){
	if(num1-num2 > -0.0000001 && num1-num2 < 0.0000001 )
		return true;
	else
		return false;

}

int main(int argc, char *argv[]){
	printf("%f\n",Power(10,3));
	return 0;
}
