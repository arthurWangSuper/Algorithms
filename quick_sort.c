
#include<stdio.h>
 
void swap(int *a,int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp; 
}
 
int quick_sort_single(int *array,int low, int height)
{
	int cur = low;
	/*选取哨兵*/
	int sol = array[cur];
	int temp = 0;
	int i,j,k;
	if(low >= height)
	{
		return -1;
	}	
	i = low+1;j = height;
	while(i!=j)
	{
		/*right*/
		while(i < j)
		{
			if(array[j]<sol)
			{
				break;
			}
			j--;
		}
	        /*left*/
		while(i < j)
		{
			if(array[i]>sol)
			{
				break;
			}
			i++;
		}
		if(i<j)
		{
			swap(array+i,array+j);
		}
	}
	swap(array+i,array+low);

	/*position*/
	return i;
}
 
int quick_sort(int *array,int low, int height)
{
	int pos = 0;
	pos = quick_sort_single(array,low, height);
	if(pos != -1)
	{
		quick_sort(array,low,pos-1);
		quick_sort(array,pos+1,height);
	}
	return 0;
}
int main()
{
	int a[10] = {7,4,5,2,6,1,8,3,9,10};
	int array_size = 10;
	int i = 0;
	quick_sort(a,0,9);
	for(i = 0; i<array_size; i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
