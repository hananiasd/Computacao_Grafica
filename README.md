<h1>Introdução à Computação Gráfica</h1>
<h4>Hananias Daniel de Sousa Vasconcelos - 2016011949</h4>

Neste repositório estão sendo apresentados os trabalhos referentes a disciplina de Introdução à Computação Gráfica, ministrada pelo Prof. Dr. Christian Azambuja Pagot durante o período suplementar 2019.4 da UFPB.

<h1>Sumário</h1>

  1. <a href="https://github.com/hananiasd/Computacao_Grafica#1-rasteriza%C3%A7%C3%A3o">Rasterização</a>
  
        - <a href="https://github.com/hananiasd/Computacao_Grafica#11-putpixel">Função PutPixel</a>
        - <a href="https://github.com/hananiasd/Computacao_Grafica#12-drawline">Função DrawLine</a>
        - <a href="https://github.com/hananiasd/Computacao_Grafica#13-drawtriangle">Função DrawTriangle</a>
        - <a href="https://github.com/hananiasd/Computacao_Grafica#14-dificuldades">Dificuldades</a>
        - <a href="https://github.com/hananiasd/Computacao_Grafica#conclus%C3%A3o">Conclusão</a>
        - <a href="https://github.com/hananiasd/Computacao_Grafica/tree/master/T1_rasteriza%C3%A7%C3%A3o">Código-Fonte</a>

  2. <a href="https://github.com/hananiasd/Computacao_Grafica#2-opengl-moderno">OpenGL Moderno</a>
  
        - <a href="https://github.com/hananiasd/Computacao_Grafica#21-resultados">Resultados</a>

  3. <a href="https://github.com/hananiasd/Computacao_Grafica#3-pipeline-gr%C3%A1fico">Pipeline Gráfico</a>
  
        - <a href="https://github.com/hananiasd/Computacao_Grafica#31-exerc%C3%ADcio-1---escala">Escala</a>
        - <a href="https://github.com/hananiasd/Computacao_Grafica#32-exerc%C3%ADcio-2---transla%C3%A7%C3%A3o">Translação</a>
        - <a href="https://github.com/hananiasd/Computacao_Grafica#33-exerc%C3%ADcio-3---proje%C3%A7%C3%A3o-perspectiva">Projeção Perspectiva</a>
        - <a href="https://github.com/hananiasd/Computacao_Grafica#34-exerc%C3%ADcio-4---posi%C3%A7%C3%A3o-da-c%C3%A2mera">Posição da Câmera</a>
        - <a href="https://github.com/hananiasd/Computacao_Grafica#34-exerc%C3%ADcio-5---transforma%C3%A7%C3%B5es-livres">Transformações Livres</a>

  4. <a href="https://github.com/hananiasd/Computacao_Grafica/blob/master/README.md#4-modelos-de-ilumina%C3%A7%C3%A3o">Modelos de Iluminação</a>
        
        - <a href="https://github.com/hananiasd/Computacao_Grafica/blob/master/README.md#41-modelo-de-reflex%C3%A3o-difuso">Modelo de Reflexão Difuso</a>
        - <a href="https://github.com/hananiasd/Computacao_Grafica/blob/master/README.md#42-modelo-de-reflex%C3%A3o-especular">Modelo de Reflexão Especular</a>

<h2>1. Rasterização</h2>
<p>O trabalho tinha como objetivo dar uma familiarização com algoritmos de rasterização e OpenGL, e foram implementados 3 funções usando o algoritmo de rasterização de Bresenham, uma para rasterização de pontos, outra para rasterização de linhas e a partir da rasterização de linhas um triângulo deveria ser desenhado. Para simular o acesso direto à memória de vídeo foi disponibilizado pelo Professor um framework.</p>

