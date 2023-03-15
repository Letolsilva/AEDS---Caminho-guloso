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
#define N 10
typedef struct Valor Valores;
typedef struct Matrix Matrizes;

struct Valor
{
    short int val;
    
};

struct Matrix
{
    Valor **matriz;
};


void percorrer_matriz(Matrix *mat);
void le_arquivo(Matrix *mat, fstream& arq);

short int direito(Matrix *mat, int i, int j);
short int esquerdo(Matrix *mat, int i, int j);
short int baixo(Matrix *mat, int i, int j);
short int diagonal_prin(Matrix *mat, int i, int j);
short int diagonal_sec(Matrix *mat, int i, int j);

#endif
