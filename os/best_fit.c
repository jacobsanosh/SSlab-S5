#include<stdio.h>
#include<stdlib.h>
struct block
{
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
	for(int i=0;i<nb-1;i++)
	{
		for(int j=i+1;j<nb;j++)
		{
			if(bl[i].size>bl[j].size)
			{
				bl[i].size=bl[i].size+bl[j].size;
				bl[j].size=bl[i].size-bl[j].size;
				bl[i].size=bl[i].size-bl[j].size;
			}
		}
	}
	printf("\nafter swapping\t");
	for(int i=0;i<nb;i++)
	{
		printf("\t%d",bl[i].size);
	}
	for(int i=0;i<np;i++)
	{
		for(int j=0;j<nb;j++)
		{
			if(bl[j].alloc==-1 &&bl[j].size>=proc[i].size)
			{
				bl[j].alloc=1;
				proc[i].alloc=j;
				break;
			}
		}
	}
	for(int i=0;i<np;i++)
	{
		if(proc[i].alloc!=-1)
		{
			printf("\n%d--->%d",proc[i].size,bl[proc[i].alloc].size);
		}
		else{
			printf("\n%d--->not allocated",proc[i].size);
		}
	}
}	
