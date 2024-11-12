/*
Q2 - Verificar se as condições estabelecidas no enunciado são respeitadas, caso sim, retore 1, caso não, retorne 0. int teste(TABB* a);

1 - Todos os nós folhas devem estar no mesmo nivel.
2 - Todos os nós de altura {0, 3, 6, 9 ...} devem ser ou folha ou pai de dois filhos.
3 - Todos os nós de altura {1, 4, 7, 10 ...} devem ter somente um filho a esquerda.
4 - Todos os nós de altura {2, 5, 8, 11 ...} devem ter somente um filho a direita.
*/

#include "TABB.c"

TABB *achafolha(TABB *a){
    if(!a->dir && !a->esq) return a;
    if(a->esq) return achafolha(a->esq);
    return achafolha(a->dir);
}

int teste2(TABB *a){
    if(!a) return 1;
    else if(TABB_altura(a) % 3 == 0){
        if((a->dir && !a->esq) || (!a->dir && a->esq)) return 0;
    }
    else if((TABB_altura(a) - 1) % 3 == 0){
        if(a->dir || (!a->esq && !a->dir)) return 0;
    }
    else if((TABB_altura(a) - 2) % 3 == 0){
        if(a->esq || (!a->esq && !a->dir)) return 0;
    }
    return (teste2(a->esq) && teste2(a->dir));
}


int nivel(TABB *a, TABB *b){
    if((a->info == b->info) || !a) return 0;
    if(a->info > b->info) return nivel(a->esq, b) + 1;
    return nivel(a->dir, b) + 1;
}

int teste3(TABB *a, TABB *b, int x){
    if(!a) return 1;
    if(!a->esq && !a->dir){
        int y = nivel(b, a);
        if(y != x) return 0;
    }
    return(teste3(a->esq, b, x) && teste3(a->dir, b, x));
}

int teste(TABB *a){
    if(!a) return 0;
    TABB *f = achafolha(a);
    int x = nivel(a, f);
    if(teste3(a, a, x) && teste2(a)) return 1;
    return 0;
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
            resp = teste(raiz);
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