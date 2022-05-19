#include <stdio.h>

int main()
{

    char nome[] = "Jose Augusto";
    int i=0;

    for (int i = 0; nome[i] != '\0'; i++)
    {

        printf("%c", nome[i]);
    }
}