#include<stdio.h>
#include<stdlib.h>
struct process{
	int pid,at,bt,ct,tt,wt,rt;
};
typedef struct process pro;
int main()
{
	int n,qua,tot=0,avgtt=0,avgwt=0,cnt=0;
	printf("\nEnter how many process u have and time quantum\t");
	scanf("%d%d",&n,&qua);
	pro p[n];
	for(int i=0;i<n;i++)
	{
		p[i].pid=i;
		printf("\nenter the arrival and burst time\t");
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].rt=p[i].bt;
	}
	while(cnt<n)
	{
		for(int j=0;j<n;j++)
		{
			if(p[j].rt>0 && p[j].rt<=qua)
			{
				printf("\nEntered!!!");
				tot+=p[j].rt;
				p[j].rt=0;
				p[j].ct=tot;
				p[j].tt=p[j].ct-p[j].at;
				p[j].wt=p[j].tt-p[j].bt;
				cnt++;
			}
			else if(p[j].rt>qua)
			{
				p[j].rt=p[j].rt-qua;
				tot+=qua;
			}
		}
	}
	printf("\npid\tct\ttt\twt\n");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d",p[i].pid,p[i].ct,p[i].tt,p[i].wt);
	}
}
