/*
(Q4) verificar se o grafo, passado como parâmetro de entrada, possui todos os nós com grau
igual a k - int testek(TG *g, int k);
*/
#include "TG.c"

int testek(TG *g, int k){
    if(!g) return 0;
    TG *gr = g;
    int x = 0;
    while(gr){
        TG *tmp = g;
        x = 0;
        while(tmp){
            TVIZ *v = tmp->prim_viz;
            while(v){
                if(v->id_viz == gr->id_no) x++;
                v = v->prox_viz;
            }
            tmp = tmp->prox_no;
        }
        if(x != k) return 0;
        gr = gr->prox_no;
    }
    return 1;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y, k, ver;
    TG* grafo = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir No\n\t2 - Inserir Aresta\n\t3 - Imprimir grafo\n\t4 - Verificar grau\n");
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
            printf("\n\tDigite o grau que deseja testar: ");
            scanf("%d", &k);
            printf("\n");
            ver = testek(grafo, k);
            if(ver) printf("\n\t Todos os nos tem grau igual a k");
            else printf("\n\t Algum dos nos nao tem grau igual a k");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    return 0;
}