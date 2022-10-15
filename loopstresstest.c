#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    float i;
    float increment = 0.000000000001;
    float n = 0.00000000001;
    int count = 1;

    for (i = 0.0; i < n; i = i + increment){
        printf("Number of Loops: %d\n", count);
        count++;
    }
    return 0;
}