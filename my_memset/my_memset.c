#include <stdio.h>
#include <string.h>

// memset fills a specified block of memory with a particular byte value
void* my_memset(void* ptr, int value, size_t num);

// fills ptr with value, with a size of num
void* my_memset(void* ptr, int value, size_t num)
{
   unsigned char* p = (void*)ptr; // cast to unsigned char* so we can modify *ptr
   for (size_t i = 0; i < num; i++)
   {
        // set *ptr to value
        *p = value;
        p++; // move the pointer to capture (size_t num) number of bytes
   }
   return ptr;
}

int main()
{
    char buf[100] = "hello world";

    for(size_t c=0; buf[c]!='\0'; c++)
    {
        printf("buf BEFORE memset: %c\n", buf[c]);

    }

    my_memset(buf, 0, sizeof(buf));

    // verify my_memset works
    for (size_t c=0; c<sizeof(buf); c++)
    {
        printf("buf AFTER memset: %d\n", c);
    }

    return 0;
}