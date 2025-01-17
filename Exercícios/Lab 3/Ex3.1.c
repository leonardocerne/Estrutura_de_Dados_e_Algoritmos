/*
(Q1) Uma função em C que, dada uma árvore B qualquer, retorne, numa lista, todos os elementos maiores que N. 
A função deve ter o seguinte protótipo: TLSE* mN(TARVBM*a, int N);
*/
#include "TARVBM.c"
#include "TLSE.c"

TLSE *mN(TARVBM *a, int N){
    TLSE *l = TLSE_inicializa();
    TARVBM *f = TARVBM_busca(a, N);
    while(f){
        for(int i = 0; i < f->nchaves; i++){
            if(f->chave[i] > N) l = TLSE_insere(l, f->chave[i]);
        }
        f = f->prox;
    }
    return l;
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
  lista = mN(arvore,x);
  printf("A lista de maiores que %d eh: ",x);
  TLSE_imprime(lista);
  TLSE_libera(lista);
  TARVBM_libera(arvore);
  return 0;
}