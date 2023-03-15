# AEDS---Caminho-guloso

<p align="justify">
  Programa para disciplina de Estrutura de Dados I, desenvolvido na linguagem C++.Este trabalha o conceito de caminhamento em matrizes de forma gulosa, ou seja, optando por um dado caminho, no caso apresentado a trajetória pelo valor da próxima casa, valor esse que deve ser o maior dentre as posições possiveis de se caminhar. O sistema lê K matrizes quadradas no tamanho NxN, escritas no arquivo "dataset/input.data". Ele se inicia na primeira matriz, sempre começando a percorre-la na posição [0][0] até chegar ao final, posição [N-1][N-1], isto por todo o arquivo.</p>

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
<p <b>Exceções: </b> </p>
  Caso haja empate entre casas, o programa prioriza na sua ordem de leitura,ou seja ele vai avaliar as expressões lógicas e qual ele retorna um valor verdadeiro primeiro consiguirá a preferência. Neste programa temos como prioridades as seguintes posições:
<p align="center">
Direta > Esquerda > Baixo > Diagonal direita > Diagonal esquerda.</p>
</p>

<p align="justify">
  Ao alcançar a última linha e coluna da matriz, ele percorre a próxima até se encerrar o arquivo. Por fim, é demostrado as matrizes com o caminho percorrido marcado por "-1" e a soma total de todo o trajeto.</p>
