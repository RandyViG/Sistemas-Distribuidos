#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main () {
    double i=0,seno,coseno,tangente,logaritmo,raizCuad;
    while(i<87000000) {
        seno=sin(i);
        coseno=cos(i);
        tangente=tan(i);
        logaritmo=log(i);
        raizCuad=sqrt(i);
        i++;
    }

    return 0;
}