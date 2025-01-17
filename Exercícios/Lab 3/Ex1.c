/*
(Q1) Uma função em C que, dada uma árvore B qualquer, retorne, numa lista, todos os elementos maiores que N. 
A função deve ter o seguinte protótipo: TLSE* mN(TARVB*a, int N);
*/
#include "TLSE.c"
#include "TARVB.c"

TLSE *insere_ordenado(TLSE *l, int N){
    if((!l) || (N < l->info)) l = TLSE_insere(l, N);
    else l->prox = insere_ordenado(l->prox, N);
    return l;
}

void percorre(TARVB *a, int N, TLSE **l){
    if(!a) return;
    for(int i = 0; i < a->nchaves; i++){
        if(a->chave[i] > N) *l = insere_ordenado(*l, a->chave[i]);
    }
    int j;
    for(j = 0; (j < a->nchaves) && (a->chave[j] < N); j++);
    if(j <= a->nchaves)
        for(j; j < a->nchaves+1; j++) percorre(a->filho[j], N, l);
    
}

TLSE *mN(TARVB *a, int N){
    TLSE *l = TLSE_inicializa();
    percorre(a, N, &l);
    return l;
}

int main(void){
  TARVB *arvore = TARVB_Inicializa();
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
  lista = mN(arvore,x);
  printf("A lista de maiores que %d eh: ",x);
  TLSE_imprime(lista);
  TLSE_libera(lista);
  TARVB_Libera(arvore);
  return 0;
}