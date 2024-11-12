#include "TAVL.h"

TAVL *rse(TAVL *p){
    TAVL *novo = p->dir;
    p->dir = novo->esq;
    novo->esq = p;
    return novo;
}

TAVL *rsd(TAVL *p){
    TAVL *novo = p->esq;
    p->esq = novo->dir;
    novo->dir = p;
    return novo;
}

TAVL *red(TAVL *p){
    p->esq = rse(p->esq);
    p = rsd(p);
    return p;
}

TAVL *rde(TAVL *p){
    p->dir = rsd(p->dir);
    p = rse(p);
    return p;
}

TAVL *TAVL_insere(TAVL *a, int x){
    if(!a) return TAVL_cria(x, NULL, NULL);
    if(a->info < x){
        a->dir = TAVL_insere(a->dir, x);
        if(fb(a) == -2){
            if(x > a->dir->info) a = rse(a);
            else a = rde(a);
        }
    }
    else if(a->info > x){
        a->esq = TAVL_insere(a->esq, x);
        if(fb(a) == 2){
            if(x < a->esq->info) a = rsd(a);
            else a = red(a);
        }
    }
    // calcula a->alt;
    return a;

}