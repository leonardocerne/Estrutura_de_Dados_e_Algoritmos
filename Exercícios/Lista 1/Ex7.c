#include <stdio.h>
#include <stdlib.h>

typedef struct arvbincor{
    int info;
    struct arvbincor *esq, *dir;
    int cor;
}TAB_cor;

#define BRANCO 0
#define PRETO 1
#define VERMELHO 2

void colore(TAB_cor *a){
    if(!a) return;
    if(a->cor == BRANCO) a->cor = PRETO;
    if(a->cor == PRETO){
        if(a->esq) a->esq->cor = VERMELHO;
        if(a->dir) a->dir->cor = VERMELHO;
    }
    else{
        if(a->esq) a->esq->cor = PRETO;
        if(a->dir) a->dir->cor = PRETO;
    }
    colore(a->esq);
    colore(a->dir);
    return;
}


TAB_cor* insere(TAB_cor* a, int x){
    if(!a){
        TAB_cor* novo = (TAB_cor*)malloc(sizeof(TAB_cor));
        novo ->info = x;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->cor = BRANCO;
        return novo;
    } 
    if(x > a->info) a->dir = insere(a->dir,x);
    if(x < a->info) a->esq = insere(a->esq,x);
    return a;
}

void imprime_colorido(TAB_cor* a){
    if(!a) return;
    imprime_colorido(a->esq);
    printf("No: %d pintado de %d",a->info,a->cor);
    printf("\n");
    imprime_colorido(a->dir);
}

void imprime(TAB_cor*a){
    if(!a) return;
    imprime(a->esq);
    printf("%d",a->info);
    imprime(a->dir);
    return;
}

void libera(TAB_cor*a){
    if(!a) return ;
    libera(a->esq);
    free(a);
    libera(a->dir);
    return;
}

void imp_aux(TAB_cor *a, int andar){
  int j;
  if(a){
    imp_aux(a->dir, andar + 1);
    for(j = 0; j <= andar; j++) printf("\t"); //printf("   ");
    printf("%d\n", a->cor);
    imp_aux(a->esq, andar + 1);
  }
  else{
   for(j = 0; j <= andar; j++) printf("\t");
   printf("N\n");
  }
}

void TAB_cor_imp_ident(TAB_cor *a){
  imp_aux(a, 0);
}


int main(void){
    int x;
    TAB_cor *a = NULL;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        a = insere(a, x);
    }while(1);
    colore(a);
    TAB_cor_imp_ident(a);
    libera(a);
    return 0;
}