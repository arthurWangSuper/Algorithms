#include <iostream>
#include <string>

using namespace std;

class Solution{

	public:
		string strPlus(string& num1,string& num2){
			if(num1.size()==0) return num2;
			if(num2.size()==0) return num1;

			if(num1.size()<num2.size()){
				swap(num1,num2);
			}

			string s;

			int carry = 0;
			int x;

			for(int i=num1.size()-1,j=num2.size()-1;i>=0;i--,j--){
			x = num1[i]-'0'+carry;

			if(j>=0){
				x += num2[j]-'0';
			}
			s.insert(s.begin(),x%10+'0');
			carry = x/10;
			}
			if(carry>0){
				s.insert(s.begin(),carry+'0');
			}
			return s;
		}
		string multiply(string num1,string num2)
		{
			if(num1.size()<=0||num2.size()<=0) return "";
			
			string result;

			for(int i=num1.size()-1;i>=0;i--){
				int carry = 0;
				string val;
				
				for(int j=num2.size()-1;j>=0;j--){
				int v = (num2[j]-'0')*(num1[i]-'0')+carry;
				val.insert(val.begin(),v%10+'0');
				carry = v/10;
				}
				if(carry) val.insert(val.begin(),carry+'0');
				for(unsigned int j=i;j<num1.size()-1;j++){
					val.push_back('0');
				}

				result = strPlus(result,val);
			}
			
			if(result[0]=='0') return "0";
			
			return result;

		}
};

int main(int argc,char *argv[]){
	string s1="20";
	string s2="25";
	
	Solution *ps = new Solution();
	if(argc>2)
	{
		s1=argv[1];
		s2=argv[2];
	}

	cout <<s1<<"*"<<s2<<" = " <<ps->multiply(s1,s2)<<endl;


}
