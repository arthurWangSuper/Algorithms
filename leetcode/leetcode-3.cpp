#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b

int longestsubstring(string str)
{
	int map[256];
	int pre = -1;
	int len = 0;
	int cur = 0;
	for(int i = 0;i<256;i++)
	{
		map[i]=-1;
	}
	for(int j = 0;j<str.length();j++)
	{
		pre = max(map[str[j]],pre);
		cur = j-pre;
		len = max(len,cur);
		map[str[j]]=j;
	}
	return len;
}
int main()
{
	string str = "abcabcdea";
	int lens =0;
	lens=longestsubstring(str);
	cout<<lens<<endl;
	return 0;
}
