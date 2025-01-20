/*
3. Dado um conjunto de arquivos que contêm números inteiros, e uma porcentagem,
fazendo uso de tabela hash em memória secundária, o objetivo é 
armazenar num arquivo de saída apenas o números que sao multiplos dessa porcentagem. Para cada arquivo de dados, 
deve ser feita somente uma leitura. Cabeçalho da função: void 
misc(char **arqs, int num_arqs,int porc, char *saida); 
*/
#include "TH.c"
#include <string.h>

void misc(char **arqs, int num_arqs, int porc, char *saida){
    int x, n;
    printf("Digite tamanho da HASH ");
    scanf("%d", &n);
    TH_inicializa("hash.bin", n);
    for(int i = 0; i < num_arqs; i++){
        FILE *fp = fopen(arqs[i], "r");
        if(!fp) exit(1);
        while(fscanf(fp, "%d", &x) == 1) TH_insere("hash.bin", "dados.bin", n, x);
        fclose(fp);
    }
    TH_imprime("hash.bin", "dados.bin", n);
    int i = 0;
    FILE *fh = fopen("hash.bin", "rb");
    while(i < n){
        int end;
        TNUM aux;
        fread(&end, sizeof(int), 1, fh);
        if(end != -1){
            FILE *fd = fopen("dados.bin", "rb");
            fseek(fd, end, SEEK_SET);
            fread(&aux, sizeof(TNUM), 1, fd);
            float div = (float)aux.qtde / num_arqs;
            float porc_atual = div * 100;
            int porcreal = (int)porc_atual;
            if(porc_atual >= porc){
                FILE *fs = fopen(saida, "at");
                fprintf(fs, "%d\n", aux.num);
                fclose(fs);
            }
            while(aux.prox != -1){
                fseek(fd, aux.prox, SEEK_SET);
                fread(&aux, sizeof(TNUM), 1, fd);
                float div = (float)aux.qtde / num_arqs;
                float porc_atual = div * 100;
                porcreal = (int)porc_atual;
                if(porc_atual >= porc){
                    FILE *fs = fopen(saida, "at");
                    fprintf(fs, "%d\n", aux.num);
                    fclose(fs);
                }
            }
            fclose(fd);
        }
        i++;
    }
    fclose(fh);
}

int main(void){
    int n, porc;
    printf("Digite o numero de arquivos: ");
    scanf("%d", &n);
    char **arqs = (char**)malloc(sizeof(char*) * n);
    printf("\nDigite o nome de cada arquivo: ");
    for(int i = 0; i < n; i++){
        arqs[i] = (char*)malloc(sizeof(char) * 10);
        char tmp[10];
        scanf("%s", tmp);
        strcpy(arqs[i], tmp);
    }
    printf("\nDigite a porcentagem a ser analisada");
    scanf("%d", &porc);
    misc(arqs, n, porc, "saida.txt");
    return 0;
}