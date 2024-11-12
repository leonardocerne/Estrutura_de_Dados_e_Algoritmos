#include "TABB.c"

TABB *menor(TABB *a){
    if(!a) return a;
    if(a->esq) return menor(a->esq);
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
    TABB_imp_ident(a);
    TABB *m = menor(a);
    x = m->info;
    printf("\n\n\n%d", x);
    TABB_libera(a);
    return 0;
}