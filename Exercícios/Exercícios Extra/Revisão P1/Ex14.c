/*
Escreva uma func ¸˜ ao recursiva que retorne o k-´ esimo menor valor de uma ´ arvore
 bin´ aria de busca
*/
#include "TABB.c"

int tam(TABB *a){
    if(!a) return 0;
    return 1 + tam(a->esq) + tam(a->dir);
}

void percorre(TABB *a, int *vet, int *in){
    if(!a) return;
    percorre(a->esq, vet, in);
    vet[(*in)++] = a->info;
    percorre(a->dir, vet, in);
}

int kmenor(TABB *a, int k){
    if(!a) return 0;
    int tamanho = tam(a);
    int index = 0;
    int *vet = (int*)malloc(sizeof(int) * tamanho);
    percorre(a, vet, &index);
    return vet[k];
}

int main(void){
    int opcao, x,resp, k;
    TABB* raiz = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Verificar k-ésimo menor valor\n");
        printf("\n");
        printf("\tDigite uma das opcoes acima: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("\n\tDigite o valor a ser inserido na arvore: ");
            scanf("%d", &x);
            printf("\n");
            raiz = TABB_insere(raiz,x);
            break;
        
        case 2:
            printf("\tA arvore eh: ");
            TABB_imp_ident(raiz);
            printf("\n");
            break;

        case 3:
            printf("\tDigite o k:\n");
            scanf("%d", &k);
            resp = kmenor(raiz, k-1);
            printf("%d", resp);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);

    TABB_libera(raiz);
    return 0;
}