#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <cs50.h>


int main(void){
        int opcao, teste;
        
        // Comandos do sistemas
        system("chcp 65001");
        system("color a");
        system("cls");

        // Primeira instância de opção
        printf("Selecione uma opção: \n");
        printf("1 - Jogo da Velha\n\n");
        printf("=========================\n\n");
        opcao = get_int("Opção: ");
        system("cls");

    do
    {
        if (opcao == 0){
            system("cls");

            printf("Selecione uma opção: \n");
            printf("1 - Jogo da Velha\n\n");
            printf("=========================\n\n");
            opcao = get_int("Opção: ");
            
            system("cls");
        } else if (opcao != 1 && opcao != 0)
        {
            system("cls");
            printf("- Desculpe, essa opcão não existe!\n\n");
        
            // Outras instâncias de opção
            printf("Selecione uma opção: \n");
            printf("1 - Jogo da Velha\n\n");
            printf("=========================\n\n");

            opcao = get_int("Opção: ");
            
        } else {
            while (true)
            {
                teste = system("jogo.exe"); 
                if (teste == -1){
                    printf("Não consegui executar seu comando."); 
                }
                string resp;
                while (true){
                    resp = get_string("\nJogar novamente? (S/N): ");
                    if (strcmp(resp, "S") != 0 && strcmp(resp, "N") != 0)
                    {
                        printf("Desculpe, não entendi sua resposta!");
                    } else {
                        break;
                    }
                }
                if (strcmp(resp, "N") == 0){
                    opcao = 0;
                    break;
                }
            }
        }
    } while (true);
    return 0;
}