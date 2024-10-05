#include "TAB.c"

int nf(TAB *a){
    if(!a) return 0;
    if(!a->esq && !a->dir) return 1 + nf(a->esq) + nf(a->dir);
    return nf(a->esq) + nf(a->dir);
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
    int resp = nf(a);
    printf("Sua arvore tem %d nos folha:\n", resp);
    TAB_libera(a);
    return 0;
}