#include<stdio.h>
#include<malloc.h>

/*注意这种写法 定义方法，之前没有遇到过*/
typedef struct ListNode
{
	struct ListNode *pNext;/*注意这个数据结构的使用*/
	int val;
}Node,*pNode;

pNode creatList(int*arr,int len)
{
	int i = 0;
	pNode phead =(pNode)malloc(sizeof(Node));
	if(phead==NULL)
	{
		
		printf("空间分配失败 \n");
        	/*退出程序*/
		exit(-1);
	} 
	phead->pNext=NULL;
	for(i=len-1;i>=0;i--)
	{
		pNode pNodenew = (pNode)malloc(sizeof(Node));
		pNodenew->val=arr[i];
		pNodenew->pNext=phead->pNext;
		phead->pNext=pNodenew;
	}
	return phead;
}
pNode reversalList(pNode List)
{
	if((List == NULL)||(List->pNext == NULL))
	{
		return NULL;
	}	
	pNode first = List->pNext;
	pNode tmp = first->pNext;
	while(tmp!=NULL)
	{
		first->pNext=tmp->pNext;
		tmp->pNext = List->pNext;
		List->pNext = tmp;
		tmp=first->pNext;
	}
		
	return List;
}
int printlist(pNode list)
{
	if((list==NULL)||(list->pNext==NULL))
	{
		printf("list is null!!!\r\n");
	}
        pNode tmp = list->pNext;
	while(tmp != NULL)
	{
		printf("%d ",tmp->val);
		tmp = tmp->pNext;
	}
	return 0;
}
int main()
{
	int arr[5]={1,2,3,4,5};
	pNode list = creatList(arr,5);
	printf("--------\r\n");
	printlist(list);
	printf("\r\n=========\r\n");
	pNode relist = reversalList(list);
	printlist(relist);	

	return 0;
}
