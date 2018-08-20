#include<stdio.h>

int printarr(int *arr,int len)
{
	int i = 0;
	for(i=0;i<len;i++)
	 	printf("%d",arr[i]);
	return 0;
}
int main()
{
	int arr[5]={1,2,3,4,5};
	printarr(arr,5);
	return 0;
}
