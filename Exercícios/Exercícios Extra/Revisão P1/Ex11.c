// Verifique se uma tab e tabb
#include "TAB.c"

int TAB_TABB(TAB *a){
    if(!a) return 1;
    if((a->esq) && (a->info < a->esq->info)) return 0;
    if((a->dir) && (a->info > a->dir->info)) return 0;
    return TAB_TABB(a->esq) && TAB_TABB(a->dir);
}


int main(void){
    int opcao, x, N, resp;
    TAB* raiz = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Verificar Estritamente Binaria\n");
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
            raiz = insere(raiz,x);
            break;
        
        case 2:
            printf("\tA arvore eh: ");
            TAB_imp_ident(raiz);
            printf("\n");
            break;

        case 3:
            resp = TAB_TABB(raiz);
            printf("%d", resp);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);

    TAB_libera(raiz);
    return 0;
}