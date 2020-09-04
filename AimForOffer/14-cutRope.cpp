#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
//动态规划

int MaxProductCut(int length){
	// 入参检测 + 特殊状况处理	
	if(length <= 0)
		return 0;
	else if(length == 1)
		return 0;
	else if(length == 2)
		return 1;
	else if(length == 3)
		return 2;
	
	std::vector<int> product(4);
	product[1] = 1;
	product[2] = 2;
	product[3] = 3;
	
	for(int i = 4; i < length; ++i){
		int maxProduct = 0;		
		for(int j = 1; j < i/2; ++j){
			maxProduct =std::max( maxProduct, product[j]*product[i-j]);		
					
		}
		product.push_back(maxProduct);
	}
	
	return product[length-1];
}

int main(int argc, char *argv[]){
	printf("MaxProductCut %d max is %d\n",10, MaxProductCut(10));
	return 0;
}
