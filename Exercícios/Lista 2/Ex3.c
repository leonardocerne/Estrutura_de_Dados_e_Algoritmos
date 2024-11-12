#include "TABB.c"

TABB *retiraImpar(TABB *a){
    if(!a) return a;
    TABB *tmp;
    if(a->esq) a->esq = retiraImpar(a->esq);
    if(a->dir) a->dir = retiraImpar(a->dir);
    if(a->info % 2 != 0){
        if((!a->esq) && (!a->dir)){
            free(a);
            return NULL;
        }
        else if((!a->esq) || (!a->dir)){
            tmp = a;
            if(a->dir) a = a->dir;
            else a = a->esq;
            free(tmp);
        }
        else{
            tmp = a->esq;
            TABB *pai = NULL;
            while(tmp->dir) {
                pai = tmp;
                tmp = tmp->dir;
            }
            a->info = tmp->info;
            if(pai) pai->dir = tmp->esq;
            else a->esq = tmp->esq;
            free(tmp);
            a = retiraImpar(a);
        }
    }
    return a;
}

int main(void){
    int x;
    TABB *a = TABB_inicializa();
    do{
        scanf("%d", &x);
        if(x < 0) break;
        a = TABB_insere(a, x);
    }while(1);
    printf("Arvore original\n");
    TABB_imp_sim(a);
    TABB *m = retiraImpar(a);
    printf("\n\nArvore sem impares\n");
    TABB_imp_sim(m);
    TABB_libera(m);
    return 0;
}