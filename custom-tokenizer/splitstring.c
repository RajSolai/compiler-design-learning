# include <stdio.h>
# include <string.h>

int main(int argc, char const *argv[])
{
	char c[1000] = "solai raj";
	char * token = strtok(c, " ");
	printf( " %s\n", token ); //printing the token
	return 0;
}

