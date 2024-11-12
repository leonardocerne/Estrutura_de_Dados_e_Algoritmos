// Faça uma função que recebe uma TABB e retorna um vetor ordenado, sem usar métodos de ordenação
#include "TABB.c"

int tamanho(TABB *a){
    if(!a) return 0;
    return 1 + tamanho(a->esq) + tamanho(a->dir);
}

void percorre(TABB *a, int *vet, int *index){
    if(!a) return;
    percorre(a->esq, vet, index);
    vet[(*index)++] = a->info;
    percorre(a->dir, vet, index);
}

int* TABB2vet_ord(TABB *a){
    if(!a) return 0;
    int x = tamanho(a);
    int *vet = (int*)malloc(sizeof(int) * x);
    int index = 0;
    percorre(a, vet, &index);
    return vet;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x,n, *resp;
    TABB* raiz = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Vetor ordenado\n");
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
            n = tamanho(raiz);
            resp = TABB2vet_ord(raiz);
            printf("\n\tA lista ordenada com os elementos da arvore eh: \n");
            for(int i = 0; i < n; i++) printf("Elemento %d: %d\n",i,resp[i]);
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