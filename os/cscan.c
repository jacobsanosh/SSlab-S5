#include<stdio.h>
#include<stdlib.h>
int main()
{
	int in,en,n,head,choice,pos,disp=0;
	printf("enter the initial and end position \t");
	scanf("%d%d",&in,&en);
	printf("\nenter the no of request\t");
	scanf("%d",&n);
	int disk[n+2];
	disk[0]=in;
	disk[n+1]=en;
	printf("\nEnter the sequence\t");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&disk[i]);
	}
	for(int i=0;i<n+2;i++)
	{
		printf("\t%d",disk[i]);
	}
	printf("\nenter the positon of the head\t");
	scanf("%d",&head);
	printf("\n1.for moving left 2 for right\t");
	scanf("%d",&choice);
	if(choice==1)
	{
		for(int i=head;i>=0;i--)
		{
			printf("%d--->\t",disk[i]);
		}
		for(int i=n+1;i>head;i--)
		{
			printf("%d--->\t",disk[i]);
		}
	disp=(disk[head]-disk[0])+(disk[n+1]-disk[0])+(disk[n+1]-disk[head+1]);
	//printf("%d\t%d\t%d\t%d",disk[0],disk[head],disk[n+1],disk[head+1]);
	printf("\nno of tracks covered\t%d",disp);
	}
	else
	{
		for(int i=head;i<n+2;i++)
		{
			printf("%d--->\t",disk[i]);
		}
		for(int i=0;i<=head-1;i++)
		{
			printf("%d--->\t",disk[i]);
		}
	disp=(disk[n+1]-disk[head])+(disk[0]-disk[n+1])+(disk[head-1]-disk[0]);
	//printf("%d\t%d\t%d\t%d",disk[0],disk[head],disk[n+1],disk[head+1]);
	printf("\nno of tracks covered\t%d",disp);
	}
	
	
}
		
