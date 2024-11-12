#include "TABB.c"

TABB *maior(TABB *a){
    if(!a) return a;
    if(a->dir) return maior(a->dir);
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
    TABB *m = maior(a);
    x = m->info;
    printf("\n\n\n%d", x);
    TABB_libera(a);
    return 0;
}