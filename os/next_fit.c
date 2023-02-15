#include<stdio.h>
#include<stdlib.h>
struct block{
	int size,alloc;
};
typedef struct block blk;

int main()
{
	int nb,np;
	printf("\nEnter the no of block and no of process\t");
	scanf("%d%d",&nb,&np);
	blk bl[nb],proc[np];
	printf("\nEnter the size of each block");
	for(int i=0;i<nb;i++)
	{
		scanf("%d",&bl[i].size);
		bl[i].alloc=-1;
	}
	printf("\nEnter the size of each process");	
	for(int i=0;i<np;i++)
	{
		scanf("%d",&proc[i].size);
		proc[i].alloc=-1;
	}
	int j=0;
	for(int i=0;i<np;i++)
	{
		x:if(bl[j].alloc==-1 &&bl[j].size>=proc[i].size)
		{
			printf("\nhi\n");
			bl[j].alloc=1;
			proc[i].alloc=j;
		}
		else if(j==nb)
		{
			break;
		}
		else
		{
			j++;
			goto x;
		}
		
	}
	printf("\ndetails of the blocks blocks that are alloaced");
	for(int i=0;i<np;i++)
	{
		if(proc[i].alloc!=-1)
			printf("\n%d--->%d--->%d",proc[i].size,proc[i].alloc,bl[proc[i].alloc].size);
		else
			printf("\n%d--->not allocated",i);
	}
}
