/*
Faça uma função que recebe uma TABB e um índice M e um N, retorna um vetor com os elementos da TABB entre M e N, ordenado,
sem usar métodos de ordenação
*/
#include "TABB.c"

int tamanho(TABB *a, int m, int n){
    if(!a) return 0;
    if((a->info > m) && (a->info < n)) return 1 + tamanho(a->esq, m, n) + tamanho(a->dir, m, n);
    return tamanho(a->esq, m, n) + tamanho(a->dir, m, n);
}

void percorre(TABB *a, int *vet, int *index, int m, int n){
    if(!a) return;
    percorre(a->esq, vet, index, m, n);
    if((a->info > m) && (a->info < n)) vet[(*index)++] = a->info;
    percorre(a->dir, vet, index, m, n);
}

int* TABB2vet_MN(TABB *a, int m, int n){
    if(!a) return 0;
    int x = tamanho(a, m, n);
    int *vet = (int*)malloc(sizeof(int) * x);
    int index = 0;
    percorre(a, vet, &index, m, n);
    return vet;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x,n, m, tam, *resp;
    TABB* raiz = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Vetor ordenado entre M e N\n");
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
            printf("\n Insira os valores M e N");
            scanf("%d", &m);
            scanf("%d", &n);
            tam = tamanho(raiz, m, n);
            resp = TABB2vet_MN(raiz, m, n);
            printf("\n\tA lista ordenada com os elementos da arvore eh: \n");
            for(int i = 0; i < tam; i++) printf("Elemento %d: %d\n",i,resp[i]);
            printf("\n");
            free(resp);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TABB_libera(raiz);
    return 0;
}