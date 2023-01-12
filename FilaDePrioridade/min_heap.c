#include <stdio.h>
#include <stdlib.h>

int pai(int i)
{
    return (i - 1) / 2;
}

int esquerda(int i)
{
    return (i * 2) + 1;
}

int direita(int i)
{
    return (i * 2) + 2;
}

void trocar(int *V, int a, int b)
{
    int aux = V[a];
    V[a] = V[b];
    V[b] = aux;
}

void imprimir(int *V, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void min_heapify(int *V, int size, int i)
{
    int esq = esquerda(i), dir = direita(i), menor;
    if (esq < size && V[esq] < V[i])
    {
        menor = esq;
    }
    else
    {
        menor = i;
    }
    if (dir < size && V[dir] < V[menor])
    {
        menor = dir;
    }
    if (menor != i)
    {
        trocar(V, i, menor);
        min_heapify(V, size, menor);
    }
}

void build_min_heap(int *V, int size)
{
    int i;
    for (i = (size / 2) - 1; i >= 0; i--)
    {
        min_heapify(V, size, i);
    }
}

int heap_extract_min(int *V, int *size)
{
    int min;
    if (*size < 1)
    {
        printf("erro: heap underflow");
        return 1;
    }
    min = V[0];
    V[0] = V[*size - 1];
    *size -= 1;
    min_heapify(V, *size, 0);
    return min;
}

void heap_decrease_key(int *V, int i, int chave, int size)
{
    if (chave > V[i])
    {
        printf("erro: chave maior que atual\n");
        return;
    }
    V[i] = chave;
    while (i > 0 && V[pai(i)] > V[i])
    {
        trocar(V, i, pai(i));
        i = pai(i);
    }
}

void min_heap_insert(int *V, int chave, int *size)
{
    *size = *size + 1;
    V[*size - 1] = 5000000;
    heap_decrease_key(V, *size - 1, chave, *size);
}

int main()
{

    int size = 10;
    int v[size];
    //vetor inicial:  {4, 1, 3, 2, 16, 9, 10, 14, 8, 7}
    v[0] = 4;
    v[1] = 1;
    v[2] = 3;
    v[3] = 2;
    v[4] = 16;
    v[5] = 9;
    v[6] = 10;
    v[7] = 14;
    v[8] = 8;
    v[9] = 7;

    printf("vetor inicial: ");
    imprimir(v, size);

    build_min_heap(v, size);
    printf("build_min_heap: ");
    imprimir(v, size);

    heap_extract_min(v, &size);
    printf("heap_extract_min: ");
    imprimir(v, size);

    //Modificando a última chave {16} para o valor {1}!
    heap_decrease_key(v, size - 1, 1, size);
    printf("heap_decrease_key (mudando a ultima chave para o valor 1): ");
    imprimir(v, size);

    //Inserindo uma nova chave com valor {0}!
    min_heap_insert(v, 0, &size);
    printf("min_heap_insert (inserindo uma chave com valor 0): ");
    imprimir(v, size);

    return 0;
}