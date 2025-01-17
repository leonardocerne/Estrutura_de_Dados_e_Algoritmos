/*
Fac ¸a uma func¸˜ ao que retorne a quantidade de n´ os de uma ´ arvore bin´ aria de busca que
 possuem apenas um filho
*/

#include "TABB.c"

int umfilho(TABB *a){
    if(!a) return 0;
    if((a->esq && !a->dir) || (!a->esq && a->dir)) return 1 + umfilho(a->esq) + umfilho(a->dir);
    return umfilho(a->esq) + umfilho(a->dir);
}

int main(void){
    int opcao, x,resp, k;
    TABB* raiz = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Verificar nos com um filho\n");
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
            resp = umfilho(raiz);
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