/*
(Q4) Escreva um código em C que, dados dois grafos G1 e G2, verifique se eles são isomórficos (retornando 1) ou não (retornando 0). Dois grafos G1 = {V1, E1} e G2 = {V2, E2} são isomórficos se:
1) Há uma correspondência um-para-um de V1 para V2; e
2) Há uma correspondência um-para-um de E1 para E2 que mapeia cada aresta de G1 para G2.
A função deve ter o seguinte protótipo: int iso(TG *G1, TG *G2);
*/

#include "TG.c"
#include "TLSEINT.c"

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

int contaarestas(TG *g){
    int tam = 0;
    TVIZ *v = g->prim_viz;
    while(v){
        tam++;
        v = v->prox_viz;
    }
    return tam;
}

int iso(TG *g1, TG *g2){
    if((!g1) || (!g2)) return 0;
    TG *a1 = g1, *a2 = g2;
    TG *tab = TG_inicializa();
    int nA;
    while(a1){
        a2 = g2;
        nA = contaarestas(a1);
        tab = TG_ins_no(tab, a1->id_no);
        while(a2){
            if(contaarestas(a2) == nA){
                TG_ins_um_sentido(tab, a1->id_no, a2->id_no);
            }
            a2 = a2->prox_no;
        }
        a1 = a1->prox_no;
    }
    TLSEINT *l = TLSEINT_inicializa();
    TLSEINT *li = l, *ll = l;
    a1 = tab;
    while(a1){
        if(contaarestas(a1) == 1){
            l = TLSEINT_insere(l, a1->id_no, a1->prim_viz->id_viz);
        }
        else{
            ll = l;
            TVIZ *v = a1->prim_viz;
            while((ll) && (!(ll->lim_sup != v->id_viz))) ll = ll->prox;
            if(!ll){
                l = TLSEINT_insere(l, a1->id_no, v->id_viz);
            }
            v = v->prox_viz;
        }
        a1 = a1->prox_no;
    }
    ll = l;
    while(ll){
        TG *gr = TG_busca_no(a2, ll->lim_sup);
        TVIZ *vi = gr->prim_viz;
        li = l;
        while(vi){
            while((li) && (li->lim_sup != vi->id_viz)) li = li->prox;
            vi->id_viz = li->lim_inf;
            vi = vi->prox_viz;
        }
        li = l;
        while((li) && (li->lim_inf != gr->id_no)) li = li->prox;
        gr->id_no = li->lim_inf;
        ll = ll->prox;
    }
    if(ig(g1, g2)) return 1;
    return 0;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver;
    TG* grafo = NULL;
    TG* segundo = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir No no primeiro\n\t2 - Inserir Aresta no primeiro\n\t3 - Inserir No no segundo\n\t4 - Inserir Aresta no segundo\n\t5 - Imprimir grafos\n\t6 - Verificar isomorfismo\n");
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