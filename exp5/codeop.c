# include <stdio.h>
# include <string.h>

struct stmt
{
	char res[1];
	char expr[10];
}stmts[10];

char eliminated[10];
char replacement;
int stack_ptr = 0;

void push_to_eliminated(char expr){
	eliminated[stack_ptr] = expr;
	++stack_ptr;
}

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
	printf("💎️ FULL CODE\n");
	printf("---------------------\n");
	for (int i = 0; i < num_of_stmts; ++i)
	{
		printf("%d\t%c:=%s\n",i,stmts[i].res[0],stmts[i].expr);
	}
	printf("\n⏰️ OPTIMIZING THE CODE\n");
	for (int i = 0; i < num_of_stmts; ++i)
	{
		if(i!=0 && strcmp(stmts[i].expr,stmts[i-1].expr)==0){
			push_to_eliminated(stmts[i].res[0]);
			replacement = stmts[i-1].res[0];
			printf("✔️ Common statement found !\n");
		}
	}
	for (int j = 0; j < num_of_stmts; ++j)
		{
			for (int k = 0; k < sizeof(stmts[j].expr); ++k)
			{
				for (int l = 0; l < stack_ptr; ++l)
				{
					if (stmts[j].expr[k]==eliminated[l])
					{
						stmts[j].expr[k] = replacement;
						printf("✔️ Common statement eliminated !\n");
					}
				}
			}
		}
	printf("\n💎️ OPTIMIZED CODE\n");
	printf("---------------------\n");
	for (int i = 0; i < num_of_stmts; ++i)
	{
		for (int j = 0; j < stack_ptr; ++j)
		{
			if (stmts[i].res[0]!=eliminated[j])
			{
				printf("%d\t%c:=%s\n",i,stmts[i].res[0],stmts[i].expr);
			}
		}
		
	}
	return 0;
}