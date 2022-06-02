/*******************************************/
/*                 堆排序                   */
/*                    16                    */
/*                 /      \                 */
/*                4        10               */
/*               /  \      / \              */
/*              14    7   9   3             */
/*	       / \  /		            */
/*            2   8 1                       */
/********************************************/
/*用数组表示的堆 下标为根结点为 1*/
#include<stdio.h>

#define LEFT(i) 2*i
#define RIGHT(i) 2*i+1/*若为奇数　说明其为右子数*/

/*恢复最大堆的过程，自上到下，将最小值送到最低的位置*/
void maxheap(int *array,int size,int cursor)
{
	int parenttmp = cursor;
	int treetmpval = 0;
	int lefttmp = 0;
	int righttmp = 0;
	int cur = 0;
	
	lefttmp = LEFT(parenttmp);
	righttmp = RIGHT(parenttmp);		
	treetmpval = array[parenttmp-1];		
	cur = parenttmp;
	
	if(lefttmp > size)
	{
		return ;
	}
	if(array[lefttmp-1]>treetmpval)
	{
		treetmpval = array[lefttmp - 1];
		cur = lefttmp;
	}
	if(righttmp<=size)
	{		
		if(array[righttmp-1]>treetmpval)
		{
			treetmpval = array[righttmp - 1];		
			cur = righttmp;
		}
	}
	if(cur != parenttmp )
	{
		/*交换最大值与父节点*/
		array[cur-1] = array[parenttmp-1];
		array[parenttmp-1] = treetmpval;
		maxheap(array,size,cur);
	}

}
/*构建最大堆的过程是：调用恢复堆的函数，自下倒上重复恢复
　　最大堆性质：某一节点的值一定比其子孙节点值大*/
void buildMaxheap(int *array,int size)
{	
	int i = size/2;
	for(;i>0;i--)	
	{
		maxheap(array,size,i);	
	}
}
void heapsort(int *array,int size)
{
	int temp = 0;
	int i = 0;
	buildMaxheap(array,size);	
	/*交换最后的值与头节点*/
	temp = array[0];
	array[0] = array[size-1];
	array[size-1] = temp;
	/*将最大值逐出序列*/
	size--;
	while(size)
	{		
		maxheap(array,size,1);
		/*交换最后的值与头节点*/
		temp = array[0];
		array[0] = array[size-1];
		array[size-1] = temp;
		size--;	
	}
}

int main()
{
	int a[10] = {4,1,3,2,16,9,10,14,8,7};
	int b[3] ={1,2,3};	
	int i = 0;
	
	heapsort(a,10);
	//heapsort(b,3);

	for(i = 0;i<10;i++)
	{
		printf(" %d",a[i]);
	}	

	return 0;
}
