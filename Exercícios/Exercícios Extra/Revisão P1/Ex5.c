// Escreva uma função que verifica se uma TABB é AVL ou não, se sim retorna 1 e se não retorna 0
#include "TABB.c"

int TABB_AVL(TABB *a){
    if(!a) return 1;
    if((fb(a) > 1) || (fb(a) < -1)) return 0;
    return (TABB_AVL(a->esq) && TABB_AVL(a->dir));
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, resp;
    TABB* raiz = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Ver se e AVL\n");
        printf("\n");
        printf("\tDigite uma das opcoes acima: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao){
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
            resp = TABB_AVL(raiz);
            if(resp > 0) printf("\nE AVL");
            else printf("\nNao e AVL");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TABB_libera(raiz);
    return 0;
}