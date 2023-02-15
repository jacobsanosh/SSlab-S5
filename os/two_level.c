#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct direct
{
	int fcnt;
	char file[20][20];
};
typedef struct direct dir;
int main()
{
	int nd,option;
	char f[20];
	printf("\nEnter how many directory u have\t");
	scanf("%d",&nd);
	dir d[nd];
	for(int i=0;i<nd;i++)
		d[i].fcnt=0;
	while(1)
	{
		printf("\nEnter the directory number \t");
		scanf("%d",&nd);
		x:printf("\nEnter your option\n1.create an file \n2.delete an file \n3.search file\n4.display\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\nfile count is%d",d[nd].fcnt);
				printf("\nenter the file name \t");
				scanf("%s",d[nd].file[d[nd].fcnt++]);
				printf("\nvalue is ");
				for(int i=0;i<d[nd].fcnt;i++)
				{
					printf("\t%s",d[nd].file[i]);	
				}
				break;
			case 2:
				printf("\nEnter the file name\t");
				scanf("%s",f);
				for(int i=0;i<=d[nd].fcnt;i++)
				{
					if(strcmp(d[nd].file[i],f)==0)
					{
						strcpy(d[nd].file[i],d[nd].file[d[nd].fcnt]);
						d[nd].fcnt-=1;
						break;
					}
				}
				break;
			case 3:
				printf("\nEnter the file name\t");
				scanf("%s",f);
				for(int i=0;i<=d[nd].fcnt;i++)
				{
					if(strcmp(d[nd].file[i],f)==0)
					{
						printf("\nfile is found");
						break;
					}
				}
				break;
			case 4:
				printf("\nfile count is%d",d[nd].fcnt);
				printf("\nfile names are \t");
				for(int i=0;i<d[nd].fcnt;i++)
				{
					printf("\t%s",d[nd].file[i]);	
				}
				break;
			
		}
		
	}	
}

