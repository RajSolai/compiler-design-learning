#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int mem_count = 0000;
    // void a = 5
    // int b = 6
    // a = a + b
    //char statement[5][40] = {"void", " ", "a", "=", "5"};
    //char statement[5][40] = {"int", " ", "b", "=", "6"};
    char statement[5][40] = {"a","=", "b","+","6"};
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t",i);
        if (!strcmp("void", statement[i])||!strcmp("int", statement[i]))
        {
            mem_count += 10;
            printf("%s\t", statement[i]);
            printf("%d\t", mem_count);
            printf("%s\n", "datatype");
        }
        if (!strcmp("5", statement[i])||!strcmp("6", statement[i]))
        {
            mem_count += 200;
            printf("%s\t", statement[i]);
            printf("%d\t", mem_count);
            printf("%s\n", "value");
        }
        if (!strcmp("=", statement[i])||!strcmp("+", statement[i]))
        {
            mem_count += 10;
            printf("%s\t", statement[i]);
            printf("%d\t", mem_count);
            printf("%s\n", "operator");
        }
        if (!strcmp("a", statement[i])||!strcmp("b", statement[i]))
        {
            mem_count += 30;
            printf("%s\t", statement[i]);
            printf("%d\t", mem_count);
            printf("%s\n", "variable");
        }
        if (!strcmp(" ", statement[i]))
        {
            mem_count += 0;
            printf("%s\t", statement[i]);
            printf("%d\t", mem_count);
            printf("%s\n", "blank");
        }
    }

    return 0;
}
