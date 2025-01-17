/*
Implemente um algoritmo que receba como parâmetro de entrada, o nome de um arquivo
texto, cujo conteúdo são o nome do aluno e as duas notas dos alunos do curso, uma em cada linha, e
que ordene o arquivo de saída em ordem crescente pela média do aluno. Isto é, se eu tiver como
entrada o arquivo: "P C/10.0/10.0-J J/3.0/4.0-G G/7.0/7.0-A A/0.5/1.5-I I/5.0/6.0", a
saída será um arquivo com o seguinte texto: "A A/1.0-J J/3.5-I I/5.5-G G/7.0-P C/10.0" -
void media(char *ArqEnt, char *ArqSaida).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct aluno{
    char nome[30];
    float media;
}ALUNO;

int cmp(const void *a, const void *b){
    ALUNO *pa = (ALUNO*)a, *pb = (ALUNO*)b;
    if(pa->media < pb->media) return -1;
    return 1;
}

void media(char *ArqEnt, char *ArqSaida){
    FILE *fp1 = fopen(ArqEnt, "r"), *fp2 = fopen(ArqSaida, "w");
    if((!fp1) || (!fp2)) exit(1);
    char nome[30];
    float nota1, nota2, media;
    int r = fscanf(fp1, "%29[^/]/%f/%f", nome, &nota1, &nota2), tam = 0;
    while(r == 3){
        tam++;
        r = fscanf(fp1, "%29[^/]/%f/%f", nome, &nota1, &nota2);
    }
    rewind(fp1);
    ALUNO *vet = (ALUNO*)malloc(sizeof(ALUNO) * tam);
    r = fscanf(fp1, "%29[^/]/%f/%f", nome, &nota1, &nota2);
    strcpy(vet[0].nome, nome);
    vet[0].media = (nota1 + nota2) / 2;
    for(int i = 1; i < tam; i++){
        r = fscanf(fp1, "%29[^/]/%f/%f", nome, &nota1, &nota2);
        strcpy(vet[i].nome, nome);
        vet[i].media = (nota1 + nota2) / 2;
    }
    qsort(vet, tam, sizeof(ALUNO), cmp);
    for(int j = 0; j < tam; j++){
        fprintf(fp2, "nome: %s", vet[j].nome);
        fprintf(fp2, " media: %.1f\n", vet[j].media);
    }
    fclose(fp1);
    fclose(fp2);
}

int main(void){
    media("entrada.txt", "saida.txt");
    return 0;
}