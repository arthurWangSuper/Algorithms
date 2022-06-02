#include <cstdio>

long long StrToIntCore(const char* str, bool minus);

enum Status {kValid = 0,kInValid};
int g_nStatus = kValid;

int StrToInt(const char* str){
	// 是否为正常的字符串	
	g_nStatus = kValid;
	long long num = 0;
	
	if(str != nullptr && *str != '\0'){
		bool minus = false;
		if(*str == '+'){
			str++;			
		}else if(*str == '-'){
			str++;
			minus = true;		
		}

		if(*str != '\0')
		{
			num = StrToIntCore(str, minus);
		}
		return (int)num;
	}
}

long long StrToIntCore(const char* str, bool minus){
	long long num = 0;
	
	while(*digit != '\0'){
		if(*digit >= '0' && *digit <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');
			// 正常值的范围
			if((!minus && num > 0x7fffffff)||(minus && num < (signed int) 0x80000000))
			{
				num = 0;
				break;
			}
			digit++;
		}
		else{
			num = 0;
			break;
		}
	}
	if(*digit == '\0')
		g_nStatus = kValid;
	return num;
}