<h3>1.1 PutPixel</h3>
<p>A primeira função desenvolvida foi a PutPixel, que era para rasterização de um ponto. Esta função recebe como parâmetros as coordenadas x e y do pixel e as cores que representavam esse pixel, vale ressaltar que foi utilizada a estrutura de linguagem <i>Struct</i> para melhor resolução dos problemas que a implementação traria.</p>
<p>Neste figura abaixo podemos ver alguns resultados da função PutPixel, onde podemos observar a impressão na tela de 6 pixels, onde cada um deles possui coordenadas e cores diferentes.</p>
<img src="https://raw.githubusercontent.com/hananiasd/Computacao_Grafica/master/T1_rasteriza%C3%A7%C3%A3o/img/PutPixel.png">
<h3>1.2 DrawLine</h3>
<p>A função DrawLine utiliza uma variação do algoritmo de Bresenham para criar uma reta. A partir das coordenadas de dois pontos, uma reta é traçada de um ponto origem, até um ponto destino. Nesta função também foi utilizado uma interpolação linear nas cores que compõem a reta.</p>
<p>Na figura abaixo vemos o resultado desta função, onde observamos 3 retas que foram criadas pelo algoritmo, com 3 diferentes angulações e cores.</p>
<img src="https://raw.githubusercontent.com/hananiasd/Computacao_Grafica/master/T1_rasteriza%C3%A7%C3%A3o/img/DrawLine.png">
<h3>1.3 DrawTriangle</h3>
<p>Esta funçaõ era totalmente dependente da DrawLine, pois criando a função que cria retas, bastava definir 3 retas que iria ser criado um triângulo. Logo, o próprio código desta função foi fácil, sendo apenas três chamadas da função DrawLine.</p>
<p>Na figura abaixo podemos ver dois exemplos de triângulos criados por essa função, onde os triângulo estão posicionados em coordenadas diferentes e cada aresta possui sua cor</p>
<img src="https://raw.githubusercontent.com/hananiasd/Computacao_Grafica/master/T1_rasteriza%C3%A7%C3%A3o/img/DrawTriangle.png">
<h3>1.4 Dificuldades</h3>
<p>As dificuldades encontradas na implementação deste trabalho foram a adaptação do algoritmo de Bresenham quando a função DrawLine estava sendo implementada, pois o algoritmo funciona apenas para um octante, logo, uma generalização do algoritmo teve que ser feita, para que incluisse em sua resolução todas as situações que poderiam ocorrer. Neste caso foram identificados algumas restrições que deveriam ser consertadas.
  <ul>
    <li><strong>Restrição 1</strong></li>
    <p>Se o Δx for negativo, significa que a reta cresce para o lado negativo de x. Para solucionar este problema, bastava trocar o ponto inicial pelo ponto final.</p>
    <li><strong>Restrição 2</strong></li>
    <p>Se o Δy for negativo, significa que a reta cresce para o lado negativo de y. Para solução deste problema, uma variável denominada <i>inclin</i> foi criada para analisar previamente o valor de Δy, de Δy fosse negativo, a variável recebia o valor -1, caso contrário, recebia 1. Ou seja, se a variável recebesse -1 ela seria multiplicada pelo Δy negativo fazendo com que assim nao houvesse erros.</p>
  </ul>
  <p>A interpolação linear também foi uma dificuldade, não a sua implementação, mas sim a compreensão em como usar este cálculo e onde ele seria aplicado no código, por fim, foi visto que precisariamos de um cálculo de distância, onde a distância entre dois pontos euclidiana foi usada, neste caso foi usado uma variável que calculava a distância que faltava até o ponto destino e ia variando a tonalidade das cores, realizando a interpolação, até chegar ao ponto final.</p>
  <h3>Conclusão</h3>
  <p>Todos os objetivos do trabalho foram concluídos, desde o desenho do ponto na tela, passando pelo desenho da reta e chegando até o triângulo, usando a interpolação linear nas cores para ocorrer uma variação na tonalidade das retas criadas.</p>
  <h3>Referências</h3>
  <ul>
  <li>https://letslearnbits.blogspot.com/2014/10/icgt1-interpolacao-de-cores.html</li>
  </ul>

---
---

<h2>2. OpenGL Moderno</h2>
<p>Esse trabalho tem como objetivo verificar se o ambiente de trabalho utilizado está corretamente configurado com o OpenGL 3.3. O trabalho em si era compilar e executar um código disponibilizado pelo professor para que essa a validação de que o computador do aluno da disciplina estivesse com perfeitas condições de trabalho com o a versão moderna do OpenGL.</p>

