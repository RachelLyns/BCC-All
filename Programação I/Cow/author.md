# introdução

Este projeto é uma implementação do jogo "Pig Dice". 
Pig Dice é um jogo de dados em que dois jogadores tentam chegar a 100 pontos primeiro. 
Eles acumulam pontos lançando dados, mas perderão a vez se rolarem um 1. 
O programa escolhe aleatoriamente quem começa, exibe os resultados dos lançamentos, 
a pontuação parcial e determina o vencedor.

# Author(s)

-Joás Leon Rocha Melo
-email: leon.rocha.702@ufrn.edu.br

-Moisés Atila Rodrigues Lima
-email: moises.lima.115@ufrn.edu.br

# Problemas encontrados e limitações

O jogo e codigo estão funcionando conforme solicitado, entretanto, devido a forma que foi construido teriamos dificuldades de realizar mais implementações ou atualizações.

·Problemas econtrados durante o processo do jogo:
    - O principal problema durante o desenvolvimento foi a mudança de estágio do jogo (Erros consertados).
    - Na utilização e entendimento do codigos fornecidos, refizemos tudo do zero, mas seguindo a mesma logica pedida.

·Limitações:
    -O jogador "Bot" ficou com uma inteligencia limitada.
    -O jogo se limita ao jogador "You" e "Bot" apenas.




# Grading

Item     | Valor máximo   | Valor esperado
-------- | :-----: | :-----:
Shows the game rules | 5 | 5
Randomly chooses the player who starts the match | 5 | 5
Program runs correctly, alternating turns between players | 10 | 10
Keeps the correct values of the turn total    | 10 | 10
Display the plays/outcomes of the human as requested in this document | 10 | 10
Display the plays/outcomes of the machine as requested in this document | 10 | 10
Show the match's partial score | 10 | 10
Show the action log at the end of a match | 10 | 10
Identify the winner correctly | 10 | 10
Created at least two classes | 10 | 10
Program handles errors properly | 10 | 10

# Compilar e executar

- Para compilar use "cmake -S src -B build".
- Depois use "cmake --build build" para acionar o processo de compilação dentro da pasta build.
- Para executar testes use "./build/pig_dice".