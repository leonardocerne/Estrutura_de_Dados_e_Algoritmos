/*
Escreva um procedimento que receba o nome de um arquivo texto, cujo conteúdo são valores
inteiros e imprima na tela o número de vezes que cada elemento aparece e em quais linhas – void
resumo(char *Arq).
*/
#include "TG.c"

int tam(TG *g){
    int tam = 0;
    TVIZ *v = g->prim_viz;
    while(v){
        tam++;
        v = v->prox_viz;
    }
    return tam;
}

void resumo(char *Arq){
    FILE *fp = fopen(Arq, "r");
    if(!fp) exit(1);
    TG *g = NULL;
    int linha = 0, x;
    int r = fscanf(fp, "%d", &x);
    g = TG_ins_no(g, x);
    TG_ins_um_sentido(g, x, 0);
    while(r == 1){
        r = fscanf(fp, "%d", &x);
        if(!r) break;
        linha++;
        if(!TG_busca_no(g, x)){
            g = TG_ins_no(g, x);
        }
        TG_ins_um_sentido(g, x, linha);
    }
    while(g){
        printf("o numero %d aparece %d vezes\n", g->id_no, tam(g));
        printf("Nas linhas: ");
        TVIZ *v = g->prim_viz;
        while(v){
            printf("%d ", v->id_viz);
            v = v->prox_viz;
        }
        printf("\n");
        g = g->prox_no;
    }
    fclose(fp);
}

int main(void){
    resumo("entrada.txt");
    return 0;
}