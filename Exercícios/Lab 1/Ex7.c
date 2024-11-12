//Dado um grafo conectado, verifique se ele pode ser transformado em uma árvore binária. Se ele pode ser uma árvore binária, retorne um. Se não, retorne zero. DICA: use TLSE para resolver esta questão: int teste (TG *g); 
#include "TLSE.c"
#include "TG.c"

int tamanhoviz(TG *g){
    TVIZ *v = g->prim_viz;
    int tam = 0;
    while(v){
        tam++;
        v = v->prox_viz;
    }
    return tam;
}

int testeciclo(TG *g){
    TG *gr = g;
    while(gr){
        TLSE *l = NULL;
        l = TLSE_insere(l, gr->id_no);
        TVIZ *f = gr->prim_viz;
        int pai = gr->id_no;
        while(f){
            TG *filho = TG_busca_no(g, f->id_viz);
            TVIZ *filhov = filho->prim_viz;
            while(filhov){
                if((filhov->id_viz != pai) && (TLSE_busca(l, filhov->id_viz))) return 0;
                else if((filhov->id_viz != pai) && (!TLSE_busca(l, filhov->id_viz))){
                    l = TLSE_insere(l, filhov->id_viz);
                    filhov = filhov->prox_viz;
                }
                else filhov = filhov->prox_viz;
            }
            l = TLSE_insere(l, f->id_viz);
            f = f->prox_viz;
        }
        gr = gr->prox_no;
        TLSE_libera(l);
    }
    return 1;
}


int teste(TG *g){
    if(!g) return 0;
    TG *gr = g;
    while(gr){
        if(tamanhoviz(gr) > 3) return 0;
        gr = gr->prox_no;
    }
    return testeciclo(g);
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver;
    TG* grafo = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir No\n\t2 - Inserir Aresta\n\t3 - Imprimir grafo\n\t4 - Verificador Arvore\n");
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
            break;

        case 3:
            printf("\n\tO grafo eh:\n0 ");
            TG_imprime(grafo);
            printf("\n");
            break;
        case 4:
            ver = teste(grafo);
            if(ver) printf("\n\tO grafo pode ser arvore");
            else printf("\n\tO grafo NAO pode ser arvore");
            printf("\n");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    return 0;
}