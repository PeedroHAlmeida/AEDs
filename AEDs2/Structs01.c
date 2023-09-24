#include <stdio.h>
#include <stdlib.h>

#define max 5 //TAMANHO MAXIMO DA LISTA

#define VERMELHO "\x1b[31m"
#define VERDE "\x1b[32m"
#define AMARELO "\x1b[33m"
#define AZUL "\x1b[34m"
#define RESETAR "\x1b[0m"

typedef struct Alunos{
    int aluno;
    float nota;
}Aluno;

//FUNÇÃO BUSCAR ALUNOS NA LISTA
int buscar(Aluno dados[], int tam, int cod_aluno){
    int i = 0;
    while(i < tam){
        if(dados[i].aluno == cod_aluno){
            // RETORNA A POSIÇÃO DA CHAVE
            return i; 
        }else{
            i = i + 1;
        }
    }
    //RETORNO DE NÃO ENCONTRADO
    return -1;
}

//FUNÇÃO INSERIR ALUNOS NA LISTA
int inserir(Aluno dados[], int tam, Aluno aux){
    //COLOCA OS DADOS NA LISTA
    dados[tam].aluno = aux.aluno;
    dados[tam].nota = aux.nota;
    //RETORNA O NOVO TAMANHO DA LISTA
    return tam + 1;
}

int main(int argc, char const *argv[])
{
    int tam = 4; //TAMANHO INICIAL DA LISTA
    int ret_buscar, ret_inserir; //DECLARAÇÃO DAS VARIÁVEIS RETORNO
    Aluno dados[max]; //CRIAÇÃO DA LISTA PRINCIPAL
    dados[0].aluno = 1;
    dados[0].nota = 7.5;
    dados[1].aluno = 2;
    dados[1].nota = 10;
    dados[2].aluno = 3;
    dados[2].nota = 8;
    dados[3].aluno = 4;
    dados[3].nota = 2.6;

    int resposta; //VARIÁVEL DE RESPOSTA DO USUÁRIO
    while (1){ 
        printf("\n------------- MENU -------------\n");
        printf("Escolha uma opção:\n");
        printf("1 - Buscar.\n");
        printf("2 - Inserir.\n");
        printf("3 - Remover.\n");
        printf("4 - Sair\n");
        printf("Digite a opção escolhida: ");
        scanf("%d", &resposta);

    
        switch (resposta){
            case 1:
                //FUNÇÃO BUSCAR
                int chave_aluno; //CHAVE DO ALUNO A SER BUSCADA
                printf("\nDigite a chave do aluno: ");
                scanf("%d", &chave_aluno);
                ret_buscar = buscar(dados, tam, chave_aluno);
                if(ret_buscar == -1){
                    // SE RETORNO DDA BUSCA == -1 VALOR NÃO FOI ENCONTRADO 
                    printf(VERMELHO "Valor não encontrado.\n" RESETAR);
                }else{
                    // CASO CONTRÁRIO É MOSTRADO POSIÇÃO DE VETOR ENCONTRADO E A NOTA DO ALUNO NA POSIÇÃO DA LISTA
                    printf(VERDE "\nValor encontrado na posição de vetor %d.\n" RESETAR, ret_buscar+1);
                    printf(VERDE "Nota do aluno = %.2f" RESETAR, dados[chave_aluno-1].nota);
                    printf("\n");
                }
                break;
            case 2:
                //FUNÇÃO INSERIR
                Aluno aux; // CRIAÇÃO DE UMA STRUCT AUXILIAR
                printf("\nDigite um valor para a chave do aluno: ");
                scanf("%d", &aux.aluno);
                // BUSCA SE O VALOR A SER INSERIADO JÁ É EXISTENTE
                ret_buscar = buscar(dados, tam, aux.aluno);
                if(ret_buscar == -1 && tam < max){
                    // SE VALOR DA BUSCA == -1 E TAMNHO ATUAL DO VETOR < TAMANHO MAXIMO A LISTA ACEITA ENTRADAS
                    printf("Digite a nota do aluno: ");
                    scanf("%f", &aux.nota);
                    ret_inserir = inserir(dados, tam, aux);
                    tam = ret_inserir;
                    printf(VERDE "Aluno inserido!" RESETAR);
                }else if (ret_buscar == -1){
                        // SE A LISTA SOMENTE == -1 A LISTA JÁ ESTÁ CHEIA
                        printf(VERMELHO "Lista cheia!\n" RESETAR);
                }else{
                    // NOS DEMAIS CASOS, É SINAL QUE O ALUNO JÁ PERTENCE A LISTA
                    printf(VERMELHO "Aluno já existente\n" RESETAR);
                }

                break;
            case 3:
                //remover
                break;
            case 4:
                //sair
                exit(0);
            default:
                // USUÁRIO FEZ UMA ENTRADA INVÁLIDA
                printf(VERMELHO "Opção inválida.\n" RESETAR);
                break;
        }
    }

    return 0;
}