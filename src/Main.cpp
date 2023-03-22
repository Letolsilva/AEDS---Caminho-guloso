#include "Funcao.h"
#include <time.h>
using namespace std;
int main ()
{	
    Matrix m;
    int ler_primeiros_num, totais=0;
    fstream arq;

    arq.open("dataset/input.data");
    if (!(arq.is_open())){
		printf("ERRO ao abrir arquivo");
    	exit(-1);
    }
  
    arq>>ler_primeiros_num>>ler_primeiros_num;

    m.num=ler_primeiros_num;

    while(arq>>ler_primeiros_num){
        m.matriz = new  short  int *[m.num];
        for ( int i= 0 ; i<m.num; i++){
            m.matriz[i] = new  short  int [m.num];
        }
        m.matriz[0][0]=ler_primeiros_num;

        le_arquivo(&m, arq);
        percorrer_matriz(&m, &totais);  
        free(m.matriz);       
    }
     
    arq.close();
	return 0;
}
