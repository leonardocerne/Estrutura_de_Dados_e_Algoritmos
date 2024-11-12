#include "TABB.c"

int mNaux(TABB *a, int n){
    if(!a) return 0;
    if(a->info < n) return 1 + mNaux(a->esq, n) + mNaux(a->dir, n);
    return mNaux(a->esq, n) + mNaux(a->dir, n);   
}

void mNaux2(TABB *a, int *vet, int *in, int n){
    if(!a) return;
    mNaux2(a->esq, vet, in, n);
    if(a->info < n) vet[(*in)++] = a->info;
    mNaux2(a->dir, vet, in, n);
}

int *mN(TABB *a, int n){
    int tam = mNaux(a, n);
    int *resp = (int*)malloc(sizeof(int) * tam);
    int in = 0;
    mNaux2(a, resp, &in, n);
    return resp;
}
int main(void){
    int x, n;
    TABB *a = TABB_inicializa();
    do{
        scanf("%d", &x);
        if(x < 0) break;
        a = TABB_insere(a, x);
    }while(1);
    printf("Insira seu N:");
    scanf("%d", &n);
    printf("\nArvore original\n");
    TABB_imp_sim(a);
    int tam = mNaux(a, n);
    int *vet = mN(a, n);
    printf("\n valores menores que n:\n");
    for(int i = 0; i < tam; i++) printf("%d ", vet[i]);
    return 0;
}