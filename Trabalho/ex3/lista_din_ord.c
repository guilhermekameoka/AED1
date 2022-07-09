#include <stdio.h>
#include <stdlib.h>
#include "lista_din_ord.h"

struct no
{
    int info;
    struct no *prox;
};

Lista criar_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
        return 1; // lista vazia

    else
        return 0; // lista nao vazia
}

/*void lista_cheia(){
 na pratica, tamanho da lista � limitado pelo espaco de memoria
 fazemos a verificacao durante a inserecao */

int insere_ord(Lista *lst, int elem)
{
    // aloca um novo no
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
        return 0; // falha: no nao alocado

    N->info = elem;
    if (lista_vazia(*lst) || elem <= (*lst)->info)
    {
        N->prox = *lst; // aponta para o 1o no atual da lista
        *lst = N;       // faz a lista apontar para o novo no
        return 1;
    }
    // percorrimento da lista (elem > 1o no da lista)
    Lista aux = *lst; // faz o aux apontar para o 1o no
    while (aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox; // avanca

    // insere o novo elemento na lista
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

int remove_ord(Lista *lst, int elem)
{
    if (lista_vazia(lst) == 1 || elem < (*lst)->info)
        return 0; // falha

    Lista aux = *lst; // ponteiro auxiliar para o 1 no
    // trata elemento = 1 no da lista
    if (elem == (*lst)->info)
    {
        *lst = aux->prox; // lista aponta para o 2 no
        free(aux);
        return 1;
    }
    // percorrimento ate o final da lista, ate achar o elemento ou um no maior
    while (aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;

    if (aux->prox == NULL || aux->prox->info > elem) // trata o final da lista
        return 0;                                    // falha
    // remove elemento diferente do 1 no da lista
    Lista aux2 = aux->prox; // aponta no a ser removido
    aux->prox = aux2->prox; // retira no da lista
    free(aux2);             // libera memoria alocada
    return 1;
}

int tamanho(Lista *lst)
{
    if (lst == NULL || lista_vazia(lst) == 1)
        return 0; // falha

    Lista aux = *lst; // ponteiro auxiliar para o 1 no da lista
    int tam = 0;

    while (aux->prox != NULL) // percorre a lista
    {
        aux = aux->prox;
        tam++;
    }

    printf("O tamanho da lista eh: %d", tam+1);
    return tam + 1;
}

float media(Lista *lst)
{
    if (lst == NULL || lista_vazia(lst) == 1)
        return 0; // falha

    Lista aux = *lst; // ponteiro auxiliar para o 1 no da lista
    int ac = 0, tam;
    float media;

    while (aux->prox != NULL) // percorre a lista
    {
        ac += aux->info;
        aux = aux->prox;
    }

    tam = tamanho(lst);
    media = ac / tam;

    printf("\nMedia total: %f\n", media);

    return media;
}

int verifica_igual(Lista *lst1, Lista *lst2)
{
    if (lst1 == NULL || lista_vazia(lst1) == 1 || lst2 == NULL || lista_vazia(lst2) == 1)
        return 0; // falha

    Lista aux = *lst1;  // ponteiro auxiliar para percorrimento da 1 lista
    Lista aux1 = *lst2; // ponteiro auxiliar para percorrimento da 2 lista

    while (aux->prox != NULL && aux->prox->info == aux1->prox->info) // percorre ate o fim
    {
        if (aux->prox == NULL)
            return 1; // sucesso. As listas sao iguais

        else if (aux->prox->info != aux1->prox->info)
            return 0; // falha. listas diferentes

        aux = aux->prox;   // avanca
        aux1 = aux1->prox; // avanca
    }
}

// Intercala

Lista inverte_lista(Lista lst)
{
    if (lst == NULL || lista_vazia(lst) == 1)
        return 0; // falha

    Lista nova_lista = criar_lista(nova_lista); // aloca mem pra nova_lista
    Lista lista;

    while (lst != NULL)
    {
        lista = lst;
        lst = lst->prox; // avanca
        lista->prox = nova_lista;
        nova_lista = lista;
    }
    lst = nova_lista;

    mostra_lista(nova_lista);

    return nova_lista;
}

Lista gera_impares(Lista *lst)
{
    Lista nova_lista = (Lista)malloc(sizeof(struct no));

    if (lst == NULL || lista_vazia(lst) == 1)
        return 0; // falha

    Lista aux = *lst; // ponteiro auxiliar para percorrimento da lista

    while (aux->prox != NULL) // percorre ate o fim
    {
        aux = aux->prox; // avanca

        if (aux->prox->info % 2 != 0) // se for impar, adicionar elemento na nova lista...
            aux->prox->info = nova_lista;
    }
    return nova_lista;
}

void mostra_lista(Lista lst)
{
    printf("Lista: {");
    for (lst; lst != NULL; lst = lst->prox)
    {
        printf((lst->prox != NULL) ? "%d, " : "%d}", lst->info);
    }
}
