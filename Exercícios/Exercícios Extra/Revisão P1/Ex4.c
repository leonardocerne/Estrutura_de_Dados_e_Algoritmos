/*
Faça uma função que recebe uma TAB e um índice M e um N, retorna uma lista com os elementos da TABB entre M e N, ordenada,
sem usar métodos de ordenação
*/

#include "TAB.c"
#include "TLSE.c"

TLSE *insere_ord(TLSE *l, int x){
    if((!l) || (x < l->info)) l = TLSE_insere(l, x);
    if(x > l->info) l->prox = insere_ord(l->prox, x);
    return l;
}

TLSE* percorre(TAB *a, TLSE *l, int m, int n){
    if(!a) return l;
    if((a->info > m) && (a->info < n)) l = insere_ord(l, a->info);
    l = percorre(a->esq, l, m, n);
    l = percorre(a->dir, l, m, n);
    return l;
}

TLSE *TAB2TLSE_MN(TAB *a, int m, int n){
    TLSE *l = NULL;
    l = percorre(a, l, m, n);
    return l;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x,n, m;
    TAB* raiz = NULL;
    TLSE* resp = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Lista ordenada entre M e N\n");
        printf("\n");
        printf("\tDigite uma das opcoes acima: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao){
        case 1:
            printf("\n\tDigite o valor a ser inserido na arvore: ");
            scanf("%d", &x);
            printf("\n");
            raiz = insere(raiz,x);
            break;
        
        case 2:
            printf("\tA arvore eh: ");
            TAB_imp_ident(raiz);
            printf("\n");
            break;
        
        case 3:
            printf("\n Insira os valores M e N");
            scanf("%d", &m);
            scanf("%d", &n);
            resp = TAB2TLSE_MN(raiz, m, n);
            TLSE_imp_rec(resp);
            free(resp);
            break;
        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TAB_libera(raiz);
    return 0;
}