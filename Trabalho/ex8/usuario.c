#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int op;

    do
    {
        system("CLS || clear");
        do
        {
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Verificar lista cheia\n");
            printf(" 4. Inserir elemento\n");
            printf(" 5. Inserir elemento ordenado\n");
            printf(" 6. Excluir elemento\n");
            printf(" 7. Excluir elemento ordenado\n");
            printf(" 8. Imprimir lista\n");
            printf(" 9. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if ((op < 1) || (op > 9))
            {

                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while ((op < 1) || (op > 9));

        switch (op)
        {
        case 1:
            printf("\n\n Recurso ainda nao foi implementado...");
            getch();
            break;

        case 2:
            printf("\n\n Recurso ainda nao foi implementado...");
            getch();
            break;

        case 3:
            printf("\n\n Recurso ainda nao foi implementado...");
            getch();
            break;

        case 4:
            printf("\n\n Recurso ainda nao foi implementado...");
            getch();
            break;

        case 5:
            printf("\n\n Recurso ainda nao foi implementado...");
            getch();
            break;

        case 6:
            printf("\n\n Recurso ainda nao foi implementado...");
            getch();
            break;

        case 7:
            printf("\n\n Recurso ainda nao foi implementado...");
            getch();
            break;

        default:
            printf("\n\n Pressione qualquer tecla para FINALIZAR...");
            getch();
        }
    } while (op != 9);

    return 0;
}