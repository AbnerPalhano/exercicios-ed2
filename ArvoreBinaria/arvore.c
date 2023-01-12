#include "arvore.h"


Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

//========= Exercício 2 - pré-ordem ====

void pre_ordem(Arvore* a){
    printf("%c ", a->info);
    if(!verifica_arv_vazia(a->esq)){
        pre_ordem(a->esq);
    }
    if(!verifica_arv_vazia(a->dir)){
        pre_ordem(a->dir);
    }

}
 

//========= Exercício 2 - in-ordem ====

void in_ordem(Arvore* a){
    if(!verifica_arv_vazia(a->esq)){
        in_ordem(a->esq);
    }
    printf("%c ", a->info);
    if(!verifica_arv_vazia(a->dir)){
        in_ordem(a->dir);
    }
}

//========= Exercício 2 - pós-ordem ====

void pos_ordem(Arvore* a){
    if(!verifica_arv_vazia(a->esq)){
        pos_ordem(a->esq);
    }
    if(!verifica_arv_vazia(a->dir)){
        pos_ordem(a->dir);
    }
    printf("%c ", a->info);
}

//========= Exercício 3 - pertence ====

int pertence_arv (Arvore *a, char c){
    int i;
    if(a->info == c){
        return 1;
    }
    else{
        i= 0;
    }
    if(!verifica_arv_vazia(a->esq)){
        i+=pertence_arv(a->esq, c);
    }
    if(!verifica_arv_vazia(a->dir)){
        i+=pertence_arv(a->dir, c);
    }
    return i;
}


//========= Exercício 4 - conta nós ====

int conta_nos (Arvore *a){
    int i=0;
    if(!verifica_arv_vazia(a)){
        i=1;
    }

    if(!verifica_arv_vazia(a->esq)){
        i+=conta_nos(a->esq);
    }
    if(!verifica_arv_vazia(a->dir)){
        i+=conta_nos(a->dir);
    }

    return i;
}

//========= Exercício 5 - calcula altura ====

int calcula_altura_arvore (Arvore *a){
    int i=0;
    if(verifica_arv_vazia(a)){
        return -1;
    }
        i++;
        i+=(calcula_altura_arvore(a->esq)>calcula_altura_arvore(a->dir)) ?
         calcula_altura_arvore(a->esq) : calcula_altura_arvore(a->dir);
    
    return i;
}

//========= Exercício 6 - conta folhas ====

int conta_nos_folha (Arvore *a){
    int i=0;
    if(!verifica_arv_vazia(a->esq)){
        i+=conta_nos_folha(a->esq);
    }

    if(!verifica_arv_vazia(a->dir)){
        i+=conta_nos_folha(a->dir);
    }
    if(verifica_arv_vazia(a->esq) && verifica_arv_vazia(a->dir)){
        return 1;
    }
    return i;
}


int main (int argc, char *argv[]) {

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );	

    pre_ordem(a);
    printf("\n");

    in_ordem(a);
    printf("\n");

    pos_ordem(a);
    printf("\n");

    printf("pertence a: %d\n", pertence_arv(a, 'a'));
    printf("pertence b: %d\n", pertence_arv(a, 'b'));
    printf("pertence c: %d\n", pertence_arv(a, 'c'));
    printf("pertence d: %d\n", pertence_arv(a, 'd'));
    printf("pertence e: %d\n", pertence_arv(a, 'e'));
    printf("pertence f: %d\n", pertence_arv(a, 'f'));
    
    printf("numero de nos: %d\n", conta_nos(a));

    printf("altura da arvore: %d\n", calcula_altura_arvore(a));

    printf("numero de folhas: %d\n", conta_nos_folha(a));

   arv_libera (a);

   return 0;
}
