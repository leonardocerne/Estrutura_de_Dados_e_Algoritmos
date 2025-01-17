#include "TARVB.c"

int menor(TARVB *a){
    if(!a) return 0;
    int resp;
    while(a){
        resp = a->chave[0];
        a = a->filho[0];
    }
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
  int resp = menor(arvore);
  printf("\nmenor elemento: %d", resp);
  TARVB_Libera(arvore);
  return 0;
}