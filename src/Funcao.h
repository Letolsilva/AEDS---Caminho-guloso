#ifndef FUNCAO_H
#define FUNCAO_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include <unistd.h>
#include <fstream>
#include <string.h>
#include<iostream>
using namespace std;
typedef struct Matrix Matrizes;
static int cont=0;

struct Matrix
{
    short int **matriz;
    short int num;
};

void percorrer_matriz(Matrix *mat, int *totais);
void le_arquivo(Matrix *mat, fstream& arq);


short int direito(Matrix *mat, int i, int j);
short int esquerdo(Matrix *mat, int i, int j);
short int baixo(Matrix *mat, int i, int j);
short int diagonal_prin(Matrix *mat, int i, int j);
short int diagonal_sec(Matrix *mat, int i, int j);

#endif