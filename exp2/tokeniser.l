%%
#<[A-Za-z].h>			printf("\n %s == preprocessor",yytext);
"void"|"int"|"float"		printf("\n %s == DataType",yytext);
"="|"+="			printf("\n %s == assingment",yytext);
"while"|"for"|"if"|"else"	printf("\n %s == keyword",yytext);
[A-Za-z0-9]			printf("\n %s == variable",yytext);
;				printf("\n %s == terminator",yytext);
"main"          printf("\n %s == MainFunction",yytext);
%%

int main(){
	yylex();
}
