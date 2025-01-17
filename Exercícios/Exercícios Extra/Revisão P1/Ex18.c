/*
Em um grafo, verifique se um nó ímpar só tem vizinhos pares, e vice versa
*/

#include "TG.c"

int imppar(TG *g){
    if(!g) return 0;
    TG *gr = g;
    while(gr){
        TVIZ *v = gr->prim_viz;
        if(gr->id_no % 2 == 0){
            while(v){
                if(v->id_viz % 2 == 0) return 0;
                v = v->prox_viz;
            }
        }
        else{
            while(v){
                if(v->id_viz % 2 != 0) return 0;
                v = v->prox_viz;
            }
        }
        gr = gr->prox_no;
    }
    return 1;
}

int main(void){
    int opcao, x, y, k, ver;
    TG* grafo = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir No\n\t2 - Inserir Aresta\n\t3 - Imprimir grafo\n\t4 - Verificar par impar\n");
        printf("\n");
        printf("\tDigite uma das opcoes acima: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("\n\tDigite o no a ser inserido no grafo: ");
            scanf("%d", &x);
            printf("\n");
            grafo = TG_ins_no(grafo,x);
            break;
        
        case 2:
            printf("\n\tDigite o no que deseja inserir a aresta: ");
            scanf("%d", &x);
            printf("\n");
            printf("\n\tDigite o no que deseja conectar com o no inserido: ");
            scanf("%d", &y);
            printf("\n");
            TG_ins_aresta(grafo,x,y);

        case 3:
            printf("\n\tO grafo eh: ");
            TG_imp_rec(grafo);
            printf("\n");
            break;
        case 4:
            ver = imppar(grafo);
            if(ver) printf("\n\t Todos os nos ímpares so tem vizinhos pares e vice versa");
            else printf("\n\t Os nos ímpares não tem vizinhos pares e vice versa");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    return 0;
}