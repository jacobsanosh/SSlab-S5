#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct direc{
	char file[20][20];
	int fcnt;
};
typedef struct direc dire;
 
int main()
{
	int option;
	dire di;
	char f[20];
	di.fcnt=0;
	while(1){
		printf("\nEnter your option \n1.create an file \n2.delete an file \n3.search an file \n4.display\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				if(di.fcnt<20)
				{
					printf("\nEnter the file name\t");
					scanf("%s",di.file[di.fcnt++]);
					
				}
				else
				{
					printf("\nthere is no space");
				}
				break;
			case 2:
				printf("\nEnter the file name to be deleted\t");
				scanf("%s",f);
				for(int i=0;i<=di.fcnt;i++)
				{
					if(strcmp(f,di.file[i])==0)
					{
						strcpy(di.file[i],di.file[di.fcnt]);
						di.fcnt--;
					}
				}
				break;
			case 3:
				printf("\nenter the file name to be searched\t");
				scanf("%s",f);
				for(int i=0;i<=di.fcnt;i++)
				{
					if(strcmp(f,di.file[i])==0)
					{
						printf("\n founded");
						break;
						
					}
				}
				break;
			case 4:
				printf("\nfile name are");
				for(int i=0;i<=di.fcnt;i++)
				{
					printf("\t%s",di.file[i]);
				}
				break;
			
				
			default:
				printf("\nplease enter an valid input");
				break;
		}
	
				
	}	
}
