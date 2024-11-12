#include "TABB.h"

TABB *TABB_inicializa(void){
  return NULL;
}

TABB *TABB_cria(int raiz, TABB *esq, TABB *dir){
  TABB *novo = (TABB *) malloc(sizeof(TABB));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;
  return novo;
}

void TABB_imp_pre(TABB *a){
  if(a){
    printf("%d ", a->info);
    TABB_imp_pre(a->esq);
    TABB_imp_pre(a->dir);
  }
}

void TABB_imp_pos(TABB *a){
  if(a){
    TABB_imp_pos(a->esq);
    TABB_imp_pos(a->dir);
    printf("%d ", a->info);
  }
}

void TABB_imp_sim(TABB *a){
  if(a){
    TABB_imp_sim(a->esq);
    printf("%d ", a->info);
    TABB_imp_sim(a->dir);
  }
}

void imp_aux(TABB *a, int andar){
  int j;
  if(a){
    imp_aux(a->dir, andar + 1);
    for(j = 0; j <= andar; j++) printf("\t"); //printf("   ");
    printf("%d\n", a->info);
    imp_aux(a->esq, andar + 1);
  }
  else{
   for(j = 0; j <= andar; j++) printf("\t");
   printf("N\n");
  }
}

void TABB_imp_ident(TABB *a){
  imp_aux(a, 0);
}

void TABB_libera(TABB *a){
  if(a){
    TABB_libera(a->esq);
    TABB_libera(a->dir);
    free(a);
  }
}

TABB *TABB_busca(TABB *a, int elem){
  if((!a) || (a->info == elem)) return a;
  if(a->info > elem) return TABB_busca(a->esq, elem);
  return TABB_busca(a->dir, elem);
}

TABB *TABB_insere(TABB *a, int elem){
  if(!a) return TABB_cria(elem, NULL, NULL);
  if(a->info > elem) a->esq = TABB_insere(a->esq, elem);
  else if (a->info < elem) a->dir = TABB_insere(a->dir, elem);
  return a;
}

TABB *retira(TABB *a, int x){
    if(!a) return a;
    if(a->info > x) a->esq = retira(a->esq, x);
    else if (a->info < x) a->dir = retira(a->dir, x);
    else{
        // 1 caso : é folha
        if((!a->esq) && (!a->dir)){
            free(a);
            a = NULL;
        }
        // 2 caso: tem um filho so
        else if((!a->esq) || (!a->dir)){
            TABB *tmp = a;
            if(a->esq) a = a->esq;
            else a = a->dir;
            free(tmp);
        }
        // 3 caso: tem 2 filhos
        else{
            TABB *f = a->esq;
            while(f->dir) f = f->dir;
            a->info = f->info;
            f->info = x;
            a->esq = retira(a->esq, x);
        }
    }
    return a;
}

int maior(int x, int y){
  if(x >= y) return x;
  return y;
}

int TABB_altura(TABB *a){
  if(!a) return -1;
  return maior(TABB_altura(a->esq), TABB_altura(a->dir)) + 1;
}

int fb(TABB *a){
  return TABB_altura(a->esq) - TABB_altura(a->dir);
}

