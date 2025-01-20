/*
4. Dada uma Árvore B+ qualquer, retorne, numa lista, todos os 
elementos menores que N. A função tem o seguinte protótipo: 
TLSE* mN(TARVBM *a, int N);
*/

#include "TARVBM.c"
#include "TLSE.c"

void percorre(TLSE **l, int N, TARVBM *a){
    if(!a) return;
    for(int j = a->nchaves; j >= 0; j--){
        percorre(l, N, a->filho[j]);
    }
    for(int i = a->nchaves-1; i >=0; i--){
        if((a->folha) && (a->chave[i] < N)) *l = TLSE_insere(*l, a->chave[i]);
    }
}

TLSE *mN2(TARVBM *a, int N){
    TLSE *l = NULL;
    percorre(&l, N, a);
    return l;
}

TLSE *mN(TARVBM *a, int N){
    TLSE *resp = NULL;
    while(a->filho[0]){
        a = a->filho[0];
    }
    while(a){
        for(int i = 0; i < a->nchaves; i++){
            if(a->chave[i] < N) resp = TLSE_insere(resp, a->chave[i]);
            else return resp;
        }
        a = a->prox;
    }
    return resp;
}

int main(void){
  TARVBM *arvore = TARVBM_inicializa();
  TLSE* lista = NULL;
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
  printf("Digite o valor n: ");
  scanf("%d", &x);
  lista = mN2(arvore,x);
  printf("A lista de maiores que %d eh: ",x);
  TLSE_imprime(lista);
  TLSE_libera(lista);
  TARVBM_libera(arvore);
  return 0;
}