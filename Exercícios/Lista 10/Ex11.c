#include "TARVBM.c"

int igual(TARVBM *a1, TARVBM *a2){
    if((!a1) && (!a2)) return 1;
    if((!a1) || (!a2)) return 0;
    TARVBM *b1 = a1, *b2 = a2;
    while(b1->filho[0]) b1 = b1->filho[0];
    while(b2->filho[0]) b2 = b2->filho[0];
    while(b1 && b2){
        if(b1->nchaves != b2->nchaves) return 0;
        for(int i = 0; i < b1->nchaves; i++){
            if(b1->chave[i] != b2->chave[i]) return 0;
        }
        b1 = b1->prox;
        b2 = b2->prox;
    }
    if((b1) || (b2)) return 0;
    return 1;
}

int main(void){
  TARVBM *arvore = TARVBM_inicializa();
  TARVBM *segunda = TARVBM_inicializa();
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
  t = 0;
  x = 0;;
  printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
  scanf("%d", &t);
  if(t < 2) t = 2;
  num = 0, from, to;
  while(num != -1){
    printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
    scanf("%d", &num);
    if(num == -9){
      scanf("%d", &from);
      segunda = TARVBM_retira(segunda, from, t);
      TARVBM_imprime(segunda);
    }
    else if(num == -1){
      printf("\n");
      TARVBM_imprime(segunda);
      break;
    }
    else if(!num){
      printf("\n");
      TARVBM_imprime(segunda);
    }
    else segunda = TARVBM_insere(segunda, num, t);
    printf("\n\n");
  }
    int resp = igual(arvore,segunda);
    if(resp)printf("As arvores SAO IGUAIS!");
    else printf("As arvores NAO SAO iguais");
    TARVBM_libera(arvore);
    TARVBM_libera(segunda);
    return 0;
}