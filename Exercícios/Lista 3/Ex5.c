//(Q5) testar se dois grafos são iguais - int ig(TG *g1, TG *g2).
#include "TG.c"

int nn(TG *g){
    if(!g) return 0;
    int x = 0;
    while(g){
        x++;
        g = g->prox_no;
    }
    return x;
}

int na(TG *g){
    if(!g) return 0;
    int x = 0;
    while(g){
        TVIZ *v = g->prim_viz;
        while(v){
            x++;
            v = v->prox_viz;
        }
        g = g->prox_no;
    }
    return x;
}

int ig(TG *g1, TG *g2){
    if((!g1) || (!g2)) return 0;
    if(nn(g1) != nn(g2)) return 0;
    if(na(g1) != na(g2)) return 0;
    TG *gr1 = g1;
    while(gr1){
        if(!TG_busca_no(g2, gr1->id_no)) return 0;
        TVIZ *v1 = gr1->prim_viz;
        while(v1){
            if(!TG_busca_aresta(g2, gr1->id_no, v1->id_viz)) return 0;
            v1 = v1->prox_viz;
        }
        gr1 = gr1->prox_no;
    }
    return 1;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver;
    TG* grafo = NULL;
    TG* segundo = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir No no primeiro\n\t2 - Inserir Aresta no primeiro\n\t3 - Inserir No no segundo\n\t4 - Inserir Aresta no segundo\n\t5 - Imprimir grafos\n\t6 - Verificar igualdade\n");
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
            printf("\n\tDigite o no a ser inserido no grafo: ");
            scanf("%d", &x);
            printf("\n");
            segundo = TG_ins_no(segundo,x);
            break;
        case 4:
            printf("\n\tDigite o no que deseja inserir a aresta: ");
            scanf("%d", &x);
            printf("\n");
            printf("\n\tDigite o no que deseja conectar com o no inserido: ");
            scanf("%d", &y);
            printf("\n");
            TG_ins_aresta(segundo,x,y);
            break;
        case 5:
            printf("\n\tOs grafos: ");
            printf("\n\tPrimeiro grafo:");
            TG_imp_rec(grafo);
            printf("\n");
            printf("\n\tSegundo grafo:");
            TG_imp_rec(segundo);
            printf("\n");
            break;
        case 6:
            ver = ig(grafo,segundo);
            if(ver) printf("\n\t Os grafos sao iguais!!!");
            if(!ver) printf("\n\t Os grafos nao sao iguais :( ");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    TG_libera(segundo);
    return 0;
}