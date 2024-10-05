#include "TAB.c"

TAB *copia(TAB *a){
    if(!a) return a;
    return TAB_cria(a->info, copia(a->esq), copia(a->dir));
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
    TAB *b = copia(a);
    printf("Sua arvore copia:\n");
    TAB_imp_ident(b);
    TAB_libera(a);
    TAB_libera(b);
    return 0;
}