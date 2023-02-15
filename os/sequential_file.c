#include<stdio.h>
#include<stdlib.h>
#define max 10
int main()
{
	int n,fle[max],nb,bno,start,len,count=0;
	for(int i=0;i<max;i++)
		fle[i]=0;
	printf("\nEnter the no of blocks whick are already allocated \t");
	scanf("%d",&nb);
	printf("\nEnter the block which are already allocated \t");
	for(int i=0;i<nb;i++)
	{
		scanf("%d",&bno);
		fle[bno]=1;
	}
	x:printf("\nEnter the starting address and length\t");
	scanf("%d%d",&start,&len);
	if(fle[start]==0 && (start+len)<max)
	{
		for(int i=start;i<max;i++)
		{
			if(fle[i]==0)
			{
				count++;
			}
		}
		//printf("\ncount=%d",count);
		if(count>=len)
		{
			for(int i=start;i<(start+len);i++)
			{
				if(fle[i]==0)
				{
					fle[i]=1;
					printf("\n%d--->1",i);	
				}
			}	
		}
		else
		{
			printf("\ncannot be allocated there is no enough space");
			goto x;
		}
	}
	else{
		printf("\nsomething went wrong");
		goto x;
	}
}
