#include <stdio.h>

int main()
{

    int amigo[3], total;
    float val_premio, recebe[3];

    for (int i = 1; i <= 3; i++)
    {

        printf("Bolao jogador %d R$: ", i);
        scanf("%d", &amigo[i]);
        total = total + amigo[i];
    }

    printf("Informe o valor do premio: ");
    scanf("%f", &val_premio);

    for (int j = 1; j <= 3; j++)
    {
        recebe[j] = val_premio * (amigo[j] / total);
        printf("Jogador %d recebera R$: %.1f\n", j, recebe[j]);
    }
    return 0;
}