#include <stdio.h>
    void tabuleiro(int tabuleiro[10][10]){
        char linha [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};


            printf(" BATALHA NAVAL \n");
            printf(" ");
            for (int i = 0; i < 10; i++)
            {
                printf("%c", linha[i]);
            }
            printf("\n");


            
            for (int j = 0; j < 10; j++)
            {
                printf(j+1);
                for (int j = 0; j < 10; j++)
                {
                    printf("%d", tabuleiro[j][j]);
                }
                printf("\n");
            }
            

           
    }

    int main(){
        int navio[10][10] = {0};

        navio [1][1] = 3;
        navio [1][2] = 3;
        navio [1][3] = 3;

        navio [1][7] = 3;
        navio [2][8] = 3;
        navio [3][9] = 3;

        navio [7][1] = 3;
        navio [8][2] = 3;
        navio [9][3] = 3;

        navio [6][4] = 3;
        navio [7][4] = 3;
        navio [8][4] = 3;


        return 0;
        }



