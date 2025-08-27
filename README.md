# SuperTrunfoAventureiro1Super Trunfo em C
Este projeto é um jogo de console em C que simula uma rodada do jogo de cartas Super Trunfo, comparando dois países com base em atributos escolhidos pelo jogador.

Como Usar no Visual Studio
Para compilar e rodar este projeto no Visual Studio, siga estes passos:

1. Crie o Projeto:

Abra o Visual Studio e vá em File > New > Project....

Escolha o template "Console App" (geralmente encontrado em C++).

Dê um nome ao seu projeto (ex: SuperTrunfo) e clique em Create.

2. Adicione o Código:

O Visual Studio criará um arquivo de código-fonte principal (ex: SuperTrunfo.cpp).

Renomeie este arquivo para ter a extensão .c (ex: super_trunfo.c). Isso garante que o Visual Studio o compile como um código C.

Apague o conteúdo padrão e copie e cole o código do jogo neste arquivo.

3. Compile e Execute:

Para rodar o programa, a melhor opção é ir ao menu Debug e selecionar Start Without Debugging.

Atalho: Ctrl + F5.

Dica: Usar Start Without Debugging (Ctrl + F5) impede que o console feche automaticamente assim que o programa terminar, permitindo que você veja o resultado final.

Atributos para Comparação
Você pode escolher dois atributos diferentes para a batalha:

1 - População: Maior valor vence.

2 - Área: Maior valor vence.

3 - PIB: Maior valor vence.

4 - Pontos Turísticos: Maior valor vence.

5 - Densidade Demográfica: Menor valor vence.

Exemplo de uma Rodada
1. Primeiro, você informa os dados dos dois países:

--- DADOS DO PAIS 1 ---
Nome: Brasil
Populacao: 215000000
Area: 8500000
PIB: 1.6
Pontos Turisticos: 1500

--- DADOS DO PAIS 2 ---
Nome: Japao
Populacao: 125000000
Area: 377000
PIB: 4.2
Pontos Turisticos: 2000
2. Depois, escolhe o primeiro atributo para a batalha:

JOGADOR 1, ESCOLHA O PRIMEIRO ATRIBUTO:
1 - Populacao
2 - Area
3 - PIB
4 - Pontos Turisticos
5 - Densidade Demografica (menor vence)

Digite sua escolha: 1

3. Em seguida, o menu para o segundo atributo aparece sem a opção já escolhida:

JOGADOR 1, ESCOLHA O SEGUNDO ATRIBUTO (diferente do primeiro):
2 - Area
3 - PIB
4 - Pontos Turisticos
5 - Densidade Demografica (menor vence)

Digite sua escolha: 3

Por fim, o placar final é exibido:



--- PLACAR DA RODADA ---
Atributos escolhidos: Populacao e PIB

--- Brasil ---
Populacao: 215000000.00
PIB: 1.60
SOMA DE PODER: 215000001.60

--- Japao ---
Populacao: 125000000.00
PIB: 4.20
SOMA DE PODER: 125000004.20

---------------------------------------
Resultado: O GRANDE VENCEDOR E Brasil!
---------------------------------------