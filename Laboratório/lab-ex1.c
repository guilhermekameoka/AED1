#include <stdio.h>

    int main(){

        int a,b,c, total;
        float premio, val1, val2, val3;

        total=a+b+c;

            printf("Bolao jogador 1 R$: ", a);
            scanf("%d", &a);

            printf("Bolao jogador 2 R$: ", b);
            scanf("%d", &b);


            printf("Bolao jogador 3 R$: ", c);
            scanf("%d", &c);

            printf("Informe o valor do premio: ", premio);
            scanf("%f", &premio);

            val1 = (a/total) * premio;
            val2 = (b/total) * premio;
            val3 = (c/total) * premio;

            printf("Jogador 1 recebera R$: %.1f\n", val1);
            printf("Jogador 2 recebera R$: %.1f\n", val2);
            printf("Jogador 3 recebera R$: %.1f\n", val3);

        return 0;
    }

