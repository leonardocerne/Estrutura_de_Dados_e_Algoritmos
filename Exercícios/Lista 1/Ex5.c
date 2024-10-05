#include "TAB.c"

int igual(TAB *a, TAB *b){
    if((!a) && (!b)) return 1;
    if(((!a) || (!b)) || (a->info != b->info)) return 0;
    int resp = igual(a->esq, b->esq);
    if(resp == 0) return 0;
    resp = igual(a->dir, b->dir);
    if(resp == 0) return 0;
    return 1;
}

int main(void){
    int x, n1, n2;
    printf("Insira a quantidade de valores da arvore: ");
    scanf("%d", &n1);
    int *vet = (int*)malloc(sizeof(int) * n1);
    for(int i = 0; i < n1; i++){
        scanf("%d", &x);
        vet[i] = x;
    }
    printf("\nInsira a quantidade de valores da arvore 2: ");
    scanf("%d", &n2);
    int *vet2 = (int*)malloc(sizeof(int) * n2);
    for(int g = 0; g < n2; g++){
        scanf("%d", &x);
        vet2[g] = x;
    }
    TAB *a = vet2ab(vet, n1);
    TAB *b = vet2ab(vet2, n2);
    printf("Sua arvore original\n");
    TAB_imp_ident(a);
    printf("\nSua arvore 2 original\n");
    TAB_imp_ident(b);
    int resp = igual(a, b);
    if(resp == 0) printf("Sao diferentes");
    else printf("Sao iguais");
    TAB_libera(a);
    TAB_libera(b);
    return 0;
}