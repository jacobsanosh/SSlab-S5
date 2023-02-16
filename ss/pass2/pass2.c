#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	printf("%s","0s");
	char add[20],label[20],opcode[20],operand[20],opt_code[20],opt_val[20],sym_lab[20],sym_val[20];
	int len=24,start;
	FILE *f1,*f2,*f3,*f4;
	f1=fopen("intermediate.txt","r");
	f2=fopen("assembly_list.txt","w");
	f3=fopen("optab.txt","r");
	f4=fopen("symtab.txt","r");
	fscanf(f1,"%s%s%s%s",add,label,opcode,operand);
	if(strcmp(label,"START")==0)
	{
		fprintf(f2,"H%s__^%06d^%06d",label,atoi(opcode),len);
		start=atoi(opcode);	
	}
	fprintf(f2,"\nT^%06d^%02d",atoi(opcode),len);
	while(fscanf(f1,"%s%s%s%s",add,label,opcode,operand)!=EOF)
	{
		printf("\n%s\t%s\t%s\t%s\t",add,label,opcode,operand);
		while(fscanf(f3,"%s%s",opt_code,opt_val)!=EOF)
		{
			//printf("\n%s\t%s",opt_code,opt_val);
			if(strcmp(opt_code,opcode)==0)
			{
				while(fscanf(f4,"%s%s",sym_lab,sym_val)!=EOF)
				{
					if(strcmp(operand,sym_lab)==0)
					{
						printf("%s%s",opt_val,sym_val);
						fprintf(f2,"^%s%s",opt_val,sym_val);
						
					}
				
				}
				fseek(f4,0,SEEK_SET);
			}
			//printf("\nopcode %s",opcode);
			else if(strcmp(opcode,"WORD")==0 || strcmp(opcode,"BYTE")==0)
			{
				fprintf(f2,"^%s",operand);
				break;
			}
		}
		fseek(f3,0,SEEK_SET);

	}
	fprintf(f2,"\nE^%06d",start);
}
