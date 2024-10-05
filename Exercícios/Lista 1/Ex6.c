#include "TAB.c"

TAB *retpares(TAB *a){
    if(!a) return a;
    if(a->esq) a->esq = retpares(a->esq);
    if(a->dir) a->dir = retpares(a->dir);
    if(a->info % 2 == 0){
        if(!a->esq && !a->dir){
            free(a);
            return NULL;
        }
        if (!a->esq) {
            TAB *tmp = a->dir;
            free(a);
            return tmp;
        }
        if (!a->dir) {
            TAB *tmp = a->esq;
            free(a);
            return tmp;
        }
        TAB *troca = a->esq, *pai = NULL;
        while(troca->dir){
            pai = troca;
            troca = troca->dir;
        }
        a->info = troca->info;
        if(pai) pai->dir = troca->esq;
        else a->esq = troca->esq;
        free(troca);
        a = retpares(a);
    }
    return a;
}

int main(void){
    int x, n;
    printf("Insira a quantidade de valores da árvore");
    scanf("%d", &n);
    int *vet = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        vet[i] = x;
    }
    
    TAB *a = vet2ab(vet, n);
    printf("Sua arvore original\n");
    TAB_imp_ident(a);
    TAB *b = retpares(a);
    printf("Sua arvore modificada:\n");
    TAB_imp_ident(b);
    TAB_libera(a);
    TAB_libera(b);
    return 0;
}