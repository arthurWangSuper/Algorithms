#include <cstdio>
#include <vector>
#include <deque>

vector<int> MaxSliceWindows(const vector<int>& num, unsigned int win_size ){
	vector<int> MaxInWindows;
	if(num.size() >= win_size && win_size >= 1){
		deque<int> index;
		
		// 初始化index队列
		for(unsigned int i = 0; i < win_size; ++i){
			while(!index.empty() && num[i] >= num[index.back()])
				index.pop_back();

			index.push_back(i);
		}

		for(unsigned int i = win_size; i < num.size(); ++i){
			maxInWindows.push_back(num[index.front()]);

			while(!index.empty() && num[i] >= num[index.back()])	
				index.pop_back()
			// 队列头部的数字已经从窗口里滑出
			if(!index.empty() && index.front() <= (int)(i - size))
				index.pop_front();

			index.push_back(i);					
		}	
		maxInWindows.push_back(num[index.front()]);
	}
	return maxInwWindows;
}
