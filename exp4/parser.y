%{


#include <stdio.h>
#include <string.h>
int yylex(void);
#include "y.tab.h"
char *makeStatement(char,char,char);
%}

%token NUMBER LETTER

%%
expr: LETTER'='stmt';' {makeStatement('=',(char)$1,(char)$3);}

stmt: 	stmt'+'stmt {$$ = makeStatement('+',(char)$1,(char)$3);}
		| stmt'-'stmt {$$ = makeStatement('-',(char)$1,(char)$3);}
		| NUMBER {$$=$1;}
		| stmt'*'stmt {$$ = makeStatement('*',(char)$1,(char)$3);}
		| LETTER {(char)$1;}
		;

%%

char *makeStatement(char operator,char operand_one , char operand_two){
	char* temp;
	if(operator=='+'){
		printf ("%c:=\t%c+%c\n",operand_one,operand_one,operand_two);
		temp = (char*)("%c+%c",operand_two,operand_one);
	}else if(operator=='-'){
		printf ("%c:=\t%c-%c\n",operand_one,operand_one,operand_two);
		temp = (char*)("%c-%c",operand_two,operand_one);
	}else if(operator=='*'){
		printf ("%c:=\t%c*%c\n",operand_one,operand_one,operand_two);
		temp = (char*)("%c*%c",operand_two,operand_one);
	}else{
		printf ("%c:=\t%c",operand_one,operand_two);
		temp = (char*)("%c=%c",operand_one,operand_two);	
	}
	return temp;
} 

int main(){
	printf("Enter the Statement\n");
	yyparse();
	return 0;
}
