# AEDS---Caminho-guloso

<p align="justify">
Programa para disciplina de Algoritmo de Estrutura de Dados I, desenvolvido na linguagem C++.<br>
Este sistema trabalha o conceito de caminhamento em matrizes de forma gulosa, ou seja, optando por um dado caminho. No caso apresentado, a trajetória pelo valor da próxima casa, valor esse que deve ser o maior dentre as posições possíveis de se caminhar. 
Em resumo, deve-se criar um algoritmo que a cada passo ele escolhe o maior valor possível, sem refazer suas decisões.
</p>

# Objetivos
<p align="justify">
O sistema lê K matrizes quadradas no tamanho NxN, escritas no arquivo "dataset/input.data", estas matrizes e o padrão do arquivo que será lido são geradas pelo programa <a href="https://github.com/mpiress/GenerateDataToMatrix.git">GenerateDataToMatrix</a>. Ele se inicia na primeira matriz, sempre começando a percorre-lá na posição [0][0] até chegar ao final, posição [N-1][N-1], isto por todo o arquivo.</p>

<p align="justify">
A partir da primeira matriz, tem como regras: 
</p>

- Avançar para a próxima coluna (Direita); 
- Retroceder para coluna anterior (Esquerda); 
- Saltar para a linha de baixo (Baixo); 
- Ir em diagonal para baixo (Diagonal direita e Diagonal esquerda). 

<div align="center">
<img src="https://user-images.githubusercontent.com/109817570/225781320-75b6923e-66b3-4499-9fe1-7047b560e110.png" width="500px" />
</div>

<p  align="center">
A imagem acima representa todas as direções as quais são possíveis de caminhar, porém seguindo o objetivo do programa ele iria para a de maior valor, sendo a diagonal direita com o número 250.
</p>

<p  align="justify">
<b>Todas essas regras só se aplicam se a casa (posição i,j da matriz) ainda não tenha sido descoberta ou já processada </b>
</p>

<div align="center">
<img src="https://user-images.githubusercontent.com/109817570/225782396-0f28cfdc-6c59-4ab3-9b9a-058ec85291b7.png" width="500px" />
</div>

<p  align="center">
Observando a imagem acima, pode-se perceber quais posições estão disponíveis em situações nas quais algumas posições já foram descobertas.
</p>

<p align="justify">
Ele deve caminhar até chegar à última linha e coluna da matriz, mostrar o trajeto realizado e a soma de toda a trajetória.
</p>

<p  align="justify">
Observação: <br>
Ao chegar a última linha da matriz, ele deverá andar apenas para direita, recebendo com prioridade chegar a última coluna e não comparar os valores.
</p>

# Lógica do código
<p align="justify">
Utilizando a ideia do caminho guloso, este código leva como solução uma boa globalmente, ou seja, pode ser alcançada fazendo-se uma escolha boa localmente(neste caso a gulosa), isto é, aquela que parece ser a melhor naquele momento, desconsiderando-se resultados de subproblemas. Dessa forma, a implementação deste sistema em cada iteração, irá comparar as direções possíveis, na ordem que são lidas no código, e fazer a escolha que parece ser a melhor no momento, armazenando o maior valor dentre elas, isto objetivando chegar na melhor solução final que ele consegue.
</p>
<p align="justify">
O código está dividido em três arquivos: Main.cpp, Funcao.hpp e Matriz.cpp. Vamos abordar cada um deles. </p>

<p align="justify">
<b>Main.cpp: </b>
Na main, foi declarada uma variável do tipo arquivo e ela foi associada a um arquivo em disco. O primeiro parâmetro passado para o método open é o nome da pasta/arquivo ("dataset/input.data"), a estrutura do documento contém os 2 primeiros caracteres indicando a quantidade de linhas e colunas da matriz e o restante dele com as matrizes, sendo separadas cada uma delas por uma linha em branco. Após isto, é feita uma tentativa de abertura do arquivo, o programa testa se a operação de abertura teve sucesso, caso não, uma mensagem de erro é fornecida e o programa interrompe sua execução. Em seguida, o programa lê os dois primeiros caracteres do arquivo e são passados para a variável 'num' da matriz na qual será utilizada depois para armazenar o tamanho do array. <br>
No comando while, existe uma condição que é verdadeira enquanto o programa ler valores diferentes de final de arquivo. Dentro do while, cria uma array de ponteiro de tamanho 'N' para o armazenamento dos valores da matriz, isto feito por meio dos dois primeiros números que foram lidos anteriormente. Dito isso, é executado, dentro da função, um loop que percorre os valores da matriz e armazena dentro da array de ponteiros os endereços de memórias referentes aos índices da matriz. De tal modo que este aloca memória suficiente para a quantidade de inteiros lidos à matriz e retorna os endereços de memória, feito isto a matriz foi alocada dinamicamente e conseguimos usar seus valores (linhas 21 a 24). Finalizando, a primeira posição da matriz (0,0) recebe seu primeiro valor, lido pela condição dentro do while, e entram nas funções que irão realizar as operações.

<p align="justify">
<b>Funcao.hpp: </b>  
Este arquivo contém a criação da matriz, sendo ela de ponteiro para ponteiro(ela guarda inteiros), por meio de struct, essa estrutura também contém o 'num' no qual armazena o tamanho da matriz e as funções as quais recebem como parâmetros a matriz, o arquivo e variáves utilizadas para acessar as posições e soma.</p>

<p align="justify">
<b>Matriz.cpp: </b> 
No Matriz.cpp desenvolvemos as funções: 
</p>
<p align="justify">

