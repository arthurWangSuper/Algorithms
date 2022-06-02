#include <cstdio>
#include <exception>


int Min(int *num, size_t length){
	int indexS = 0;
	int indexE = length-1;
	int indexM = indexS;
	while(num[indexS] > num[indexE]){
		if(indexE - indexS == 1){
			indexM = indexE;
			break;
		}

		int indexM = (indexS + indexE) / 2;
		// 无法判断最小值在那个区的情况
		if(num[indexS] == num[indexM] && num[indexM] == num[indexE])
		{
			int result = 0;
			for(int i = indexS; i<indexE; ++i){
				if(result > num[i])
					result = num[i];
			}
			return result;
		}
		if(num[indexS] >= num[indexM]){
			indexE = indexM;
		}
		else if(num[indexM] >= num[indexE]){
			indexS = indexM;
		}
	}
	return num[indexM];
}

int main(int argc, char *argv[]){

	int arr[6] = {1,2,3,4,5,6};

	printf("result = %d\n",Min(arr, 6));
	
	return 0;
}
