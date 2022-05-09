#include <stdio.h>
#include <math.h>

    int main(){

        int x,y;
        float dist;

        dist = sqrt((0-x)*(0-x) + (0-y)*(0-y)); //d² = (xb - xa)² + (yb - ya)².

        printf("Entre com a coordenada x: ");
        scanf("%d", &x);

        printf("Entre com a coordenada y: ");
        scanf("%d", &y);

        printf("A distancia entre os pontos (%d,%d) e (0,0) eh %.1f", x,y,dist);








    }
