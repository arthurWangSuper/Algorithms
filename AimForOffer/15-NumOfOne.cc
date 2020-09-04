#include <iostream>
#include <cstdio>

int NumberOfOne(int n){
	int count = 0;
	while(n){
		++count;
		n = n&(n-1); // 讲最后一位１变为０
	}
	return count;
}

int main(int argc, char *argv[]){
	printf("%d NumOfOne %d",10,NumberOfOne(10));
	return 0;
}
