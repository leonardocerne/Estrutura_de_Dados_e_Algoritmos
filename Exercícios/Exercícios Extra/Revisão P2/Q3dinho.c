/*
3. Dado um conjunto de arquivos que contêm números inteiros, 
fazendo uso de tabela hash em memória secundária, o objetivo é 
armazenar num arquivo de saída apenas o números que aparecem 
uma quantidade ímpar de vezes. Para cada arquivo de dados, 
deve ser feita somente uma leitura. Cabeçalho da função: void 
misc(char **arqs, int num_arqs, char *saida); 
*/

#include "TH.c"
#include <stdlib.h>
#include <string.h>

void misc(char **arqs, int num_arqs, char *saida){
    int i, n, aux;
    printf("Digite tamanho da HASH");
    scanf("%d", &n);
    TH_inicializa("hash.bin", n);
    for(i = 0; i < num_arqs; i++){
        FILE *fp = fopen(arqs[i], "r");
        if(!fp) exit(1);
        while(fscanf(fp, "%d", &aux) == 1) TH_insere("hash.bin", "dados.bin", n, aux);
        fclose(fp);
    }
    i = 0;
    TH_imprime("hash.bin", "dados.bin", n);
    FILE *fh = fopen("hash.bin", "rb");
    while(i < n){
        int end;
        TNUM aux;
        fread(&end, sizeof(int), 1, fh);
        if(end != -1){
            FILE *fd = fopen("dados.bin", "rb");
            fseek(fd, end, SEEK_SET);
            fread(&aux, sizeof(TNUM), 1, fd);
            if(aux.qtde % 2 != 0){
                FILE *fs = fopen(saida, "at");
                fprintf(fs, "%d\n", aux.num);
                fclose(fs);
            }
            while(aux.prox != -1){
                fseek(fd, aux.prox, SEEK_SET);
                fread(&aux, sizeof(TNUM), 1, fd);
                if(aux.qtde % 2 != 0){
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
    int n;
    scanf("%d", &n);
    char **arqs = (char**)malloc(sizeof(char*) * n);
    for(int i = 0; i < n; i++){
        arqs[i] = (char*)malloc(sizeof(char) * 10);
        char tmp[10];
        scanf("%s", tmp);
        strcpy(arqs[i], tmp);
    }
    misc(arqs, n, "saida.txt");
}