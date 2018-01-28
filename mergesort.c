/*********************/

/**/

/**/

/*********************/

#include<stdio.h>

#include<stdlib.h>

int merge(int array[],int low ,int height)

{

	int i,j,k;

	int medium = (low+height)/2;

	int leftsize = medium-low+1;

	int rightsize = height-medium;

	int *left = NULL;

	int *right = NULL;

	left = (int *)malloc(sizeof(int)*(leftsize+1));

	right = (int *)malloc(sizeof(int)*(rightsize+1));
	
	for(i = 0;i<leftsize;i++)
	{

		left[i] = array[low+i];
		
	}
	left[i] = 1000;
	for(i = 0;i<rightsize;i++)
	{
		right[i] = array[medium+i+1];
	}
	right[i] = 1000;

	i = 0;

	j = 0;

	while((left[i] != 1000)&&(right[j] != 1000))
	{
		if(left[i]>right[j])
		{
			array[low] = right[j];
			j++;
		}
		else
		{
			array[low] = left[i];
			i++;		
		}
		low++;

	}	
	if(left[i] == 1000)
	{

		for(;low<=height;low++)
		{	
			array[low] = right[j];
			j++;		
		}	
	}
	else if(right[j] == 1000)
	{

		for(;low<= height;low++)
		{
			array[low] = left[i];
			i++;		
		}
	}
	return 0;

}

int mergesort(int *array,int low ,int height)

{

	

	int medium = (low+height)/2;

#if 1

	if(low == height)
	{
		return 0;
	}
	mergesort(array,low,medium);

	mergesort(array,medium+1,height);

	merge(array,low,height);

#endif

	return 0;

}

int main()

{

	int a[10] = {4,7,5,2,6,1,8,3,10,9};

	int b[8] = {2,8,7,1,3,5,6,4};

	int array_size = 10;

	int i = 0;

	mergesort(b,0,7);

	for(i = 0; i<7; i++)

	{
		printf("%d ",b[i]);
	}
	return 0;

}
