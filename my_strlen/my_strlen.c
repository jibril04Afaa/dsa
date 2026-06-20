#include <stdio.h>
#include <string.h>

size_t my_strlen(char* my_string);

size_t my_strlen(char* my_string)
{
    size_t counter = 0;
    for (size_t c = 0; my_string[c] != '\0'; c++)
    {   
        counter ++;
    }

    return counter;
}

int main()
{
    char* s = "hello world";
    printf("strlen(s): %ld\n", strlen(s));

    printf("my_strlen(s): %ld\n", my_strlen(s));

    return 0;
}
