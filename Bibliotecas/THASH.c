#include "THASH.h"

int hash(int mat, int n){
    return mat % n;
}

void TH_inicializa(THASH tab, int n){
    int i;
    for(i = 0; i<n; i++) tab[i]=NULL;
}

void TH_inicializa_arq(char *hash, char *dados, int n){
    FILE *fph = fopen(hash, "wb"), *fpd = fopen(dados, "wb");
    if((!fph) || (!fpd)) exit(1);
    fclose(fpd);
    int i, num = -1;
    for(i = 0; i < n; i++) fwrite(&num, sizeof(int), 1, fph);
    fclose(fph);
}

void TH_imprime_arq(char *hash, char *dados, int n){
    FILE *fph = fopen(hash, "rb"), *fpd = fopen(dados, "rb");
    if((!fph) || (!fpd)) exit(1);
    int vet[n], i, pos;
    fread(&vet, sizeof(int), n, fph);
    fclose(fph);
    for(i = 0; i < n; i++){
        if(vet[i] == -1){
            printf("%d:NULL\n", i);
        }
        else{
            pos = vet[i];
            while(pos != -1){
                fseek(fpd, pos, SEEK_SET);
                TAarq aux;
                fread(&aux, sizeof(TA), 1, fpd);
                if(aux.status) printf("mat:%d\tcr:%.2f\tprox:%d\n", aux.mat, aux.cr, aux.prox);
                pos = aux.prox;
            }
        }
    }
    fclose(fpd);
}



TA *TA_aloca(int mat, float cr){
    TA *al = (TA*)malloc(sizeof(TA));
    al->mat = mat;
    al->cr = cr;
    al->prox = NULL;
    return al;
}
void TH_libera(THASH tab, int n){
    int i;
    for(i = 0; i<n; i++)
        if(tab[i]){
            TA *p = tab[i], *q;
            while(p){
                q = p;
                p = p->prox;
                free(q);
            }
            tab[i] = NULL;
        }
}

void TH_imprime(THASH tab, int n){
    int i;
    for(i = 0; i<n; i++)
    if(tab[i]){
        TA *p = tab[i];
        while(p){
            printf("%d\t%.2f\n", p->mat, p->cr);
            p = p->prox;
        }
    }
    else printf("NULL\n");
}

TA *TH_busca(THASH tab, int n, int mat){
    int h = hash(mat, n);
    TA *resp = tab[h];
    while((resp) && (resp->mat < mat)) resp = resp->prox;
    if((resp) && (resp->mat == mat)) return resp;
    return NULL;
}

void TH_insere(THASH tab, int n, int mat, float cr){
    int h = hash(mat, n);
    TA *ant = NULL, *p = tab[h];
    while((p) && (p->mat < mat)){
        ant = p;
        p = p->prox;
    }
    if((p) && (p->mat == mat)){
        p->cr = cr;
        return;
    }
    TA *al = TA_aloca(mat, cr);
    if(!ant){
        al->prox = p;
        tab[h] = al;
    }
    else{
        al->prox = p;
        ant->prox = al;
    }
}

float TH_retira(THASH tab, int n, int mat){
    int h = hash(mat, n);
    TA *p = tab[h], *ant = NULL;
    while((p) && (p->mat < mat)){
        ant = p;
        p = p->prox;
    }
    if(!p || (p->mat != mat)) return -1.0;
    if(!ant) tab[h] = p->prox;
    else ant->prox = p->prox;
    float cr = p->cr;
    free(p);
    return cr;
}



float TH_busca_arq(char *hasharq, char *dados, int n, int mat){
    FILE *fp = fopen(hasharq, "rb");
    if(!fp) exit(1);
    int h = hash(mat, n), pos;
    fseek(fp, h*sizeof(int), SEEK_SET);
    fread(&pos, sizeof(int), 1, fp);
    fclose(fp);
    if(pos == -1) return -1.0;
    fp = fopen(dados, "rb");
    if(!fp) exit(1);
    while(pos != -1){
        fseek(fp, pos, SEEK_SET);
        TAarq aux;
        fread(&aux, sizeof(TAarq), 1, fp);
        if((aux.mat == mat) && (aux.status)){
            fclose(fp);
            return aux.cr;
        }
        pos = aux.prox;
    }
    fclose(fp);
    return -1.0;
}

void TH_retira_arq(char *hasharq, char *dados, int n, int mat){
    FILE *fp = fopen(hasharq, "rb");
    if(!fp) exit(1);
    int h = hash(mat, n), pos;
    fseek(fp, h*sizeof(int), SEEK_SET);
    fread(&pos, sizeof(int), 1, fp);
    fclose(fp);
    if(pos == -1) return;
    fp = fopen(dados, "rb+");
    if(!fp) exit(1);
    while(pos != -1){
        fseek(fp, pos, SEEK_SET);
        TAarq aux;
        fread(&aux, sizeof(TAarq), 1, fp);
        if((aux.mat == mat) && (aux.status)){
            aux.status = 0;
            fseek(fp, pos, SEEK_SET);
            fwrite(&aux, sizeof(TAarq), 1, fp);
            fclose(fp);
            return;
        }
        pos = aux.prox;
    }
    fclose(fp);
}

void TH_insere(char *hasharq, char *dados, int n, int mat, float cr){
    FILE *fph = fopen(hasharq, "rb+"), *fpd = fopen(dados, "rb+");
    int h = hash(mat, n), pos;
    fseek(fph, h*sizeof(int), SEEK_SET);
    fread(&pos, sizeof(int), 1, fph);
    TAarq aux;
    int ant = -1, poslivre = -1;
    while(pos != -1){
        fseek(fpd, pos, SEEK_SET);
        fread(&aux, sizeof(TAarq), 1, fpd);
        if(aux.mat == mat){
            aux.status = 1;
            aux.cr = cr;
            fseek(fpd, pos, SEEK_SET);
            fwrite(&aux, sizeof(TAarq), 1, fpd);
            fclose(fpd); fclose(fph);
            return;
        }
        if((!aux.status) && (poslivre == -1)) poslivre = pos;
        ant = pos;
        pos = aux.prox;
    }
    TAarq novo;
    novo.cr = cr;
    novo.mat = mat;
    novo.status = 1;
    novo.prox = -1;
    if((ant == -1) || (poslivre == -1)){
        fseek(fpd, 0L, SEEK_END);
        int end = ftell(fpd);
        fwrite(&novo, sizeof(TAarq), 1, fpd);
        if(ant == -1){
            fseek(fph, h*sizeof(int), SEEK_SET);
            fwrite(&end, sizeof(int), 1, fph);
        }
        else{
            fseek(fpd, ant, SEEK_SET);
            aux.prox = end;
            fwrite(&aux, sizeof(TAarq), 1, fpd);
        }
        fclose(fph); fclose(fpd);
        return;
    }
    fseek(fpd, poslivre, SEEK_SET);
    fread(&aux, sizeof(TAarq), 1, fpd);
    novo.prox = aux.prox;
    fseek(fpd, poslivre, SEEK_SET);
    fwrite(&novo, sizeof(TAarq), 1, fpd);
    fclose(fpd); fclose(fph);
}