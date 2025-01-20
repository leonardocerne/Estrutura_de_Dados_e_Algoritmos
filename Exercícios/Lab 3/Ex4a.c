/*
(Q4) Dados dois arquivos texto que representam conjuntos inteiros (isto é, não há elementos repetidos nos arquivos), um elemento por linha, e fazendo SOMENTE uma leitura em cada arquivo, faça cada uma das questões utilizando tabelas hash em memória secundária:
(a) interseção dos conjuntos: void inter(char* arq1, char* arq2, char* saida);

(b) diferença simétrica de conjuntos: void dif_sim(char* arq1, char* arq2, char* saida);

(c) união de conjuntos: void uniao(char* arq1, char* arq2, char* saida);

(d) Elimine as repetições de números em um arquivo usando hashing, e sem copiar TODOS os elementos para a memória principal: void elim_repet (char *repet, char *novo);
*/
#include "TH.c"
//(b)
void dif_sim(char *arq1, char *arq2, char *saida){
    FILE *fp1 = fopen(arq1, "r"), *fp2 = fopen(arq2, "r"), *fpw = fopen(saida, "w");
    if((!fp1) || (!fp2) || (!fpw)) exit(1);
    int aux, n;
    printf("Digite o tamanho da tabela HASH:");
    scanf("%d", &n);
    TH_inicializa("hash.bin", n);
    while(fscanf(fp1, "%d", &aux) == 1) TH_insere("hash.bin", "dados.bin", n, aux);
    while(fscanf(fp2, "%d", &aux) == 1) TH_insere("hash.bin", "dados.bin", n, aux);
    fclose(fp1);
    fclose(fp2);
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
            if(aux.qtde == 1) {
                FILE *fs = fopen(saida, "at");
                fprintf(fs, "%d\n", aux.num);
                fclose(fs);
            }
            while(aux.prox != -1){
                fseek(fd, aux.prox, SEEK_SET);
                fread(&aux, sizeof(TNUM), 1, fd);
                if(aux.qtde == 1) {
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
//(a)
void inter(char* arq1, char* arq2, char* saida){
    FILE *fp1 = fopen(arq1, "r"), *fp2 = fopen(arq2, "r"), *fpw = fopen(saida, "w");
    if((!fp1) || (!fp2) || (!fpw)) exit(1);
    int aux, n;
    printf("Digite o tamanho da tabela HASH:");
    scanf("%d", &n);
    TH_inicializa("hash.bin", n);
    while(fscanf(fp1, "%d", &aux) == 1) TH_insere("hash.bin", "dados.bin", n, aux);
    fclose(fp1);
    while(fscanf(fp2, "%d", &aux) == 1){
        if(TH_busca("hash.bin", "dados.bin", n, aux)) fprintf(fpw, "%d\n", aux);
    }
    fclose(fp2); fclose(fpw);
}
//(c)
void uniao(char *arq1, char *arq2, char *saida){
    FILE *fp1 = fopen(arq1, "r"), *fp2 = fopen(arq2, "r");
    if((!fp1) || (!fp2)) exit(1);
    int aux, n;
    printf("\nInsira o tamanho da HASH:");
    scanf("%d", &n);
    TH_inicializa("hash.bin", n);
    while(fscanf(fp1, "%d", &aux) == 1) TH_insere("hash.bin", "dados.bin", n, aux);
    while(fscanf(fp2, "%d", &aux) == 1) TH_insere("hash.bin", "dados.bin", n, aux);
    fclose(fp1);
    fclose(fp2);
    int i = 0;
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
            FILE *fs = fopen(saida, "at");
            fprintf(fs, "%d\n", aux.num);
            fclose(fs);
            while(aux.prox != -1){
                fseek(fd, aux.prox, SEEK_SET);
                fread(&aux, sizeof(TNUM), 1, fd);
                FILE *fs = fopen(saida, "at");
                fprintf(fs, "%d\n", aux.num);
                fclose(fs);
            }
            fclose(fd);
        }
        i++;
    }
    fclose(fh);
}
//(d)
void elim_repet (char *repet, char *novo){
    FILE *fp = fopen(repet, "r");
    if(!fp) exit(1);
    int aux, n;
    printf("\nInsira o tamanho da HASH:");
    scanf("%d", &n);
    TH_inicializa("hash.bin", n);
    while(fscanf(fp, "%d", &aux) == 1) TH_insere("hash.bin", "dados.bin", n, aux);
    fclose(fp);
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
            FILE *fs = fopen(novo, "at");
            fprintf(fs, "%d\n", aux.num);
            fclose(fs);
            while(aux.prox != -1){
                fseek(fd, aux.prox, SEEK_SET);
                fread(&aux, sizeof(TNUM), 1, fd);
                FILE *fs = fopen(novo, "at");
                fprintf(fs, "%d\n", aux.num);
                fclose(fs);
            }
            fclose(fd);
        }
        i++;
    }
    fclose(fh);
}


int main(void){
    printf("Escolha entre:\n1-Intersecao dos conjuntos\n2-Diferenca simetrica dos conjuntos\n3-Uniao dos conjuntos\n4-Eliminacao de repeticao\n");
    int x;
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        inter("Arq1.txt", "Arq2.txt", "saida.txt");
        break;
    
    case 2:
        dif_sim("Arq1.txt", "Arq2.txt", "saida.txt");
        break;
    
    case 3:
        uniao("Arq1.txt", "Arq2.txt", "saida.txt");
        break;

    case 4:
        elim_repet("Arq1.txt", "saida.txt");
    default:
        break;
    }
    
    return 0;
}