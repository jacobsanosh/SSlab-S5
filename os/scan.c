#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,head,choice,disp=0;
	printf("\nenter the no of disk trackes\t");
	scanf("%d",&n);
	int disk[n];
	printf("\nEnter the disk elements\t");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&disk[i]);
	}
	printf("\nenter the head position\t");
	scanf("%d",&head);
	printf("\nenter the direction to be moved \n1.lower\n2.higher\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		for(int i=head;i>=0;i--)
		{
			printf("%d--->",disk[i]);
		}
		for(int i=head+1;i<n;i++)
		{
			printf("%d--->",disk[i]);
		}
		disp=(disk[head]-disk[0])+(disk[n-1]-disk[0]);
		printf("\nno of track covered %d",disp);
	}
	else
	{
		for(int i=head;i<n;i++)
		{
			printf("%d--->",disk[i]);
		}
		for(int i=head-1;i>=0;i--)
		{
			printf("%d--->",disk[i]);
		}
		disp=(disk[n-1]-disk[head])+(disk[n-1]-disk[0]);
		printf("\nno of track covered %d",disp);
	}
}