- le_arquivo: Ela se incicia com uma variável booleana como true, ela é responsável por manter a leitura do arquivo da primeira linha e coluna de forma correta, pois a primeira posição já foi definida na main (linha 6). Em seguida, existem dois loops, um de linhas (i) e outro de colunas (j), que acontecerão até o tamanho da matriz (num). Dentro dele, se encontra o comando  if no qual lê os dados do arquivo e recebe uma condição que é verdadeira enquanto o programa ler valores diferentes de final de arquivo. (linha 11).<br>
Ainda dentro da condição acima:<br>
Se for uma primeira iteração de uma matriz, a variável boolena vai se encontrar verdadeira, então irá entrar na condição 'se for a primeira linha' (linha 13), dentro dela a coluna mudará para j=1 e a variável se torna false, para não ocorrer de entrar novamente caso não seja a primeira linha, isto para os valores serem armazenados corretamente em suas posições (linhas 13 a 18). <br>
Após esse caso em particular e fora dele, toda leitura do arquivo vai se armazenando para dentro da matriz e aparecendo na tela, caso chegue no tamanho final da matriz ele inicia a leitura da próxima e quando chega ao final do arquivo, ele se encerra <br>

- Funções de direção: Existem no total cinco funções de direções, são elas: para direita, esquerda, baixo e as duas diagonais. Cada uma delas recebe um tratamento único, indicando para em quais situações podem se mover e caso possam para onde vão se direcionar, é utilizado para isto a alteração das linhas e colunas e retornado estás alterações, assim mais para frente no código é possível comparar as posições das matrizes.

- Percorrer_matriz: Esta função permite caminhar por cada uma das matrizes, ela utiliza das funções de direção, compara cada uma delas com todas, a condição que obtiver todas suas condições verdadeias é acessada e dentro dela é realizada as modificações, sendo elas marcar a posição que está com "-1" indicando que foi percorrida, se deslocar para o sentido no qual entrou, salvar sua nova posição e armazenar o valor para a soma total do caminho. Após isto, ela sai deste "if"e  continua realizando a mesma ação até chegar na última linha e coluna da matriz.</p>
<p align="justify">

>
>Exemplo de comparação das direções:<br>
><br>
>Vamos supor que em uma matriz K e em uma posição i,j que não se encontra na última coluna da matriz e o maior valor dentre todas as direções esteja a sua direita, como o programa vai interpretar que deve ir para este sentido?<br>
>Primeiro vai verificar a condição nas funções de direção da direta para vê se é possível ele ir.<br>
>
> if (j!=(num-1))  //Se coluna for diferente da última coluna <br>
>		{<br>
>			posicao_direita = mat->matriz[i][j+1]; //matriz recebe uma posição para direita <br>
>		} <br>
>   return posicao_direita;<br>
>
>Como a posição não esta na última coluna, é possível ir para direita. <br>
>Então ele vai comparar a posição direita com todos os outros sentidos.<br>
>
>if ((pos_direita >= pos_esquerda) && (pos_direita >= pos_baixo) && (pos_direita >= pos_diagonal) && (pos_direita >= pos_diagonal_sec))<br>
>
>Como todas receberam um valor verdadeiros ele entra neste "if" e realiza as operações citadas acima.<br>
>
</p>
<p> <b>Exceções:</b></p>
<p align="justify">
Caso haja empate entre casas, o programa prioriza na sua ordem de leitura,ou seja ele vai avaliar as expressões lógicas e qual ele retorna um valor verdadeiro primeiro consiguirá a preferência. Neste programa temos como prioridades as seguintes posições:
<p align="center">
Direta > Esquerda > Baixo > Diagonal direita > Diagonal esquerda</p>
</p>

<div align="center">
<img src="https://user-images.githubusercontent.com/109817570/225783840-407d1bfd-70c2-47bd-b356-e826c20e4333.png" width="500px" />
</div>

<p  align="center">
Imagem para representar a prioridade das direções, quanto mais forte o tom da cor, mais preferencia o sentido recebe.
</p>

<p align="justify">
  Ao alcançar a última linha e coluna da matriz, ele percorre a próxima até se encerrar o arquivo. Por fim, é demostrado as matrizes com o caminho percorrido marcado por "-1" e a soma total de todo o trajeto.</p>
  
# Exemplo de execução
O arquivo de entrada deve conter apenas números inteiros positivos pois a saída terá demarcada o trajeto com o número 1 negativo. <br>
Demonstração de um dos arquivos testado:

<center>
<table>
   <tr>
      <td>Arquivo de entrada</td>
      <td>Matriz 1</td>
      <td>Matriz 2</td>
      <td>Matriz 3</td>
   </tr>
   <tr>
      <td><img src="https://user-images.githubusercontent.com/109817570/226119330-ccb2d7cb-f953-4941-b399-71c922e69ecc.png"/></td>
      <td><img src="https://user-images.githubusercontent.com/109817570/226120664-40cefbab-a2f2-4b84-a9d0-62ec439e355b.png" /></td>
      <td><img src="https://user-images.githubusercontent.com/109817570/226120705-452c490c-b84c-4c6b-b198-6ba39c90452c.png"/></td>
      <td><img src="https://user-images.githubusercontent.com/109817570/226120731-7ad39a50-d65d-4a8f-8027-55a81859363b.png"/></td>
   </tr>
</table>
</center> 

- Lembrando que na última linha não há comparação e sim prioriza chegar ao final da matriz.

- "Soma de todas" é a soma total de todos os caminhos das matrizes do arquivo que já foram percorridas, sendo a última soma a de todas as matrizes e "soma de uma" é apenas da matriz que acabou de ser percorrida.

# Compilação e Execução

Esse código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para compilar abra a pasta src no terminal, após temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
