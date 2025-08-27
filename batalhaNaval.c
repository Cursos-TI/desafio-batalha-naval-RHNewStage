#include <stdio.h>

// --- Função para inicializar o tabuleiro com zeros ---
void inicializarTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// --- Função para validar a posição e sobreposição do navio ---
int validarPosicao(int tabuleiro[10][10], int linha, int coluna, int orientacao) {
    // A orientação 0 representa horizontal e 1 representa vertical
    if (orientacao == 0) {
        // Valida se o navio horizontal cabe no tabuleiro
        if (coluna + 3 > 10) {
            return 0; // Fora do limite
        }
        // Valida se a posição já está ocupada por outro navio
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha][coluna + i] != 0) {
                return 0; // Posição ocupada, há sobreposição
            }
        }
    } else { // orientacao == 1
        // Valida se o navio vertical cabe no tabuleiro
        if (linha + 3 > 10) {
            return 0; // Fora do limite
        }
        // Valida se a posição já está ocupada por outro navio
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha + i][coluna] != 0) {
                return 0; // Posição ocupada, há sobreposição
            }
        }
    }
    return 1; // Posição válida
}

// --- Função para posicionar o navio no tabuleiro ---
void posicionarNavio(int tabuleiro[10][10], int linha, int coluna, int orientacao) {
    if (orientacao == 0) {
        // Posiciona navio horizontalmente
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha][coluna + i] = 3; // 3 representa o navio
        }
    } else { // orientacao == 1
        // Posiciona navio verticalmente
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha + i][coluna] = 3; // 3 representa o navio
        }
    }
}

// --- Função para exibir o tabuleiro ---
void exibirTabuleiro(int tabuleiro[10][10]) {
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("  ");
    // Loop para imprimir as letras das colunas (A a J)
    for (char c = 'A'; c <= 'J'; c++) {
        printf("%c ", c);
    }
    printf("\n");
    printf("---------------------\n");

    // Loop para imprimir as linhas do tabuleiro
    for (int i = 0; i < 10; i++) {
        printf("%d|", i); // Imprime o número da linha
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com 0s (água)
    inicializarTabuleiro(tabuleiro);

    // Coordenadas e orientação dos navios
    int linha_navio1 = 2;
    int coluna_navio1 = 1;
    int orientacao_navio1 = 0; // 0 = horizontal

    int linha_navio2 = 4;
    int coluna_navio2 = 5;
    int orientacao_navio2 = 1; // 1 = vertical
    
    // Valida e posiciona o primeiro navio
    if (validarPosicao(tabuleiro, linha_navio1, coluna_navio1, orientacao_navio1)) {
        posicionarNavio(tabuleiro, linha_navio1, coluna_navio1, orientacao_navio1);
    } else {
        printf("Posicao do Navio 1 invalida (fora dos limites ou sobreposicao).\n");
    }

    // Valida e posiciona o segundo navio
    if (validarPosicao(tabuleiro, linha_navio2, coluna_navio2, orientacao_navio2)) {
        posicionarNavio(tabuleiro, linha_navio2, coluna_navio2, orientacao_navio2);
    } else {
        printf("Posicao do Navio 2 invalida (fora dos limites ou sobreposicao).\n");
    }

    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}