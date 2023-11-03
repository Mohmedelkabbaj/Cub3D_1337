
#include <string.h>
#include <stdio.h>
int main ()
{

    char src[] = "heelo world";
    char *dest = memcpy(src+2,src,5);
    printf("%s\n",src);
}