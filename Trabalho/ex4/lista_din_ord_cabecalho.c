#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no
{
    int info;
    struct no *prox;
};

Lista criar_lista()
{
    // Aloca no cabecalho
    Lista cab = (Lista)malloc(sizeof(struct no));

    // Coloca lista no estado de vazia
    if (cab != NULL)
    { // Se a alocacao nao falahar...
        cab->prox = NULL;
        cab->info = 0; // guarda o tamanho da lista
        return cab;
    }
}

int lista_vazia(Lista lst)
{
    if (lst->prox == NULL)
    {
        return 1; // lista vazia
    }
    else
    {
        return 0; // lista nao vazia
    }
}

int insere_elem(Lista *lst, int elem)
{
    // aloca um novo no
    Lista N = (Lista)malloc(sizeof(struct no));

    if (N == NULL)
    {
        return 0; // falha: no nao alocado
    }

    // preenche os campos do novo no
    N->info = elem; // insere o conteudo

    Lista aux = *lst; // faz aux apontar para no cabecalho
    while (aux->prox != NULL && aux->prox->info < elem)
    {
        aux = aux->prox; // avanca
    }
    N->prox = aux->prox; // insere novo no na lista
    aux->prox = N;
    N->info++;
    return 1;
}

int remove_elem(Lista *lst, int elem)
{
    if (lista_vazia(lst) == 1)
    {
        return 0; // falha
    }

    Lista aux = *lst; // ponteiro auxiliar para o 1 no

    while (aux->prox != NULL && aux->prox->info != elem)
    {
        aux = aux->prox;
    }

    if (aux->prox == NULL || aux->prox->info > elem) // trata o final da lista
        return 0;                                    // falha

    // remove elemento diferente do 1 no da lista
    Lista aux2 = aux->prox; // aponta no a ser removido
    aux->prox = aux2->prox; // retira no da lista
    free(aux2);             // libera memoria alocada
    (*lst)->info--;         // decrementa o tamanho da lista
    return 1;
}

void imprime_lista(Lista lst)
{
    printf("Lista: {");
    for (lst; lst != NULL; lst = lst->prox)
    {
        printf((lst->prox != NULL) ? "%d, " : "%d}", lst->info);
    }
}

int tamanho(Lista lst)
{
    if (lista_vazia(lst) == 1 || lst == NULL)
    {
        return 0; // falha
    }
    else
    {
        // printf("O tamanho da lista eh: %d", lst->info);
        return lst->info;
    }
}

float media(Lista *lst)
{
    if (lst == NULL || lista_vazia(lst) == 1)
        return 0; // falha

    Lista aux = *lst; // ponteiro auxiliar para o 1 no da lista
    int ac = 0;
    float media;

    while (aux->prox != NULL) // percorre a lista
    {
        ac += aux->prox->info;
        aux = aux->prox;
    }

    media = ac / (*lst)->info;
    return media;
}

int verifica_igual(Lista *lst1, Lista *lst2)
{
    if (lst1 == NULL || lista_vazia(lst1) == 1 || lst2 == NULL || lista_vazia(lst2) == 1 || (*lst1)->info < (*lst2)->info || (*lst1)->info > (*lst2)->info)
    {
        return 0; // falha
    }

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

int inverte_lista(Lista *lst)
{
    Lista nova_lista = cria_lista(); // Inicializa nova lista vazia

    if (lst == NULL || lista_vazia(lst) == 1 || nova_lista == NULL) // Lista nao pode estar vazia e tem que existir
    {
        return 0; // falha
    }

    Lista aux = *lst; // Cria uma lista auxiliar e faz aux apontar para no cabecalho

    while (aux->prox != NULL) // enquanto nao chegar no fim da lista, avancar.
    {
        aux = aux->prox; // avanca
    }

    aux->prox->info = nova_lista->info; // pega o ultimo elemento e atribui no comeco da nova_lista
    remove_elem(aux, aux->prox->info);  // remove o ultimo elementro de aux

    /* Lista aux2 = aux->prox;             // aponta no a ser removido
     aux->prox = aux2->prox;             // retira no da lista
     free(aux2);                         // libera memoria alocada
     (*lst)->info--;                     // decrementa o tamanho da lista
    */

    return 1;
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
