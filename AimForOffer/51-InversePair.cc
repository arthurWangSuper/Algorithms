#include <cstdio>
#include <iostream> 

int InversePairsCore(int *data, int *copy, int start, int end){

	if(start == end){
		copy[start] = data[start];
		return 0;
	}
	
	int length = (end - start)/2;
	// 注意　dst　和　src
	// 递归的过程中，copy与data之间交换来交换去
	int left = InversePairsCore(copy, data, start, start+length);
	int right = InversePairsCore(copy, data, start+length+1, end);
	
	int i = start + length;
	int j = end;
	int indexCopy = end;
	int count = 0;
	
	while(i >= start && j >= start+length+1){
		if(data[i] > data[j]){
			// 有逆序对的存在，也就是说前面的元素大于后边
			// 讲其copy到辅助数组
			copy[indexCopy--] = data[i--];
			count += j - start -length;	
		}
		else{
			copy[indexCopy--] = data[j--];
		}
	}

	for(;i>=start;--i)
		copy[indexCopy--] = data[i];
	for(;j>=start+length+1;--j)
		copy[indexCopy--] = data[j];

	return left+right+count;
}


int InversePairs(int *data, int length){
	if(data == nullptr || length < 0)
		return 0;
	int *copy = new int[length];
	for(int i = 0;i<length; ++i){
		copy[i] = data[i];
	}
	
	int count = InversePairsCore(data, copy, 0, length-1);
	std::cout <<"copy ===="<<std::endl;	
	for(int i = 0; i < 6; ++i)
		printf("%d ",copy[i]);
	std::cout<<std::endl;
	delete[] copy;

	return count;

}

int main(int argc, char *argv[]){
	int data[] = {6,5,4,3,2,1};
	InversePairs(data,6);
	for(int i = 0; i < 6; ++i)
		printf("%d ",data[i]);
	std::cout<<std::endl;
	return 0;
}

