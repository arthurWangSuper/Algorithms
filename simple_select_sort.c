/*简单选择排序*/
/*每次将之后数组中的最小值归位*/
#include<stdio.h>
void selectminelement(int *array,int low,int height)
{
	int tempmin = array[low];
	int i = 0,j;
	int cur = low;	

	for(i = low+1;i<=height;i++ )
	{
		if(array[i]<tempmin)
		{
			tempmin = array[i];
			cur = i;
		}
	}
	 printf("min: cur = %d val = %d\n ",cur,array[cur]);
	{
		array[cur] = array[low];
		array[low] = tempmin;
	}
	for(j = 0;j<= height;j++)
	{
		printf(" %d",array[j]);
	}
	printf("\n");
}
void simpleselectsort(int *array,int low,int height)
{
	int i = 0;
	
	for(i = low;i<height;i++)
	{
		selectminelement(array,i,height);
	}
}
void main()
{
	int i;
	int a[10]={7,5,3,4,6,8,9,1,10,2};
	simpleselectsort(a,0,9);
	for(i=0;i<=9;i++)
	{
		printf(" %d",a[i]);
	}
}