<h3>2.1 Resultados</h3>
<p>O código disponibilizado pelo professor foi baixado do repositório onde estava. E após isso foi compilado, nenhum erro foi detectado durante a compilação, apenas a aparição de alguns <i>warnings</i>, que já havia sido informado pelo professor que isso poderia acontecer. Após o resultado da compilação, houve a execução do programa e o resultado podemos ver na figura abaixo:</p>

<img src=https://github.com/hananiasd/Computacao_Grafica/blob/master/T2_opengl_moderno/img/cg_atividade2.gif>

---
---

<h2>3. Pipeline Gráfico</h2>
<p>O objetivo desse trabalho é visualizar o pipeline gráfico através de algumas implementações de transformações geométricas que o compõem. A biblioteca <i>glm</i> foi utilizada para auxiliar essa implementação.
A atividade consistiu em algumas alterações realizadas no código disponibilizado pelo professor, onde essas alterações eram nas matrizes <i>Model, View</i> e <i>Projection</i>. A imagem gerada originalmente pelo código-fonte disponibilizado está apresentada abaixo:</p>
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T3_pipeline_gr%C3%A1fico/img/Original.png">

<h3>3.1 Exercício 1 - Escala</h3>
<p>Modificação da matriz <i>MModel</i> de forma que a imagem gerada pelo programa alterasse a escala original dos triângulos. Os fatores de escala pedidos pelo professor foram <strong>(x, y, z) = (1/3, 3/2, 1)</strong>. A matriz alterada e a imagem gerada pelas mudanças estão apresentadas a seguir:</p>
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T3_pipeline_gr%C3%A1fico/img/1_matrixmodel.png">
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T3_pipeline_gr%C3%A1fico/img/exercicio1.png">

<h3>3.2 Exercício 2 - Translação</h3>
<p>Modificação novamente da matriz <i>MModel</i> de forma que a imagem gerada pelo programa alterasse a posição original dos triângulos, fazendo com que as formas ficassem localizadas a direita da janela. Os fatores de escala pedidos pelo professor foram <strong>(x, y, z) = (1, 0, 0)</strong>. A matriz alterada e a imagem gerada pelas mudanças estão apresentadas a seguir:</p>
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T3_pipeline_gr%C3%A1fico/img/2_matrizmodel.png">
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T3_pipeline_gr%C3%A1fico/img/exercicio2.png">

<h3>3.3 Exercício 3 - Projeção Perspectiva</h3>
<p>Modificação da matriz <i>MProjection</i> de forma que a imagem gerada pelo programa coloque o triângulo da cor azul um pouco mais ao fundo, como se ele estivesse em uma posição mais longe da câmera. A matriz de projeção utilizada foi a matriz que considera a câmera na origem do sistema de coordenadas. O parâmetro <i>d</i> pedido pelo professor foi <strong>d = 1/2</strong>. A matriz alterada e a imagem gerada pelas mudanças estão apresentadas a seguir:</p>
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T3_pipeline_gr%C3%A1fico/img/3_matrizprojection.png">
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T3_pipeline_gr%C3%A1fico/img/exercicio3.png">

<h3>3.4 Exercício 4 - Posição da Câmera</h3>
<p>Mantendo as modificações realizadas no exercício 3 e fazendo a modificação da matriz <i>MView</i> de forma que a imagem gerada pelo programa coloque os triângulos de uma forma diagonal. Nesse exercício foi necessário a construção de duas matrizes, a matriz da base da câmera e a matriz que translada a base da câmera. A matriz <i>MView</i> é construída com o produto das duas matrizes criadas (BT e T). Para esse desenvolvimento foi usado as funções da biblioteca glm. Os fatores pedidos pelo professor foi <strong>Posição da câmera = (-1/10, 1/10, 1/4), vetor Up da câmera = (0, 1, 0), ponto para qual a câmera aponta = (0, 0, 0)</strong>. A matriz alterada e a imagem gerada pelas mudanças estão apresentadas a seguir:</p>
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T3_pipeline_gr%C3%A1fico/img/4_matrizview.png">
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T3_pipeline_gr%C3%A1fico/img/exercicio4.png">

<h3>3.4 Exercício 5 - Transformações Livres</h3>
<p>Nessa atividade, é pedido transformações nas 3 matrizes utilizadas no desenvolvimento, para essas modificações foi feita uma nova geometria da fornecida originalmente. A nova forma foi feita com adições no array <i>vértices[]</i> de dois novos triângulos, outra mudança foi a localização onde os triângulos se encontravam, eles foram realocados para que a imagem tornasse forma. A nova forma desenhada se encontra abaixo:</p>
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T3_pipeline_gr%C3%A1fico/img/geometria05.png">

