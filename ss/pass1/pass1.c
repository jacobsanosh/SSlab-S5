#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char label[20],opcode[20],operand[20],optab_op[20],optab_val[20];
	int start,loc,length;
	FILE *f1,*f2,*f3,*f4;
	f1=fopen("input.txt","r");//to read input
	f2=fopen("optab.txt","r");//to read optab
	f3=fopen("intermediate.txt","w");//to write into intermediate file
	f4=fopen("symtab.txt","w");
	fscanf(f1,"%s%s%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		start=atoi(operand);
		loc=start;
		fprintf(f3,"%s\t%s\t%s",label,opcode,operand);
	}
	else
		loc=0;
	while(fscanf(f1,"%s%s%s",label,opcode,operand)!=EOF)
	{
		if(strcmp(opcode,"END")!=0)
		{
			if(strcmp(label,"**")==0)
			{
				while(fscanf(f2,"%s%s",optab_op,optab_val)!=EOF)
				{
					if(strcmp(optab_op,opcode)==0)
					{
						fprintf(f3,"\n%d\t**\t%s\t%s",loc,opcode,operand);
						loc+=3;
					}
				}
				fseek(f2,0,SEEK_SET);//to reset file pointer to beginning
			}
			else
			{
				fprintf(f3,"\n%d\t%s\t%s\t%s",loc,label,opcode,operand);
				fprintf(f4,"\n%s\t%d",label,loc);
				if(strcmp(opcode,"WORD")==0)
					loc+=3;
				else if(strcmp(opcode,"RESW")==0)
					loc+=3*atoi(operand);
				else if(strcmp(opcode,"BYTE")==0)
					loc+=(strlen(operand)-2);
				else if(strcmp(opcode,"RESB")==0)
					loc+=atoi(operand);
				else
					printf("\n invalid input");		
			}
		}				
	}
	fprintf(f3,"\n%d\t%s\t%s\t%s",loc,label,opcode,operand);
	length=loc-start;
	printf("\nlength is %d",length);
}
