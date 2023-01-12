#include "abbLista.h"

Arvore *cria_arvore_vazia(void)
{
    return NULL;
}

void arvore_libera(Arvore *a)
{
    if (a != NULL)
    {
        arvore_libera(a->esq);
        arvore_libera(a->dir);
        free(a);
    }
}

//========= Q1 - inserir
Arvore *inserir(Arvore *a, int v)
{
    /* Completar */
    if (a == NULL)
    {
        a = (Arvore *)malloc(sizeof(Arvore));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (v < a->info)
    {
        a->esq = inserir(a->esq, v);
    }
    else
    {
        a->dir = inserir(a->dir, v);
    }

    return a;
}

//========= Q1 - remover
Arvore *remover(Arvore *a, int v)
{
    /* Completar */
    if (a = NULL)
    {
        return NULL;
    }
    else if (a->info > v)
    {
        a->esq = remover(a->esq, v);
    }
    else if (a->info < v)
    {
        a->dir = remover(a->dir, v);
    }
    else if ((a->esq == NULL) && (a->dir == NULL))
    {
        free(a);
        a = NULL;
    }
    else if (a->dir == NULL)
    {
        Arvore *tmp = a;
        a = a->esq;
        free(tmp);
    }
    else if (a->esq == NULL)
    {
        Arvore *tmp = a;
        a = a->dir;
        free(tmp);
    }
    else
    {
        Arvore *tmp = a->esq;
        while (tmp->dir != NULL)
        {
            tmp = tmp->dir;
        }
        a->info = tmp->info;
        tmp->info = v;
        a->esq = remover(a->esq, v);
    }

    return a;
}

//========= Q1 - busca
int buscar(Arvore *a, int v)
{
    /* Completar */
    if (a == NULL)
    {
        return 0;
    }
    else if (v > a->info)
    {
        return buscar(a->dir, v);
    }
    else if (v < a->info)
    {
        return buscar(a->esq, v);
    }
    else
        return 1;
}

//========= Q2 - min =====
int min(Arvore *a)
{
    if (a->esq != NULL)
    {
        return min(a->esq);
    }
    else
    {
        return a->info;
    }
}

//========= Q2 - max =====
int max(Arvore *a)
{
    if (a->dir != NULL)
    {
        return max(a->dir);
    }
    else
    {
        return a->info;
    }
}

//========= Q3 - imprime_decrescente =====
void imprime_decrescente(Arvore *a)
{
    if (a->dir != NULL)
    {
        imprime_decrescente(a->dir);
    }
    printf("%d ", a->info);
    if (a->esq != NULL)
    {
        imprime_decrescente(a->esq);
    }
}

//========= Q4 - maior ramo =====
int maior_ramo(Arvore *a)
{
    if (a != NULL)
    {
        return a->info + ((maior_ramo(a->esq) > maior_ramo(a->dir)) ? maior_ramo(a->esq) : maior_ramo(a->dir));
    }
    else
    {
        return 0;
    }
}

void pre_order(Arvore *a)
{
    if (a != NULL)
    {
        printf("%d ", a->info);
        pre_order(a->esq);
        pre_order(a->dir);
    }
}

int main()
{

    int i;
    clock_t start, end;
    srand(time(NULL));

    Arvore *a = cria_arvore_vazia();

    // inserir
    a = inserir(a, 50);
    a = inserir(a, 30);
    a = inserir(a, 90);
    a = inserir(a, 20);
    a = inserir(a, 40);
    a = inserir(a, 95);
    a = inserir(a, 10);
    a = inserir(a, 35);
    a = inserir(a, 45);

    printf("\n");
    pre_order(a);
    printf("\n");
    printf("min: %d\n", min(a));
    printf("max: %d\n", max(a));

    imprime_decrescente(a);
    printf("\n");
    printf("%d\n", maior_ramo(a));
    // ====== Q5 ====
    Arvore *b = cria_arvore_vazia();
    start = clock();
    // quase 1 minuto
    for (i = 0; i < 100000; i++)
    {
        b = inserir(b, i);
    }
    end = clock();
    printf("numeros inseridos na arvore, de 0 ate 999999: %.2fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    Arvore *c = cria_arvore_vazia();
    start = clock();
    // menos de 1 segundo
    for (i = 0; i < 100000; i++)
    {
        c = inserir(c, rand() % 100000);
    }
    end = clock();
    printf("numeros aleatorios entre 0 e 999999 inseridos na arvore: %.2fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    arvore_libera(a);
    arvore_libera(b);
    arvore_libera(c);
    return 0;
}