#include "TARVB.c"
#include <limits.h>

void percorre(TARVB *a, int elem, int *resp){
    if(!a) return;
    for(int i = 0; i < a->nchaves ; i++){
        if((a->chave[i] > elem) && (a->chave[i] < *resp)) *resp = a->chave[i];
        percorre(a->filho[i], elem, resp);
    }
}

int suc(TARVB *a, int elem){
    int resp = INT_MAX;
    percorre(a, elem, &resp);
    return resp;
}

int main(void){
  TARVB *arvore = TARVB_Inicializa();
  int t, x;
  printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
  scanf("%d", &t);
  if(t < 2) t = 2;
  int num = 0, from;
  while(num != -1){
    printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
    scanf("%d", &num);
    if(num == -9){
      scanf("%d", &from);
      arvore = TARVB_Retira(arvore, from, t);
      TARVB_Imprime2(arvore);
    }
    else if(num == -1){
      printf("\n");
      TARVB_Imprime2(arvore);
      break;
    }
    else if(!num){
      printf("\n");
      TARVB_Imprime2(arvore);
    }
    else arvore = TARVB_Insere(arvore, num, t);
    printf("\n\n");
  }
  printf("Digite o elemento que quer descobrir o sucessor:\n");
  scanf("%d", &x);
  int resp = suc(arvore, x);
  printf("\nsucessor: %d", resp);
  TARVB_Libera(arvore);
  return 0;
}