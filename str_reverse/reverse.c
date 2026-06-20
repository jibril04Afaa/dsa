#include <stdio.h>
#include <string.h>

char* reverse(char* s);

char* reverse(char* s)
{
    size_t length = strlen(s);

    // make a right and left pointer
    size_t left = 0;
    size_t right = length - 1;

    while (left < right)
    {
        // swap characters
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        // move both pointers towards each other while they have not met
        left++;
        right--;
    } 

    return s;
}


int main()
{
    char my_str[] = "hello world";
    reverse(my_str);

    for(size_t c=0; my_str[c] != '\0'; c++)
    {
        printf("%c", my_str[c]);
    }
    return 0;
}