#include<stdio.h>
#include<stdlib.h>

struct process{
	int pid,at,ct,bt,tt,wt;
};
typedef struct process proc;
int main()
{
	int n,tot=0,avgtt=0,avgwt=0;
	printf("\nEnter how may process u have\t");
	scanf("%d",&n);
	proc p[n];
	for(int i=0;i<n;i++)
	{
		p[i].pid=i;
		printf("\nEnter the arrival,burst time\t");
		scanf("%d%d",&p[i].at,&p[i].bt);
	}
	//for sorting based on arrival time
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].at>p[j].at)
			{
				proc temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	printf("\nafter sorting\t");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t%d",p[i].pid,p[i].at);
	}
	printf("\npid\tct\ttt\twt");
	for(int i=0;i<n;i++)
	{
		tot+=p[i].bt;
		p[i].ct=tot;
		p[i].tt=p[i].ct-p[i].at;
		p[i].wt=p[i].tt-p[i].bt;
		avgtt+=p[i].tt;
		avgwt+=p[i].wt;
		printf("\n%d\t%d\t%d\t%d",p[i].pid,p[i].ct,p[i].tt,p[i].wt);
	}
	printf("\navereage waiting time is%f",(float)avgwt/n);
	printf("\navereage turnaroun time is%f",(float)avgtt/n);	
	
}
