#include <stdio.h>
#include <string.h>

void* my_memcpy(void* dest, const void* source, size_t size);

void* my_memcpy(void* dest, const void* source, size_t size)
{
    // cast source and destination since we need to walk through memory one at a time
    unsigned char* s = (unsigned char*)source;
    unsigned char* d = (unsigned char*)dest;

    // loop through source
    for (size_t i=0; i<size; i++)
    {
        // set each destination item to each source destination item  
        d[i] = s[i];
    }
}

int main()
{
    size_t arr[] = {1, 2, 3, 4 ,5};
    size_t dest_arr[5];

    // my memcpy
    size_t arr_sizem = sizeof(arr);
    my_memcpy(dest_arr, arr, arr_sizem);

    // print destination array
    for (size_t i = 0; i < 5; i++)
    {
        printf("dest_arr[i]: %d\n", dest_arr[i]);
    }
    
    return 0;
}