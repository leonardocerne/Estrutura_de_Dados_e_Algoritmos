#include "TAB.c"

TAB *grande(TAB *a){
    if(!a) return a;
    int esq, dir;
    TAB *esqA, *dirA;
    if(a->esq){
        esqA = grande(a->esq);
        esq = esqA->info;
    }
    else esq = 0;
    if(a->dir){
        dirA = grande(a->dir);
        dir = dirA->info;
    }
    else dir = 0;
    if(esq >= dir){
        if(a->info >= esq) return a;
        else return esqA;
    }
    else{
        if(a->info > dir) return a;
        else return dirA;
    }
}

int main(void){
    int x, n;
    printf("Insira a quantidade de valores da árvore");
    scanf("%d", &n);
    int vet[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        vet[i] = x;
    }
    
    TAB *a = vet2ab(vet, x);
    printf("Sua arvore original\n");
    TAB_imp_ident(a);
    TAB *b = grande(a);
    printf("maior número: %d \n", b->info);
    TAB_libera(a);
    return 0;
}