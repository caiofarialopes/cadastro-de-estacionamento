#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void linha(){
    printf("--------------------------------------------------\n");
}

struct cadastro{
        char nome[50];
        char modelo[50];
        char placa[50];
        char telefone[20];
    };
    
void criacadastro(){
    FILE *arquivo;
    linha();
        struct cadastro pes;
        arquivo = fopen("cadastros.txt","a");
        printf("Digite seu nome: ");
        fgets(pes.nome, 50, stdin);
        printf("Digite o modelo do carro: ");
        fgets(pes.modelo,50,stdin);
        printf("Digite a placa: ");
        fgets(pes.placa,50,stdin);
        printf("Digite seu telefone: ");
        fgets(pes.telefone,20,stdin);

        pes.nome[strcspn(pes.nome, "\n")] = '\0';
        pes.modelo[strcspn(pes.modelo, "\n")] = '\0';
        pes.placa[strcspn(pes.placa, "\n")] = '\0';

        fprintf(arquivo, "%s;%s;%s;%s;\n", pes.nome, pes.modelo, pes.placa, pes.telefone);

        printf("\n\nCadastro criado!\n");

        fclose(arquivo);
}

void consulta(){
    FILE *arquivo;
    printf("\n............CONSULTA............\n\n");
        char verifica[10];
        char linha[100], nome[100], carro[100], placa[100], telefone[100];
        int encontrou=0;
        printf("Digite a placa do carro: ");
        scanf("%9s", verifica);
        while(getchar() != '\n');

        arquivo = fopen("cadastros.txt","r");
        if(arquivo == NULL){
            printf("ERRO!");
        }

        while(fgets(linha, sizeof(linha), arquivo) != NULL){
            linha[strcspn(linha, "\n")] = '\0';

            char *nome = strtok(linha, ";");
            char *carro = strtok(NULL, ";");
            char *placa = strtok(NULL, ";");
            char *telefone = strtok(NULL, ";");

            if(placa != NULL && strcmp(placa, verifica) == 0){
                printf("\nCadastro encontrado!\n\n");
                printf("Nome: %s\n", nome);
                printf("Carro: %s\n", carro);
                printf("Placa: %s\n", placa);
                printf("Telefone: %s\n", telefone);

            encontrou = 1;
            }
        }

        if(!encontrou){
            printf("Cadastro não encontrado.");
        }

        fclose(arquivo);
}

void deleta(){
     FILE *arquivo, *temp;
     char linha[200];
    char verifica[20];
    int encontrou = 0;

    printf("\n............DELETAR............\n\n");

    printf("Digite a placa para deletar: ");
    scanf("%19s", verifica);
    while(getchar() != '\n');

    arquivo = fopen("cadastros.txt", "r");
    temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL){

        char copia[200];
        strcpy(copia, linha);

        copia[strcspn(copia, "\n")] = '\0';

        char *nome = strtok(copia, ";");
        char *carro = strtok(NULL, ";");
        char *placa = strtok(NULL, ";");
        char *telefone = strtok(NULL, ";");

        if (placa != NULL && strcmp(placa, verifica) == 0){
            printf("\nCadastro removido!\n");
            encontrou = 1;
            continue;
        }

        fputs(linha, temp);
    }

    fclose(arquivo);
    fclose(temp);

    remove("cadastros.txt");
    rename("temp.txt", "cadastros.txt");

    if (!encontrou){
        printf("Placa não encontrada.\n");
    }
}

int main(){

    int op;

    printf("\n\n");
    linha();

do{
    printf("\n............CADASTRO............\n\n");
    printf("[1] - Criar Cadastro.\n[2] - Consultar Cadastro.\n[3] - Deletar Cadastro.\n[4] - Sair.\n\n");
    scanf("%i",&op);
    while(getchar() != '\n');
    
    switch (op){
        case 1:
            criacadastro();
        break;

        case 2:
            consulta();
        break;

        case 3:
            deleta();
        break;

        case 4:
            return 0;
        break;
    }

} while(op != 3);

    return 0;
}