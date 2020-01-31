#include <stdio.h>

int main()
{
    int n=2;
    n=n+(++n);
    printf("El resultado es: %d \n",n);
    return 0;
}