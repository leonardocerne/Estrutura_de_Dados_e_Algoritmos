/*
Dado um Grafo, verificar se ele é bipartido int bipartido(TG *g);
*/
#include "TG.c"
#include "TLSE.c"

int bipartido(TG *g){
    if(!g) return 0;
    TLSE *x = NULL, *y = NULL;
    while(g){
        TVIZ *v = g->prim_viz;
        if(TLSE_busca(x, g->id_no)){
            while(v){
                if(TLSE_busca(x, v->id_viz)) {TLSE_libera(x); TLSE_libera(y); return 0;}
                if(!TLSE_busca(y, v->id_viz)){
                    y = TLSE_insere(y, v->id_viz);
                }
                v = v->prox_viz;
            }
        }
        else if(TLSE_busca(y, g->id_no)){
            while(v){
                if(TLSE_busca(y, v->id_viz)) {TLSE_libera(x); TLSE_libera(y); return 0;}
                if(!TLSE_busca(x, v->id_viz)){
                    x = TLSE_insere(x, v->id_viz);
                }
                v = v->prox_viz;
            }
        }
        else{
            while(v && !(TLSE_busca(x, v->id_viz)) && !(TLSE_busca(y, v->id_viz))) v = v->prox_viz;
            if(!v){
                x = TLSE_insere(x, g->id_no);
                v = g->prim_viz;
                while(v){
                    y = TLSE_insere(y, v->id_viz);
                    v = v->prox_viz;
                }
            }
            else if(TLSE_busca(x, v->id_viz)){
                y = TLSE_insere(y, g->id_no);
                v = g->prim_viz;
                while(v){
                    if(TLSE_busca(y, v->id_viz)) {TLSE_libera(x); TLSE_libera(y); return 0;}
                    else if(!TLSE_busca(x, v->id_viz)) x = TLSE_insere(x, v->id_viz);
                    v = v->prox_viz;
                }
            }
            else{
                x = TLSE_insere(x, g->id_no);
                v = g->prim_viz;
                while(v){
                    if(TLSE_busca(x, v->id_viz)) {TLSE_libera(x); TLSE_libera(y); return 0;}
                    else if(!TLSE_busca(y, v->id_viz)) y = TLSE_insere(y, v->id_viz);
                    v = v->prox_viz;
                }
            }
        }
        g = g->prox_no;
    }
    TLSE_libera(x); TLSE_libera(y);
    return 1;
}


int main(void){
    int opcao, x, y, k, ver;
    TG* grafo = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir No\n\t2 - Inserir Aresta\n\t3 - Imprimir grafo\n\t4 - Verificar se o grafo é bipartido\n");
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
            ver = bipartido(grafo);
            if(ver) printf("\n\t O grafo e bipartido");
            else printf("\n\t O grafo nao e bipartido");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    return 0;
}