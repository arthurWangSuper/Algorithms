/*希尔排序：也叫增量排序，每次只比较增量序列*/
 #include<stdio.h>

void shellsort(int* array,int size)
{
	int increment = 0;
	int i = 0;	
	int j = 0;
	int temp = 0;

	for(increment = size/3;increment>0;increment/=3)
	{
		/*每个序列的最小值*/
		 for (i = 0; i + increment < size; ++i)
                  {
                          if (array[i + increment] < array[i])
                          {
                                  temp = array[i +increment];                                                                  
                                  j = -1;
                                  for (j = i; temp < array[j] && j >= 0; j -= increment)
                                  {
                                          array[j + increment] = array[j];
                                  }
                                  array[j + increment] = temp;
                          }
                  }
	
	}
}
int main()
{
	int a[13] ={5,3,12,1,9,6,2,4,7,13,11,10,8};
	int i = 0;
	shellsort(a,13);	
	for(i = 0;i<13;i++)
	{
		printf(" %d",a[i]);
	}	
	return 0;
}
