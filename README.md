# AEDS---Caminho-guloso

<p align="justify">
  Programa para disciplina de Estrutura de Dados I. Este trabalha o conceito de caminhamento em matrizes de forma gulosa, ou seja, optando por um dado caminho, no caso apresentado o caminho opta pelo valor da próxima casa, valor esse que deve ser o maior dentre as posições possiveis de se caminhar. O sistema lê K matrizes quadradas no tamanho NxN, escritas no arquivo "dataset/input.data". Ele se inicia na primeira matriz, sempre começando a percorre-la na posiçao [0][0] ate chegar ao final, posição [N-1][N-1].</p>

<p align="justify">
A partir da primeira matriz, você tem como regras: 
>  
>(a) avançar para a próxima coluna; 
>(b) retroceder para coluna anterior; 
>(c)  saltar para a linha de baixo; 
>(d) ir em diagonal para baixo. 
>  
Todas essas regras só se aplicam se a casa (posição i,j da matriz) ainda não tenha sido descoberta ou já processada.</p>

<p align="justify">
<b>Exceções: </b>
  Caso haja empate entre casas, o programa prioriza na sua ordem de leitura,ou seja ele vai avaliar as expressões lógicas e qual ele retorna um valor verdadeiro primeiro tera preferência. Neste programa temos como prioridades as seguintes posições:
<p align="center">
Direta > Esquerda > Baixo > Diagonal Direita > Diagonal Esquerda.</p>
</p>

<p align="justify">
  Ao alcançar a última linha e coluna da matriz, ele percorre a próxima até se encerrar o arquivo. Por fim, é demostrado as matrizes com o caminho percorrido marcado por "-1" e a soma total de todo o trajeto.</p>
