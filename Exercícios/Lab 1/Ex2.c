#include "TAB.c"

int aux(TAB *a){
    if(!a) return 1;
    if(a->dir && a->esq) return 0;
    return (aux(a->esq) && aux(a->dir));
}

int zz(TAB *a){
    if(!a) return 0;
    return (aux(a->esq) && aux(a->dir));
}

int main(void){
    int opcao, x, resp;
    TAB* raiz = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Verificar se eh zig zag\n");
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
            raiz = insere(raiz,x);
            break;
        
        case 2:
            printf("\tA arvore eh: ");
            TAB_imp_ident(raiz);
            printf("\n");
            break;

        case 3:
            printf("\n");
            resp = zz(raiz);
            if(resp) printf("\nSim");
            else printf("\nNao");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TAB_libera(raiz);
    return 0;
}