#include<stdio.h>
#include<stdlib.h>
struct blocks
{
	int size,alloc;
};
typedef struct blocks blk;
int main()
{
	int nb,np;
	printf("\nEnter the no of block and no of process\t");
	scanf("%d%d",&nb,&np);
	blk b[nb],proc[np];
	printf("\nEnter the size of each block\t");
	for(int i=0;i<nb;i++)
		scanf("%d",&b[i].size);
	for(int i=0;i<nb;i++)
	{
		b[i].alloc=-1;
		proc[i].alloc=-1;
	}
	printf("\nEnter the size of of each process\t");
	for(int i=0;i<np;i++)
		scanf("%d",&proc[i].size);
	for(int i=0;i<np;i++)
	{
		for(int j=0;j<nb;j++)
		{
			if(b[j].alloc==-1 &&b[j].size>=proc[i].size)
			{
				b[j].alloc=1;
				proc[i].alloc=j;
				break;
			}
		}
	}
	printf("\ndetails of the blocks blocks that are alloaced");
	for(int i=0;i<np;i++)
	{
		if(proc[i].alloc!=-1)
			printf("\n%d--->%d--->%d",proc[i].size,proc[i].alloc,b[proc[i].alloc].size);
		else
			printf("%d--->not allocated",i);
	}
}
