#include <stdio.h>

int main() {
    int popUF;
    float numDepUF;

    printf("Insira a população do estado: ");
    scanf("%d", &popUF);

    numDepUF = (popUF * 513.0) / 190755799;

    if(numDepUF < 8){
        numDepUF = 8;
    }
    else if(numDepUF > 70) {
        numDepUF = 70;
    }

    printf("Esse estado tem %.0f deputados.", numDepUF);

    return 0;
}