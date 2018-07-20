#include<iostream>
#include<vector>
using namespace std;


int getverNum(string str,vector<int> &strvec,vector<char> &suffixvec)
{
         int i = 0;
        int num = 0;
        int sum = 0;
        int size = 0;

        while(str[i] != '\0')
        {
                if(str[i] != '.')
                {
                        if((str[i]>='0')&&(str[i]<='9'))
                        {
                                num = str[i]-'0';
                                sum*=10;
                                sum+=num;
                        }
                        else
                        {
				
				/*只是考虑简答的后缀 a b c的情况*/
				/*如果迭代版本为其他形式如base等字符串，可以用map实现*/
                                suffixvec.push_back(str[i]-'A');
                        }
                }
                else
                {

                        strvec.push_back(sum);
                        sum = 0;
                }
                i++;
        }
        strvec.push_back(sum);
        for(i=0;i<strvec.size();i++)
        {
                cout<<strvec[i]<<' ';
        }
        cout<<endl;
        for(i=0;i<suffixvec.size();i++)
        {
                cout<<suffixvec[i];
        }
        cout<<endl;
        return 0;
}

int comparever(string strA,string strB)
{
	vector<int> strvecA;
	vector<char> suffixvecA;
	vector<int> strvecB;
	vector<char> suffixvecB;	

	getverNum(strA,strvecA,suffixvecA);
	getverNum(strB,strvecB,suffixvecB);
	
	/*比较长度*/
	if(strvecA.size()>strvecB.size())
	{
		return 1;
	}
	else if(strvecA.size()<strvecB.size())
	{
		return -1;
	}
	/*长度相同的情况*/
	for(int i =0;i<strvecA.size();i++)
	{
		if(strvecA[i]>strvecB[i])
		{
			return 1;
		}
		else if(strvecA[i]<strvecB[i])
		{
			return -1;
		}
	}
	if(suffixvecA.size()>suffixvecB.size())
        {
                return 1;
        }
        else if(suffixvecA.size()<suffixvecB.size())
        {
                return -1;
        }	
	
	if(suffixvecA.size()==suffixvecB.size())
	{
		return 0;
	}	
	if(suffixvecA[0]>suffixvecB[0])
	{
		return 1;
	}
	else if(suffixvecA[0]<suffixvecB[0])
	{
		return -1;
	}
	else
	{
		return 0;
	}

	return 0;
}

int main()
{
		
		string strA ="1.1.12";
		string strB ="1.1.12";
		
		
		int retflag = comparever(strA,strB);
		
		if(retflag == 1)
		{
			cout<<"result:A"<<endl;
		}
		else if(retflag == -1)
		{
			cout<<"result:B"<<endl;
		}
		else
		{
			cout<<"result:C"<<endl;
		}		
		return 0;
}
