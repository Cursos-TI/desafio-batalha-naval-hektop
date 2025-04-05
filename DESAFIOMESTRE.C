#include <stdio.h>
#include <stdlib.h>

#define N 10

// ORGANIZAR MATRIZ (tudo vira 0)
void limparMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            matriz[i][j] = 0;
}

// EXIBIÇÃO TABULEIRO
void exibirTabuleiro(int navios[N][N], int habilidade[N][N]) {
    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};

    printf("\n    ");
    for (int i = 0; i < N; i++) {
        printf("%c ", letras[i]);
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        printf("%2d | ", i + 1);
        for (int j = 0; j < N; j++) {
            if (navios[i][j] == 3) {
                printf("3 ");
            } else if (habilidade[i][j] == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Habilidade: Cone com base para baixo
void habilidadeCone(int matriz[N][N], int x, int y) {
    limparMatriz(matriz);
    int padrao[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int lin = x + i;
            int col = y + j - 2;
            if (lin >= 0 && lin < N && col >= 0 && col < N && padrao[i][j] == 1) {
                matriz[lin][col] = 1;
            }
        }
    }
}

// Habilidade: Cruz
void habilidadeCruz(int matriz[N][N], int x, int y) {
    limparMatriz(matriz);
    int padrao[4][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}

    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int lin = x + i - 1;
            int col = y + j - 2;
            if (lin >= 0 && lin < N && col >= 0 && col < N && padrao[i][j] == 1) {
                matriz[lin][col] = 1;
            }
        }
    }
}

// Habilidade: Octaedro
void habilidadeOctaedro(int matriz[N][N], int x, int y) {
    limparMatriz(matriz);
    int padrao[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int lin = x + i - 1;
            int col = y + j - 2;
            if (lin >= 0 && lin < N && col >= 0 && col < N && padrao[i][j] == 1) {
                matriz[lin][col] = 1;
            }
        }
    }
}

// POSIÇAO DOS NAVIOS
void posicionarNavios(int navios[N][N]) {
    limparMatriz(navios);

    navios[1][1] = 3;
    navios[1][2] = 3;
    navios[1][3] = 3;

    navios[0][7] = 3;
    navios[1][7] = 3;
    navios[2][7] = 3;

    navios[7][7] = 3;
    navios[8][8] = 3;
    navios[9][9] = 3;

    navios[9][0] = 3;
    navios[8][1] = 3;
    navios[7][2] = 3;
}

int main() {
    int navios[N][N], habilidade[N][N];
    int linha, coluna;
    char letraColuna;

    posicionarNavios(navios);

    printf("Digite a linha (1 a 10): ");
    scanf("%d", &linha);

    printf("Digite a coluna (A a J ou a a j): ");
    scanf(" %c", &letraColuna);

    // Converter manualmente letra minúscula para maiúscula
    if (letraColuna >= 'a' && letraColuna <= 'j') {
        letraColuna = letraColuna - 'a' + 'A';
    }

    // Verifica se a letra está no intervalo permitido
    if (letraColuna < 'A' || letraColuna > 'J') {
        printf("Coluna inválida.\n");
        return 1;
    }

    // Verifica se linha está no intervalo permitido
    if (linha < 1 || linha > 10) {
        printf("Linha inválida.\n");
        return 1;
    }

    linha -= 1; // Ajusta para índice da matriz
    coluna = letraColuna - 'A'; // Converte letra para índice

    int escolha;
    printf("\nEscolha a habilidade:\n");
    printf("1 - Cone\n");
    printf("2 - Cruz\n");
    printf("3 - Octaedro\n");
    printf(">> ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: habilidadeCone(habilidade, linha, coluna); break;
        case 2: habilidadeCruz(habilidade, linha, coluna); break;
        case 3: habilidadeOctaedro(habilidade, linha, coluna); break;
        default: printf("Habilidade inválida.\n"); return 1;
    }

    exibirTabuleiro(navios, habilidade);

    return 0;
}

