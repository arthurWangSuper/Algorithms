#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;


class Solution {
public:
    int strStr(string haystack, string needle) {
	int ret = 0;
	int len = haystack.length();
	int len_p = needle.length();
	vector<int> next = getNext(needle);
	int k = 0;
	int i = 0;
	while(i < len && k < len_p){
		if(k == -1 || haystack[i] == needle[k]){
			k++;
			i++;
		} else {
			k=next[k];
		}
	}
  	if(k == len_p){
		return i - len_p;
	} else {
		return -1;
	}
	return ret;
    }
	
    vector<int> getNext(string p){
    	int len = p.length();
	vector<int> next(len);
	int k = -1;
	int i = 0;
	if(len > 0) {
		next[0]=-1;
	}
	while(i < len - 1){
		if(k == -1 || p[i] == p[k]){
			k++;
			i++;
			next[i] = k;
		} else {
			// 回退
			k = next[k];
		}
	}
	return next;
    }
};

int main(){
	string haystack = "";
	string needle = "";
	Solution *pS = new Solution();
	int ret = pS->strStr(haystack, needle);
	cout << ret << endl;
	return 0;
}
