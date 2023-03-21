#include "Funcao.h"
#include <time.h>
using namespace std;
int main ()
{	
    Matrix m;
    fstream arq;
    arq.open("dataset/input.data");
    if (!(arq.is_open())){
		printf("ERRO ao abrir arquivo");
    	exit(-1);
    }
    int x;
    arq>>x>>x;
    m.num=x;
    while(arq>>x){
        m.matriz = new  short  int *[m.num];
        for ( int i= 0 ; i<m.num; i++){
            m.matriz[i] = new  short  int [m.num];
        }
        m.matriz[0][0]=x;
        le_arquivo(&m, arq);
        percorrer_matriz(&m);  
        free(m.matriz);       
    }
     
    arq.close();
	return 0;
}
