#include "avl.h"

int main()
{

   ///////////EX1//////////

   Arvore *AVL = NULL;
   /*
      AVL = inserir(AVL, 'Q');
      AVL = inserir(AVL, 'Z');
      AVL = inserir(AVL, 'B');
      AVL = inserir(AVL, 'Y');
      AVL = inserir(AVL, 'T');
      AVL = inserir(AVL, 'M');
      AVL = inserir(AVL, 'E');
      AVL = inserir(AVL, 'W');
      AVL = inserir(AVL, 'X');
      AVL = inserir(AVL, 'S');
      AVL = inserir(AVL, 'F');
      AVL = inserir(AVL, 'G');
      AVL = inserir(AVL, 'A');
      AVL = inserir(AVL, 'H');
      AVL = inserir(AVL, 'N');
      AVL = inserir(AVL, 'O');
      AVL = inserir(AVL, 'P');
      AVL = inserir(AVL, 'R');
   */

   // AVL = remover (AVL, 'A');
   // AVL = remover (AVL, 'H');
   // AVL = remover (AVL, 'E');
   // AVL = remover (AVL, 'W');
   // AVL = remover (AVL, 'G');
   // AVL = remover (AVL, 'N');
   // AVL = remover (AVL, 'P');
   // AVL = remover (AVL, 'O');

   AVL = inserir(AVL, 14);
   AVL = inserir(AVL, 5);
   AVL = inserir(AVL, 28);
   AVL = inserir(AVL, 2);
   AVL = inserir(AVL, 8);
   AVL = inserir(AVL, 18);
   AVL = inserir(AVL, 33);
   AVL = inserir(AVL, 1);
   AVL = inserir(AVL, 3);
   AVL = inserir(AVL, 6);
   AVL = inserir(AVL, 11);
   AVL = inserir(AVL, 15);
   AVL = inserir(AVL, 20);
   AVL = inserir(AVL, 30);
   AVL = inserir(AVL, 38);
   AVL = inserir(AVL, 4);
   AVL = inserir(AVL, 7);
   AVL = inserir(AVL, 10);
   AVL = inserir(AVL, 12);
   AVL = inserir(AVL, 16);
   AVL = inserir(AVL, 19);
   AVL = inserir(AVL, 21);
   AVL = inserir(AVL, 29);
   AVL = inserir(AVL, 31);
   AVL = inserir(AVL, 35);
   AVL = inserir(AVL, 39);
   AVL = inserir(AVL, 13);
   AVL = inserir(AVL, 22);
   AVL = inserir(AVL, 32);
   AVL = inserir(AVL, 34);
   AVL = inserir(AVL, 36);
   AVL = inserir(AVL, 40);
   AVL = inserir(AVL, 37);
   imprimir_in_order(AVL, 0);

   AVL = remover(AVL, 1);

   printf("\n\n\n");
   imprimir_in_order(AVL, 0);

   return 0;
}
