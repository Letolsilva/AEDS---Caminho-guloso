#include "Funcao.h"

void  le_arquivo (Matrix *mat, fstream& arq){
    short apoio_matriz;
   
        bool primeiralinha = true;
        cout<< " \t\t\t\t\t " << "   MATRIZ " <<endl;
        for ( int i= 0 ;i<mat->num;i++){
            cout<< " \t\t " ;
            for ( int j=0 ;j<mat->num;j++){
                    if(arq>>apoio_matriz){
                         //i=0 j=0
                        if(primeiralinha == true){
                            //i=0 j=1
                            j++;
                            primeiralinha = false;
                            cout<< " \t " <<mat-> matriz [0][0];
                    }
                    mat-> matriz [i][j]=apoio_matriz;

                    cout<< " \t " <<mat-> matriz [i][j];
                    }
                    else{
                        break;
                    }              
            }
            cout<<endl;
        }
        cout<<endl;

}


short int direito (Matrix *mat, short int i, short int j) {
    short int posicao_direita = 0;
    if (j!=(mat->num-1))
		{
			posicao_direita = mat->matriz[i][j+1];
		} 

    return posicao_direita;
}

short int esquerdo (Matrix *mat, int i, int j) {
    short int Posicao_esquerda = 0;

    if (!((j==0) || (i==(mat->num-1))))
    {
        Posicao_esquerda = mat->matriz[i][j-1];
    }
    return Posicao_esquerda;
}

short int baixo (Matrix *mat, int i, int j) {
   short int posicao_baixo = 0;
    if (!(i==(mat->num-1)))
    {
        posicao_baixo = mat->matriz[i + 1][j];
    }
    return posicao_baixo;
}
short int diagonal_prin(Matrix *mat, int i, int j){
    short int posicao_diagonal=0;
    if(j+1<=mat->num-1 && i+1<=mat->num-1){
        posicao_diagonal=mat->matriz[i+1][j+1];

    }
    return posicao_diagonal;
}
short int diagonal_sec(Matrix *mat, int i, int j){
    short int posicao_diagonal_sec=0;
    if(j-1>=0 && i+1<=mat->num-1){
        posicao_diagonal_sec=mat->matriz[i+1][j-1];
    }
    return posicao_diagonal_sec;
    
}

void percorrer_matriz(Matrix *mat, int *totais) {
    
    short int i = 0, j = 0, agora = mat->matriz[i][j], total = agora, pos_direita, pos_esquerda, pos_baixo, pos_diagonal, pos_diagonal_sec;

    while ((i<mat->num-1 || j<mat->num-1) )
	{
		pos_direita = direito(mat, i, j);
		pos_esquerda = esquerdo(mat, i, j);
		pos_baixo = baixo(mat, i, j);
        pos_diagonal = diagonal_prin(mat,i,j);
        pos_diagonal_sec = diagonal_sec(mat,i,j);

		if ((pos_direita >= pos_esquerda) && (pos_direita >= pos_baixo) && (pos_direita >= pos_diagonal) && (pos_direita >= pos_diagonal_sec))
		{
			mat->matriz[i][j] = -1;
			j++;
			agora = mat->matriz[i][j];
			total+= agora;
            //cout<<"\nDireita: "<<agora<<endl;
            
		}

		if ((pos_esquerda > pos_direita) && (pos_esquerda >= pos_baixo) && (pos_esquerda >= pos_diagonal) && (pos_esquerda >= pos_diagonal_sec))
		{
			mat->matriz[i][j] = -1;
			j--;
			agora = mat->matriz[i][j];
			total+=agora;
            //cout<<"\nEsquerda: "<<agora<<endl;
		}

	    if ((pos_baixo > pos_direita) && (pos_baixo > pos_esquerda) && (pos_baixo >= pos_diagonal) && (pos_baixo >= pos_diagonal_sec))
		{
			mat->matriz[i][j] = -1;
			i++;
			agora = mat->matriz[i][j];
			total+= agora;
            //cout<<"\nBaixo: "<<agora<<endl;
		}

       if((pos_diagonal > pos_direita) && (pos_diagonal > pos_esquerda) && (pos_diagonal > pos_baixo)&& (pos_diagonal > pos_diagonal_sec)){
            mat->matriz[i][j]=-1;
            i++;
            j++;
            agora = mat->matriz[i][j];
			total+= agora;
            //cout<<"\nDiagonal direita: "<<agora<<endl;
        }
        if((pos_diagonal_sec > pos_direita) && (pos_diagonal_sec > pos_esquerda) && (pos_diagonal_sec > pos_baixo)&&(pos_diagonal_sec > pos_diagonal)){
            mat->matriz[i][j]=-1;
            i++;
            j--;
            agora = mat->matriz[i][j];
			total+= agora;
            //cout<<"\nDiagonal esquerda: "<<agora<<endl;

        }
	}
    mat->matriz[mat->num-1][mat->num-1]=-1;
    
    cout<<"\t\t\t\t Caminho realizado marcado por -1\t\t"<<endl;
            cout<<endl;
        for (i = 0; i < mat->num; i++)
	    {
		    cout<<"\t\t";
            for (j = 0; j < mat->num; j++)
            {
                cout<<"\t"<<mat->matriz[i][j];
            }
            cout<<endl;
        }
    *totais += total;
    cout<<"\nSoma do trajeto da matriz lida por ultimo: "<<total<<endl;
    cout<<"\nSoma do trajeto de todas as matrizes percorridas até o momento: "<<*totais<<endl;
    cout<<"\n------------------------------------------------------------------------------------------------------------\n";
    cout<<endl;
   
}