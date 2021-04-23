#include <string.h>
#include <stdio.h>

struct stmt
{
	char res[1];
	char expr[10];
}stmts[10];

int last_op_mov;

int address = 0;

int main()
{
	int num_of_stmts;
	printf("ENTER NUMBER OF STATEMENTS\n");
	scanf("%d",&num_of_stmts);
	for (int i = 0; i < num_of_stmts; ++i)
	{
		printf("ENTER THE LHS\t");
		scanf("%s",stmts[i].res);
		printf("ENTER THE RHS\t");
		scanf("%9s",stmts[i].expr);
	}
	printf("\n💎️ FULL CODE\n");
	printf("---------------------\n");
	for (int i = 0; i < num_of_stmts; ++i)
	{
		printf("%d\t%c:=%s\n",i,stmts[i].res[0],stmts[i].expr);
	}
	printf("\n💎️ MACHINE CODE\n");
	printf("---------------------\n");
	for (int j = 0; j < num_of_stmts; ++j)
		{
			for (int k = 0; k < sizeof(stmts[j].expr); ++k)
			{
				if (stmts[j].expr[1]=='+')
					{
						last_op_mov = address+1;
						printf("ADD R%d R%d\n",address-1,address);
						printf("MOV A R%d\n",last_op_mov);
						last_op_mov = last_op_mov+1;
						break;
					}
					if (stmts[j].expr[0]=='5'|stmts[j].expr[0]=='8')
					{
						++address;
						printf("MOV %c R%d\n",stmts[j].expr[0],address); 
						break;
					}
					if (stmts[j].expr[1]=='-')
					{
						printf("SUB R%d R%d\n",address-1,address);
						printf("MOV A R%d\n",last_op_mov);
						last_op_mov = last_op_mov+1;
						break;
					}
			}
		}
	return 0;
}
