/*given s1,s2,s3,find whether s3 is formed by the interleaving of s1 and s2*/

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
//      d b b c a      
//	  1 0 0 0 0	0
//	a 1
//  a 1
//  b 0
//  c 0
//  c 0
// match[i][j] s1-i s2-j match s3-i+j
//Dynamic Programming
bool isInterleave(string s1,string s2,string s3)
{

	if(s1.size()+s2.size() != s3.size())
	{
		return false;
	}
	//注意其大小
	vector<vector<int>> match(s1.size()+1,vector<int>(s2.size()+1,false));

	match[0][0] = true;
	//初始化 第0行，第0列
	for(int i=1;i<=s1.size();i++){
		if(s1[i-1]==s3[i-1]){
			match[i][0] = true;
		}
		else{
			break;
		}
	}
	
	for(int i=1;i<=s2.size();i++){
		if(s2[i-1] == s3[i-1]){
			match[0][i] = true;
		}
		else{
			break;
		}
	}

	for(int i=1;i<=s1.size();i++){
		for(int j=1;j<=s2.size();j++){
			if(s1[i-1] == s3[i+j-1]){
				match[i][j] = match[i-1][j]||match[i][j];
			}
			if(s2[j-1] == s3[i+j-1]){
				match[i][j] = match[i][j-1]||match[i][j];
			}
		}
	}
	return match[s1.size()][s2.size()];
}


#define TEST(s1,s2,s3) cout<<s1<<","<<s2<<":"<<isInterleave(s1,s2,s3)<<endl;

int main()
{
	string s1 = "aabcc",s2 = "dbbca";

	TEST(s1,s2,"aadbbcbcac");
	TEST(s1,s2,"aadbbbaccc");

	return 0;
}
