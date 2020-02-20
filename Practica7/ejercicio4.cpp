#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double max,i=0;
    double seno,coseno,tangente,logaritmo,raizCuad;
    while(i<87000000){
        seno+=sin(i);
        coseno+=cos(i);
        tangente+=tan(i);
        logaritmo+=log(i);
        raizCuad+=sqrt(i);
        i++;
    }

    return 0;
}

