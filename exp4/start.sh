yacc -d parser.y && lex intercode.l
gcc lex.yy.c y.tab.c -ll -ly