<p>Após alterações nas 3 matrizes implementadas no código, a forma criada é a da imagem abaixo:</p>
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T3_pipeline_gr%C3%A1fico/img/exercicio5.png">

---
---

<h2>4. Modelos de Iluminação</h2>
<p>O objetivo desse trabalho é a familiarização com os modelos de iluminação tradicionalmente usados na rasterização, que são: <i>ambiente</i>, <i>difuso</i> e <i>especular (Phong)</i>. Para a atividade foi usado o código disponibilizado pelo professor, onde a cena a ser renderizada é uma malha de triângulos que representa o <i>Utah Teapot</i> e uma fonte de luz pontual.</p>
<p>O programa usado como base renderiza o <i>teapot</i> usado apenas o modelo de reflexão <i>ambiente</i>. A atividade consiste em alterar o conteúdo do <i>vertex shader</i> de forma a adicionar os outros modelos de reflexão, <i>difuso</i> e <i>especular</i>. A imagem apresentada após a compilação do template disponibilizado se encontra abaixo:</p>
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T4_shader_modelo_de_ilumina%C3%A7%C3%A3o/img/orginal000.png">

<h3>4.1 Modelo de Reflexão Difuso</h3>
<p>Para incluir o modelo de <i>difuso</i> é necessário calcular o valor do vetor normal N e o vetor L que aponta do vértice para a fonte de luz. Foi seguido as sugestões de cálculo dos dois vetores disponibilizados no documento, e o modelo de iluminação difuso a ser avaliado foi o seguinte:</p>
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T4_shader_modelo_de_ilumina%C3%A7%C3%A3o/img/formula1.png">
<p>Onde, <strong>Ia</strong> é a intesidade da luz ambiente, <strong>Ka</strong> é o coeficiente de reflectância ambiente, <strong>Ip</strong> é a intensidade da luz pontual, <strong>Kd</strong> é o coeficiente de reflectância do objeto e o <strong>cos θ</strong> é o cosseno do ângulo formado entre o vetor normal N e o vetor L.</p>
<p>As mudanças feitas no código base se encontram abaixo, assim como o resultado obtido por essas mudanças:</p>
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T4_shader_modelo_de_ilumina%C3%A7%C3%A3o/img/cod1.png">
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T4_shader_modelo_de_ilumina%C3%A7%C3%A3o/img/exercicio1.png">

<h3>4.2 Modelo de Reflexão Especular</h3>
<p>Além do modelo de iluminação ambiente e difuso, nesse exercício deve haver a inclusão do modelo <i>especular</i>. Para isso é necessário calcular o vetor R de reflexão da luz L e o vetor da câmera V, que aponta do vértice em questão para a câmera. As sugestões também foram seguidas, e o modelo de iluminação a ser avaliado deve ser:</p>
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T4_shader_modelo_de_ilumina%C3%A7%C3%A3o/img/formula2.png">
<p>Onde, <strong>Ia</strong> é a intesidade da luz ambiente, <strong>Ka</strong> é o coeficiente de reflectância ambiente, <strong>Ip</strong> é a intensidade da luz pontual, <strong>Kd</strong> é o coeficiente de reflectância do objeto, <strong>cos θ</strong> é o cosseno do ângulo formado entre o vetor normal N e o vetor L, <strong>Ks</strong> é o coeficiente de reflectância especular, <strong>cos α</strong> é o ângulo formado entre o vetor R e o vetor V e o <strong>n</strong> é a potência do termo especular.</p>
<p>As mudanças feitas no código se encontram abaixo assim como o resultado obtido.</p>
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T4_shader_modelo_de_ilumina%C3%A7%C3%A3o/img/cod2.png">
<img src="https://github.com/hananiasd/Computacao_Grafica/blob/master/T4_shader_modelo_de_ilumina%C3%A7%C3%A3o/img/exercicio2.png"https://github.com/hananiasd/Computacao_Grafica/blob/master/T4_shader_modelo_de_ilumina%C3%A7%C3%A3o/img/exercicio2.png>
