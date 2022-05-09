#include <stdio.h>
#include <stdlib.h>

    int main(){

    int bit1, bit2, bit3, bit4, decimal;

    printf("digite o 1o bit: ");
    scanf("%d", &bit1);

    printf("digite o 2o bit: ");
    scanf("%d", &bit2);

    printf("digite o 3o bit: ");
    scanf("%d", &bit3);

    printf("digite o 4o bit: ");
    scanf("%d", &bit4);


    decimal = pow((bit4*2),0) + pow((bit3*2),1) + pow((bit2*2),2) + pow((bit1*2),3);


    printf("O numero binario %d%d%d%d corresponde ao numero decimal %d", bit1, bit2, bit3, bit4, decimal);







    }


