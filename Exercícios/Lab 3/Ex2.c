/*
(Q2) Retornar todas as informações ancestrais de um nó na árvore B, da 
raiz da árvore até o elemento passado como parâmetro, usando a biblioteca de lista encadeada - TLSEINT* misc(TARVB *a, int elem), onde:
*/

#include "TLSEINT.c"
#include "TARVB.c"
#include <limits.h>

void percorre(TARVB *a, int elem, TLSEINT **l){
    if(!a) return;
    int i;
    for(i = 0; (i < a->nchaves) && (a->chave[i] < elem); i++);
    if(a->chave[i] == elem){
        if(a->nchaves == 1) *l = TLSEINT_insere(*l, INT_MIN, INT_MAX);
        else if(i == a->nchaves-1) *l = TLSEINT_insere(*l, a->chave[i-1], INT_MAX);
        else if(i == 0) *l = TLSEINT_insere(*l, INT_MIN, a->chave[i+1]);
        else *l = TLSEINT_insere(*l, a->chave[i-1], a->chave[i+1]);
    }
    else {
        if(i == a->nchaves) *l = TLSEINT_insere(*l, a->chave[i-1], INT_MAX);
        else if(i == 0) *l = TLSEINT_insere(*l, INT_MIN, a->chave[0]);
        else *l = TLSEINT_insere(*l, a->chave[i-1], a->chave[i]);
    }
    percorre(a->filho[i], elem, l);
}

TLSEINT *misc(TARVB *a, int elem){
    TLSEINT *l = TLSEINT_inicializa();
    percorre(a, elem, &l);
    return l;
}

int main(void){
  TARVB *arvore = TARVB_Inicializa();
  TLSEINT* lista = NULL;
  int t, x;
  printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
  scanf("%d", &t);
  if(t < 2) t = 2;
  int num = 0, from, to;
  while(num != -1){
    printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
    scanf("%d", &num);
    if(num == -9){
      scanf("%d", &from);
      arvore = TARVB_Retira(arvore, from, t);
      TARVB_Imprime(arvore);
    }
    else if(num == -1){
      printf("\n");
      TARVB_Imprime(arvore);
      break;
    }
    else if(!num){
      printf("\n");
      TARVB_Imprime(arvore);
    }
    else arvore = TARVB_Insere(arvore, num, t);
    printf("\n\n");
  }
  printf("Digite o valor n: ");
  scanf("%d", &x);
  lista = misc(arvore,x);
  printf("A lista de ancestrais de %d eh: ",x);
  TLSEINT_imprime(lista);
  TLSEINT_libera(lista);
  TARVB_Libera(arvore);
  return 0;
}