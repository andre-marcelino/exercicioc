#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_TENTATIVAS_FACIL 20
#define N_TENTATIVAS_MEDIO 15
#define N_TENTATIVAS_DIFICIL 6
#define PONTOS_INICIAL 1000

int main() {
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n");

    int jogarnovamente = 1;

    while (jogarnovamente) {
    
        srand(time(0));

        int nivel;
        int totaldetentativas;
        int numerogrande = rand();
        int numerosecreto;
        int chute;
        int acertou = 0;
        int min = 0;
        int max = 99;
        int buffer;
        double pontos = PONTOS_INICIAL;

        printf("\nQual o nivel de dificuldade?\n");
        printf("(1) Facil (2) Medio (3) Dificil\n\n");
        printf("Escolha: ");
        scanf("%d", &nivel);

        printf("Escolha o range minimo: ");
        scanf("%d", &min);
        printf("Escolha o range maximo: ");
        scanf("%d", &max);

        numerosecreto = min + numerogrande % (max - min + 1);


        switch (nivel) {
        case 1:
           totaldetentativas = N_TENTATIVAS_FACIL;
           break;

        case 2:
            totaldetentativas = N_TENTATIVAS_MEDIO;
            break;

        default:
            totaldetentativas = N_TENTATIVAS_DIFICIL; 
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

            if(buffer == chute) {
                printf("Voce ja chutou esse numero. Escolha outro!\n");
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
            
            buffer = chute;


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

        printf("Digite (1) para jogar novamente: ");
        scanf("%d", &jogarnovamente);

        if(jogarnovamente != 1) jogarnovamente = 0; 

    } 
    
    printf("Fim de jogo!");
}