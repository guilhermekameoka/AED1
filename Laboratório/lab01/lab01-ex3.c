#include <stdio.h>
#include <stdlib.h>

int main()
{

    int bit[4], decimal;

    for (int i = 1; i < 5; i++)
    {

        printf("digite o %do bit: ", i);
        scanf("%d", &bit[i]);
    }

    decimal = pow((bit[4] * 2), 0) + pow((bit[3] * 2), 1) + pow((bit[2] * 2), 2) + pow((bit[1] * 2), 3);

    printf("O numero binario %d%d%d%d corresponde ao numero decimal %d", bit[1], bit[2], bit[3], bit[4], decimal);
}
