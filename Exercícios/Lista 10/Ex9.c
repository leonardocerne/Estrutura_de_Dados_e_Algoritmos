#include "TARVBM.c"

int maior(TARVBM *a){
    TARVBM *b = a;
    while(b->filho[b->nchaves]) b = b->filho[b->nchaves];
    return b->chave[b->nchaves - 1];
}

int main(void){
  TARVBM *arvore = TARVBM_inicializa();
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
      arvore = TARVBM_retira(arvore, from, t);
      TARVBM_imprime(arvore);
    }
    else if(num == -1){
      printf("\n");
      TARVBM_imprime(arvore);
      break;
    }
    else if(!num){
      printf("\n");
      TARVBM_imprime(arvore);
    }
    else arvore = TARVBM_insere(arvore, num, t);
    printf("\n\n");
  }
  int resp = maior(arvore);
  printf("\nmaior: %d", resp);
  TARVBM_libera(arvore);
  return 0;
}