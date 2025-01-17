#include "TARVBM.c"
#include "TLSE.c"

TLSE *insere_pares(TARVBM *a, TLSE *l){
    TARVBM *b = a;
    while(b->filho[0]) b = b->filho[0];
    while(b){
        for(int i = 0; i < b->nchaves; i++){
            if(b->chave[i] % 2 == 0) l = TLSE_insere(l, b->chave[i]);
        }
        b = b->prox;
    }
    return l;
}

TARVBM *retira_pares(TARVBM *a, int t){
    if(!a) return a;
    TLSE *l = NULL;
    l = insere_pares(a, l);
    while(l){
        a = TARVBM_retira(a, l->info, t);
        l = l->prox;
    }
    TLSE_libera(l);
    return a;
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
  arvore = retira_pares(arvore, t);
  printf("\nAqui esta a arvore sem pares:\n");
  TARVBM_imprime(arvore);
  TARVBM_libera(arvore);
  return 0;
}