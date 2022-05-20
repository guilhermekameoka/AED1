#include <stdio.h>
#include <stdlib.h>

typedef struct ponto
{

    int x, y;
    
} ponto;

int main()
{

    int n, *v;

    printf("Quantos pontos deseja digitar: ");
    scanf("%d", &n);

    v = (int *)malloc(n * sizeof(int));

    ponto v[n];

    for (int i = 0; i < n; i++)
    {
        printf("Entre com a coordenada x do ponto %d: ", i + 1);
        scanf("%d", &v.x[i]);
        printf("Entre com a coordenada y do ponto %d: ", i + 1);
        scanf("%d", &v.y[i]);
    }
}