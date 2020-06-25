<h1>Introdução à Computação Gráfica</h1>
<h4>Hananias Daniel de Sousa Vasconcelos - 2016011949</h4>

Neste repositório estão sendo apresentados os trabalhos referentes a disciplina de Introdução à Computação Gráfica, ministrada pelo Prof. Dr. Christian Azambuja Pagot durante o período suplementar 2019.4 da UFPB.

<h1>Sumário</h1>
<ol>
  <li>Rasterização</li>
  <ul>
    <li><a href="https://github.com/hananiasd/Computacao_Grafica/tree/master/T1_rasteriza%C3%A7%C3%A3o">Código-Fonte</a></li>
  </ul>
</ol>

<h2>1. Rasterização</h2>
<p>O trabalho tinha como objetivo dar uma familiarização com algoritmos de rasterização e OpenGL, e foram implementados 3 funções usando o algoritmo de rasterização de Bresenham, uma para rasterização de pontos, outra para rasterização de linhas e a partir da rasterização de linhas um triângulo deveria ser desenhado. Para simular o acesso direto à memória de vídeo foi disponibilizado pelo Professor um framework.</p>

<h3>1.1 PutPixel</h3>
<p>A primeira função desenvolvida foi a PutPixel, que era para rasterização de um ponto. Esta função recebe como parâmetros as coordenadas x e y do pixel e as cores que representavam esse pixel, vale ressaltar que foi utilizada a estrutura de linguagem <i>Struct</i> para melhor resolução dos problemas que a implementação traria.</p>
<p>Neste exemplo abaixo podemos ver alguns resultados da função PutPixel, onde podemos observar a impressão na tela de 6 pixels, onde cada um deles possui coordenadas e cores diferentes.</p>

<img src="https://raw.githubusercontent.com/hananiasd/Computacao_Grafica/master/T1_rasteriza%C3%A7%C3%A3o/img/PutPixel.png">
