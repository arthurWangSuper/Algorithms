/*********************************/
/*　　　　　　插入排序　　　　　　*/
#include<stdio.h>
void insertsort(int *array,int size)
{
	int i = 1;
	int j = 0;
	int k = 0;
	int temp = 0;                                               
	for(;i<size;i++)
	{
		temp = array[i];
		printf("temp = %d\n",temp);
		/*每次添加一个*/
		for(j = 0;j<=i;j++)
		{
			if(temp<=array[j])
			{
				printf(" i =%d,j = %d\n",i,j);
				for(k = i;k>j;k--)
				{	
					array[k] = array[k-1];
				}				
				array[j] = temp;
				break;			
			}
		}
			
	}
}
void main()
{
	int i = 0;
	int a[10] = {5,3,7,8,9,1,4,2,10,6};
	insertsort(a,10);
	for(i=0;i<10;i++)
	{	
		printf(" %d",a[i]);	
	}
}
