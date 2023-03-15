#include "Funcao.h"
#include <time.h>
using namespace std;
int main ()
{	
    short int andar_matriz=0;
    Matrix m;
  
    fstream arq;
    arq.open("dataset/input.data");
    if (!(arq.is_open())){
		printf("ERRO ao abrir arquivo");
    	exit(-1);
    }
    while(!(arq.eof())){
        le_arquivo(&m, arq);
        andar_matriz=1;
        if(andar_matriz==1){
            percorrer_matriz(&m); 
            andar_matriz=0;
        }
        
    } 
     
    arq.close();
	return 0;
}
