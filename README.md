# AEDS---Caminho-guloso

<p align="justify">
  Programa para disciplina de Estrutura de Dados I, desenvolvido na linguagem C++. Este trabalha o conceito de caminhamento em matrizes de forma gulosa, ou seja, optando por um dado caminho, no caso apresentado a trajetória pelo valor da próxima casa, valor esse que deve ser o maior dentre as posições possiveis de se caminhar. O sistema lê K matrizes quadradas no tamanho NxN, escritas no arquivo "dataset/input.data". Ele se inicia na primeira matriz, sempre começando a percorre-la na posição [0][0] até chegar ao final, posição [N-1][N-1], isto por todo o arquivo.</p>

<p align="justify">
A partir da primeira matriz, tem como regras: 
</p>

- Avançar para a próxima coluna (Direita); 
- Retroceder para coluna anterior (Esquerda); 
- Saltar para a linha de baixo (Baixo); 
- Ir em diagonal para baixo (Diagonal direita e Diagonal esquerda). 

<p>
Todas essas regras só se aplicam se a casa (posição i,j da matriz) ainda não tenha sido descoberta ou já processada.</p>

<p align="justify">
  Ele deve caminhar ate chegar à última linha e coluna da matriz, mostrar o trajeto realizado e a soma de todo a trajetória.
</p>
  

#Resumo do código

<p align="justify">
O código está dividido em três arquivos, Main.cpp, Funcao.hpp e Matriz.cpp. Vamos abordar cada um deles. </p>

<p align="justify">
<b>Main.cpp: </b>
Na main, abrimos o arquivo "dataset/input.data", arquivo que irá conter as matrizes que se deseja percorrer. Depois fazemos a leitura do arquivo, enquanto não for o final dele lemos a função "le_arquivo" e conseguimos percorre-la com a função "percorrer_matriz".</p>

<p align="justify">
<b>Funcao.cpp: </b>  
Este arquivo contém a criação da matriz por meio de structs e as funções as quais recebem como parametro a matriz, o arquivo e variáves utilizadas para acessar as posições.</p>

<p align="justify">
<b>Matriz.cpp: </b> 
No Matriz.cpp desenvolvemos as funções:

-<b>le_arquivo: </b> lê os primeiros caracteres do arquivo que indica o tamanho da matriz, os trasforma em inteiros e os aloca dinamicamente. Após isto se inicia a leitura e armazenamento das matrizes presentes no arquivo.

-<b>Funções de direçâo: </b> Temos no total cinco funções de direções, são elas: para direita, esquerda, baixo e as duas diagonais. Cada uma delas recebe um tratamento único, indicando para em quais situações podem se mover e caso possam para onde vão se direcionar, utilizamos para isto a alteração das linhas e colunas e retornamos esta alteração, assim mais para frente no código conseguirmos comparar as posições da matriz.

-<b>Percorrer_matriz: </b> Esta função é as que nos permite caminhar por cada uma das matrizes, ela utiliza das funções de posições, as compara e a que for maior é para onde deve andar,salva na posição o dígito -1, se desloca, e realiza a soma do caminho.

</p>

<p align="justify">
<p <b>Exceções: </b> </p>
  Caso haja empate entre casas, o programa prioriza na sua ordem de leitura,ou seja ele vai avaliar as expressões lógicas e qual ele retorna um valor verdadeiro primeiro consiguirá a preferência. Neste programa temos como prioridades as seguintes posições:
<p align="center">
Direta > Esquerda > Baixo > Diagonal direita > Diagonal esquerda.</p>
</p>

<p align="justify">
  Ao alcançar a última linha e coluna da matriz, ele percorre a próxima até se encerrar o arquivo. Por fim, é demostrado as matrizes com o caminho percorrido marcado por "-1" e a soma total de todo o trajeto.</p>
