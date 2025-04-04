#include <stdio.h>
    void tabuleiro(int tabuleiro[10][10]){
        char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // LINHAS DE LETRA DE a - j

        printf(" BATALHA NAVAL \n");

        // IMPRESSÃO DAS LETRAS 

        printf(" ");
        for (int i = 0; i < 10; i++)
        {
            printf(" %c", linha[i]);

        }
        printf("\n");

        // COLUNA DE NUMEROS 1 - 10

        for (int i = 0; i < 10; i++)
        {
            printf("%2d", i + 1);
            for (int j = 0; j < 10; j++)
            {
                if (tabuleiro[i][j] == 3)
                {
                    printf(" 3");
                }else{
                    printf(" 0");
                }
                
            }
            printf("\n");
        }
        
    }
    int main(){
        int navio[10][10] = {0}; // Posicionando os navios no tabuleiro (valores 3 representam a parte do navio)

        navio[1][1] = 3;
        navio[1][2] = 3;
        navio[1][3] = 3;

        navio[1][7] = 3;
        navio[2][8] = 3;
        navio[3][9] = 3;

        navio[7][1] = 3;
        navio[8][2] = 3;
        navio[9][3] = 3;

        navio[6][4] = 3;
        navio[7][4] = 3;
        navio[8][4] = 3;

        tabuleiro(navio); // impressão do tabuleiro

        return 0;
        
    }
