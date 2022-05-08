#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int dado;
    struct NODE *prox;
} NODE;

typedef struct PILHA
{
    NODE *topo;
} PILHA;

void inicializar(PILHA *p)
{
    p->topo = NULL;
}

void empilhar(int dado, PILHA *p)
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    if (ptr == NULL)
    {
        printf("ERRO DE ALOCACAO DE NO.\n");
        return;
    }
    else
    {
        ptr->dado = dado;
        ptr->prox = p->topo;
        p->topo = ptr;
    }
}

void desempilhar(PILHA *p)
{
    NODE *ptr = p->topo;
    int dado;
    if (ptr == NULL)
    {
        printf("PILHA VAZIA.\n");
        return;
    }
    else
    {
        p->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
}

void imprimir(PILHA *p)
{
    NODE *ptr = p->topo;
    if (ptr == NULL)
    {
        printf("PILHA VAZIA.\n");
        return;
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    }
}

int main(void)
{
    PILHA *p1 = (PILHA *)malloc(sizeof(PILHA));
    if (p1 == NULL)
    {
        printf("ERRO DE ALOCACAO DE PILHA.\n");
        exit(0);
    }
    else
    {
        inicializar(p1);

        empilhar(10, p1);
        empilhar(20, p1);
        empilhar(30, p1);

        imprimir(p1);
    }

    return 0;
}