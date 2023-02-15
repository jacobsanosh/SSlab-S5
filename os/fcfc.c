#include<stdio.h>
#include<stdlib.h>
struct process{
	int pid,at,bt,ct,tt,wt;
};
typedef struct process proc;

int main()
{
	int n,tot=0;
	float avgwt=0,avgtt=0;
	printf("\nEnter how many process u have\t");
	scanf("%d",&n);
	proc p[n];
	for(int i=0;i<n;i++)
	{
		printf("\nenter the arrival time and burst time\t");
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].pid=i;
	}
	for(int i=0;i<n;i++)
	{
		tot+=p[i].bt;
		p[i].ct=tot;
		p[i].tt=p[i].ct-p[i].at;
		p[i].wt=p[i].tt-p[i].bt;
		avgwt+=p[i].wt;
		avgtt+=p[i].tt;
	}
	printf("\npid\tct\ttt\twt");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d",p[i].pid,p[i].ct,p[i].tt,p[i].wt);
	}
	printf("\naverage turn around time is %lf",avgtt/n);
	printf("\navverage waiting time is %lf",avgwt/n);	
}
