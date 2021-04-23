/*
Disclaimer the code is useless unoptimized shit
KNOWN BUGS: space in file makes it unable to read
KNOWN BUGS: the code file needs space at start
*/

#include <stdio.h>
#include <stdlib.h> // For exit() function
# include <string.h>

int main() {
	char c[1000];
	int mem_count = 0000;
	//int count = 1;
	char * token = NULL;
	FILE *fptr;

	// the file read section
	if ((fptr = fopen("helloworld.dat", "r")) == NULL) {
		printf("Error! opening file");
		exit(1);
	}
	fscanf(fptr, "%[^/s]", c);

	// make token out of chars
	// the strtok --> string tokenizer
	token = strtok(c, " ");
	while( token != NULL ) {
		if (!strcmp("void", token)||!strcmp("int", token)||!strcmp("print", token))
		{
			mem_count += 10;
			printf("%s\t", token);
			printf("%d\t", mem_count);
			printf("%s\n", "datatype");
		}
		if (!strcmp("5", token)||!strcmp("6", token))
		{
			mem_count += 200;
			printf("%s\t", token);
			printf("%d\t", mem_count);
			printf("%s\n", "value");
		}
		if (!strcmp("=", token)||!strcmp("+", token))
		{
			mem_count += 10;
			printf("%s\t", token);
			printf("%d\t", mem_count);
			printf("%s\n", "operator");
		}
		if (!strcmp("a", token)||!strcmp("b", token))
		{
			mem_count += 30;
			printf("%s\t", token);
			printf("%d\t", mem_count);
			printf("%s\n", "variable");
		}
		if (!strcmp(" ", token))
		{
			mem_count += 0;
			printf("%s\t", token);
			printf("%d\t", mem_count);
			printf("%s\n", "blank");
		}
		token = strtok(NULL, " ");
	}

	fclose(fptr);

	return 0;
}