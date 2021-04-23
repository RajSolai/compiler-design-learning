%{

#include "y.tab.h"

%}

%%
[0-9]	{yylval= *yytext;return NUMBER;}
[a-z]	{yylval= *yytext;return LETTER;}
[+-;=]		return *yytext;
.		;
%%

int yywrap(void) {
	return 1;
}