# Trabalho 1 (T1)

# Descrição do Problema

Gomoku é um jogo de tabuleiro para dois jogadores. Os jogadores alternam em colocar uma pedra de sua cor (branco e preto) em um quadrado do tabuleiro que tem 8 colunas e 8 linhas, e quem tiver cinco (5) pedras consecutivas na horizontal, vertical ou diagonal ganha o jogo. Gomoku-N é uma versão estendida de Gomoku, alterando o número de pedras consecutivas vencedoras para N e o tamanho do tabuleiro é 2 * N por 2 * N. Por exemplo, se N = 6, então o tamanho do tabuleiro é 12 x 12 e o jogador que tem 6 pedras consecutivas na horizontal, vertical ou diagonal ganha o jogo. Quando o tabuleiro está cheio e não há vencedor, o jogo termina empatado. 

# Objetivo do trabalho

O objetivo deste trabalho é implementar um programa que permita que dois jogadores disputem uma partida de Gomoku-N  por meio do computador.

Quando um jogador coloca uma pedra no tabuleiro, o programa deve verificar se o jogador venceu o jogo. Para tal, o programa determina se a nova pedra conectou N pedras juntas horizontalmente, verticalmente ou diagonalmente. As verificações das três direções são independentes umas das outras. Pthreads devem realizar a verificação de cada uma das três direções.

O tabuleiro é modelado como uma matriz de 2N * 2N, onde N é um valor fornecido quando do início da partida e a célula superior esquerda é a de posição (0, 0) e a inferior direita é (2N-1, 2N-1). Após definido o valor de N, o programa determina aleatoriamente o jogador que inicia a partida. O  jogador faz sua jogada inserindo as coordenadas da célula em que deseja colocar a pedra e o formato de entrada deve ser a linha, coluna. Por exemplo, se o jogador quiser colocar a pedra na célula da linha 0 e coluna 5, o jogador deve inserir 0 5. Após cada jogada, é mostrado o estado do tabuleiro atualizado (um jogador pode ser representado por 'X' e o outro por 'O'). No final do jogo, o programa informa o vencedor ou empate.

# Método

A implementação deve ser realizada na linguagem C. A versão paralela deve ser implementada para ambiente Unix usando pthreads.
