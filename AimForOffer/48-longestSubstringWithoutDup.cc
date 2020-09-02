#include <iostream>
#include <string>
int longestSubstringWithoutDup(const std::string& str){

	int curLen = 0;
	int maxLen = 0;
    // 辅助数组用于记录字符最后一次出现的位置
	int *pos = new int[26];

	for(int i = 0;i < 26 ; i++){
		position[i]=-1;
	}
	
	for(int i = 0; i < str.length(); ++i){
		
		int prevIndex = pos[str[i]-'a'];

		if(preIndex < 0 || i - prevIndex > curLen){
			++curLen;
		}else{
		
			if(curLen > maxLen){
				maxLen = curLen;
			}
			curLen = i - prevIndex;
		}
		// 更新最后一次出现的位置
		position[str[i]-'a'] = i;
	}
	if(curLen > maxLen){
		maxLen = curLen;
	}

	delete[] position;
	return maxLen;

}
