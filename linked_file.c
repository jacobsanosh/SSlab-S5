#include<stdio.h>
#include<stdlib.h>
struct node{
	int free;	
};
typedef struct node nod;
int main()
{
	int n,f,start,block;
	printf("\nEnter how many file you have\t");
	scanf("%d",&n);
	nod no[n];
	for(int i=0;i<n;i++)
	{
		
		printf("\nenter 0 for free 1 for not free in block %d\t",i);
		scanf("%d",&f);
		no[i].free=f;
	}
	x:printf("\nEnter the starting block\t");
	scanf("%d",&start);
	if(no[start].free==1)
	{
		printf("\nalready allocated");
		goto x;
	}
	else
	{
		no[start].free=0;
		printf("\nallocated");	
	}
	y:printf("\nEnter the block number > %d\t",start);
	scanf("%d",&block);
	if(no[block].free==0 && block>start)
	{
		no[block].free==0;
		printf("%d---->1",block);
		goto y;
	}
	else
	{
		printf("\nnot available");
		goto y;
	}	
}

