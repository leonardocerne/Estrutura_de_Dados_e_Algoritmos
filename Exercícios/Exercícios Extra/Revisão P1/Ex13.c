/*
Duas ABBs s˜ ao SIMILARES se possuem a mesma distribuic¸˜ ao de n´ os (independente
 dos valores nos mesmos). Em uma definic ¸˜ ao mais formal, duas ABBs s˜ ao SIMILARES
 se s˜ ao ambas vazia, ou se suas sub´ arvores esquerdas s˜ ao similares, e suas sub´ arvores
 direitas tamb´ em s˜ ao similares. Implemente a func¸˜ ao que verifica se duas ´ arvores s˜ ao
 similares.
*/
#include "TABB.c"

int similares(TABB *a, TABB *b){
    if(!a && !b) return 1;
    if((a->esq && !b->esq) || (!a->esq && b->esq) || (a->dir && !b->dir) || (!a->dir && b->dir)) return 0;
    if(a->esq && !a->dir) return similares(a->esq, b->esq);
    else if(!a->esq && a->dir) return similares(a->dir, b->dir);
    return (similares(a->esq, b->esq) && similares(a->dir, b->dir));
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x,ver;
    TABB* raiz = NULL;
    TABB* outra = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir na primeira\n\t2 - Imprimir\n\t3 - Inserir na segunda\n\t4 - Imprimir a segunda\n\t5 - Verificar similaridade\n");
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
            printf("\n\tDigite o valor a ser inserido na arvore: ");
            scanf("%d", &x);
            printf("\n");
            outra = TABB_insere(outra,x);
            break;

        case 4:
            printf("\tA arvore eh: ");
            TABB_imp_ident(outra);
            printf("\n");
            break;

        case 5:
            ver = similares(raiz,outra);
            if(ver) printf("\n\tAs arvores sao similares");
            else printf("\n\tAs arvores NAO sao similarres");
            printf("\n");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TABB_libera(raiz);
    TABB_libera(outra);
    return 0;
}