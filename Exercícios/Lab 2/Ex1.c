/*
(Q1) Uma função em C que, dada uma árvore de busca binária qualquer, retorne, numa lista,
 todos os elementos maiores que N. A função deve ter o seguinte protótipo: TLSE* mN(TABB*a, int N);
*/
#include "TABB.c"
#include "TLSE.c"

void percorre(TABB *a, int N, TLSE **resp){
    if(!a) return;
    percorre(a->esq, N, resp);
    if(a->info > N) *resp = TLSE_insere(*resp, a->info);
    percorre(a->dir, N, resp);
}

TLSE *mN(TABB *a, int N){
    if(!a) return NULL;
    TLSE *resp = NULL;
    percorre(a, N, resp);
    return resp;
}

int main(void){
    int opcao, x,ver, N;
    TABB* raiz = NULL;
    TLSE *resp = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Lista com maiores que N\n");
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
            printf("\t\n Digite o N:");
            scanf("%d", &N);
            resp = mN(raiz, N);
            TLSE_imprime(resp);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TABB_libera(raiz);
    return 0;
}