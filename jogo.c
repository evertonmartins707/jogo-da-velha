#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

// Variáveis globais
string jogo[3][3];
string jogador = "O";
int velha = 0;
bool jogada = false;
bool ganhador = false;

// Protótipos
string mostrarJogo();
string verificarJogada();
void verificarVencedor();

int main(void)
{
    // Variáveis
    int linha, coluna = 0;
    string vencedor = "O";

    system("chcp 65001");
    // Preenchimento inicial da matriz
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            jogo[i][j] = " ";
        }
    }

    // Jogo
    do{
        system("cls");
        jogada = false;

        // Mudar jogador
        if(strcmp(jogador, "O") == 0){
            jogador = "X";
        } else {
            jogador = "O";
        }
        velha = 0;
        printf("\nJogador: %s\n\n", jogador);
        mostrarJogo();

        // Verificar se a jogada é verdadeira
        while (jogada != true){
            
            // Receber o valores da posição
            linha = get_int("Digite a linha: ");
            
            // Verificar se o valor da linha é aceito
            if(linha == 1 || linha == 2 || linha == 3) {
                coluna = get_int("Digite a coluna: ");
                
                // Verificar se o valor da coluna é aceito
                if(coluna == 1 || coluna == 2 || coluna == 3) {
                    // Verificar se a jogada é possível
                    verificarJogada(linha, coluna);
                } else {
                    printf("Coluna inválida! Tente novamente!");
                    continue;
                }
            } else {
                printf("\nLinha inválida! Tente novamente!\n\n");
                continue;
            }
        }
        verificarVencedor();
        if (velha == 9)
        {
            break;
        }
        
        
        // Verficar jogo
    } while (ganhador != true);

    system("cls");
    mostrarJogo();

    if(velha == 9){
        printf("\n-------------------------------\n");
        printf("|######### DEU VELHA #########|\n");
        printf("-------------------------------\n");
    } else {
        // Mostrar vencedor
        printf("\n-------------------------------\n");
        printf("|####### VENCENDOR |%s| #######|\n", jogador);
        printf("-------------------------------\n");
    }

    return 0;
}

string mostrarJogo(){

    printf("-------------------------------\n");
    printf("|####### JOGO DA VELHA #######|\n");
    printf("-------------------------------\n");

    printf("         1     2     3\n");
    for (int i = 0; i < 3; i++){
        printf("      %i", i+1);
        for (int j = 0; j < 3; j++){
            printf(" [%s] ", jogo[i][j], j);
            if (j < 2){
                printf("|");
            }
        }
        printf("\n");
    }
}

string verificarJogada(int linha, int coluna){
    linha--;
    coluna--;
    string jogadaFeita = jogo[linha][coluna];

    if ( strcmp(jogadaFeita, " ") == 0)
    {
        // adicionar jogada
        jogo[linha][coluna] = jogador;
        jogada = true;
    } else {
        printf("\nCampo ocupado! Tente novamente!\n\n");
    }
    return 0;
}

void verificarVencedor(){

    // Verificação na horizontal
    for (int i = 0; i < 3; i++)
    {
        int j = 0;
        if (strcmp(jogo[i][0], jogo[i][1]) == 0 && strcmp(jogo[i][0], jogo[i][2]) == 0 && strcmp(jogo[i][0], " ") != 0)
        {
            ganhador = true;
        }
        
    }
    // Verificação na vertical
    for (int j = 0; j < 3; j++)
    {
        if (strcmp(jogo[0][j], jogo[1][j]) == 0 && strcmp(jogo[0][j], jogo[2][j]) == 0 && strcmp(jogo[0][j], " ") != 0)
        {
            ganhador = true;
        }
        
    }
    // Verificação na diagonal | esquerda-direita
    if (strcmp(jogo[1][1], jogo[0][0]) == 0 && strcmp(jogo[1][1], jogo[2][2]) == 0 && strcmp(jogo[0][0], " ") != 0)
    {
        ganhador = true;
    }
    // Verificação na diagonal | direita-esquerda
    if (strcmp(jogo[1][1], jogo[0][2]) == 0 && strcmp(jogo[1][1], jogo[2][0]) == 0 && strcmp(jogo[0][2], " ") != 0)
    {
        ganhador = true;
    }
    // Verificação de velha
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(strcmp(jogo[i][j], " ") != 0)
            {
                velha++;
            }
        }
    }
}