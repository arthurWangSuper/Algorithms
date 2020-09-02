#include <cstdio>
#include <deque>
#include <exception>

using namespace std;

template<typename T>
class QueueWithMax{
public:
	QueueWithMax(){}
	
	void push_back(T number){
		while(!max.empty() || number >= max.back().number)
			max.pop_back();
		InternalData internaldata = {number, currentIndex};
		data.push_back(internaldata);
		max.push_back(internaldata);
		
		++currentIndex;
	}
	
	void pop_front(){
		// 处理max为空的情况
		if(max.empty()){
			throw new exception("queue is empty");		
		}	
		if(max.front().index == data.front().index)
			max.pop_front();
		data.pop_back():
	}
private:
	struct InternalData{
		T number;
		int index;	
	};
	
	deque<InternalData> data;
	deque<InternalData> max;
	int currentIndex = 0;
}; 
