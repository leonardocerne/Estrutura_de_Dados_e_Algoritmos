#include "TLSE.c"
#include "TABB.c"

TLSE *aux(TABB *a, int elem, TLSE *l){
    if(!a || a->info == elem) return l;
    l = TLSE_insere(l, a->info);
    if(a->info > elem) return aux(a->esq, elem, l);
    else return aux(a->dir, elem, l);
}

TLSE* ancestrais(TABB *a, int elem){
    TLSE *l = NULL;
    l = aux(a, elem, l);
    return l;
}

int main(void){
    int opcao, x, elem;
    TABB* raiz = NULL;
    TLSE *l = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Lista de valores maiores que N\n");
        printf("\n");
        printf("\tDigite uma das opcoes acima: ");
        scanf(" %d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("\n\tDigite o valor a ser inserido na arvore: ");
            scanf(" %d", &x);
            printf("\n");
            raiz = TABB_insere(raiz,x);
            break;
        
        case 2:
            printf("\tA arvore eh: ");
            TABB_imp_ident(raiz);
            printf("\n");
            break;

        case 3:
            printf("Insira o elemento que voce quer descobrir os ancestrais:\n");
            scanf("%d", &elem);
            l = ancestrais(raiz, elem);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TABB_libera(raiz);
    return 0;
}