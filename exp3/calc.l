%{
#include <stdio.h>

int address = 0;
double ins[100];

%}

%%
[0-9]*	{ins[address]=atof(yytext);address++;}
"add"	{printf("%f",ins[0]+ins[1]);}
"mul"	{printf("%f",ins[0]*ins[1]);}
"sub"	{printf("%f",ins[0]-ins[1]);}
;	{printf("%f",ins[0]);}
%%

