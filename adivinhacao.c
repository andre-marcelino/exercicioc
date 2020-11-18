#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define NUMERO_DE_TENTATIVAS 3

int main() {
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    srand(time(0));

    int nivel;
    int totaldetentativas;
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;
    int chute;
    int acertou = 0;
    //int tentativas = 1;
    double pontos = 1000;

/*    for (int i = 1; i <= NUMERO_DE_TENTATIVAS; i++) {
        printf("Qual e o seu %do. chute? ", i);
        scanf("%d", &chute);
        
        if(chute < 0) {
            printf("Voce nao pode chutar numeros negativos\n");
            i--;
            continue;
        }

        printf("Seu chute foi %d\n", chute);

        int acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if (acertou) {
            printf("Parabens! Voce acertou!\n");
            break;
        } else if (maior) {
                printf("Seu chute foi maior do que o numero secreto!\n");
            } else {
                printf("Seu chute foi menor do que o numero secreto!\n");
            }
    }
*/

    printf("Qual o nivel de dificuldade?\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    /*
    if(nivel == 1) {
        totaldetentativas = 20;
    } else if (nivel == 2) {
        totaldetentativas = 15;
    } else {
        totaldetentativas = 6;
    }
    */

   switch (nivel)
   {
   case 1:
       totaldetentativas = 20;
       break;

    case 2:
        totaldetentativas = 15;
        break;
    
   default:
        totaldetentativas = 6; 
        break;
   }

    
    
    for(int i = 1; i <= totaldetentativas; i++) {
        printf("Tentativa %d de %d\n", i, totaldetentativas);
        printf("Chute um numero: ");
        scanf("%d", &chute);
        
        if(chute < 0) {
            printf("Voce nao pode chutar numeros negativos\n");
            i--;
            continue;
        }

        printf("Seu %do. chute foi %d\n", i, chute);
        
        acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if (acertou) {
            break;
        } else if (maior) {
                printf("Seu chute foi maior do que o numero secreto!\n");
            } else {
                printf("Seu chute foi menor do que o numero secreto!\n");
            }
        

        double pontosperdidos = abs(chute-numerosecreto)/2.0;
        pontos = pontos - pontosperdidos;

    }

    if (acertou) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("Parabens! Voce acertou!\n");
        printf("Voce fez %.2f pontos\n", pontos);
    } else {
        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");
        printf("Voce perdeu! Tente novamente!");
    } 
    
    printf("Fim de jogo!");
}