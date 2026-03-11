#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14
#define JUNTA1 "/base_link_respondable[0]/joint_1" //podia fazer usando strcat tbm, fiz assim pois vi um video que tinha que respeitar a hierarquia de juntas 
#define JUNTA2 "/base_link_respondable[0]/joint_1/joint_2"
#define JUNTA3 "/base_link_respondable[0]/joint_1/joint_2/joint_3"
#define JUNTA4 "/base_link_respondable[0]/joint_1/joint_2/joint_3/joint_4"
#define JUNTA5 "/base_link_respondable[0]/joint_1/joint_2/joint_3/joint_4/joint_5"
#define JUNTA6 "/base_link_respondable[0]/joint_1/joint_2/joint_3/joint_4/joint_5/joint_6"

// Inclusão da biblioteca externa C
extern "C" {
#include "extApi.h"
}



void inicioJUNTA1(int clientID, simxChar* handlerName, int* handler);
void inicioJUNTA2(int clientID, simxChar* handlerName, int* handler);
void inicioJUNTA3(int clientID, simxChar* handlerName, int* handler);
void inicioJUNTA4(int clientID, simxChar* handlerName, int* handler);
void inicioJUNTA5(int clientID, simxChar* handlerName, int* handler);
void inicioJUNTA6(int clientID, simxChar* handlerName, int* handler);
void inicio0(int clientID, simxChar* handlerName, int* handler);
void numero0(int clientID, simxChar* handlerName, int* handler);
void numero1(int clientID, simxChar* handlerName, int* handler);
void numero2(int clientID, simxChar* handlerName, int* handler);
void numero3(int clientID, simxChar* handlerName, int* handler);
void numero4(int clientID, simxChar* handlerName, int* handler);
void numero5(int clientID, simxChar* handlerName, int* handler);
void numero6(int clientID, simxChar* handlerName, int* handler);
void numero7(int clientID, simxChar* handlerName, int* handler);
void numero8(int clientID, simxChar* handlerName, int* handler);
void numero9(int clientID, simxChar* handlerName, int* handler);
void numeroconfirm(int clientID, simxChar* handlerName, int* handler);

// Função principal
int main(int argc, char* argv[]) {
    int handler = 0;
    simxChar handlerName[150] = "/base_link_respondable[0]";
    FILE* arquivo;
    int clientID = simxStart((simxChar*)"127.0.0.1", 19999, true, true, 2000, 5);

    if (clientID == -1) {
        printf("Erro conectando ao Coppelia!\n");
        exit(1);
    }
    else {
        printf("Conectado ao Coppelia!\n");
    }



    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    inicio0(clientID, handlerName, &handler);


    // local do arquivo que fiz
    arquivo = fopen("C:\\Users\\giova\\OneDrive\\Documentos\\output\\sugestoes_votos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro  no arquivo");
    }
    else {
        printf("arquivo aberto com sucesso!!");
    }
    char votos[70];
    //Pega le os votos de uma linha do  arquivo e depois volta pra ler de novo no loop até acabar.
    while (fgets(votos, 70, arquivo) != NULL)
    {
        for (int i = 0; i < strlen(votos); i++)
        { //se o botao um botao "n" aparecer no arquivo ele chama a função numero"n"
            if (votos[i] == '0')
            {
                numero0(clientID, handlerName, &handler);

            }
            else if (votos[i] == '1')
            {
                numero1(clientID, handlerName, &handler);

            }
            else if (votos[i] == '2')
            {
                numero2(clientID, handlerName, &handler);

            }
            else if (votos[i] == '3')
            {
                numero3(clientID, handlerName, &handler);

            }
            else if (votos[i] == '4')
            {
                numero4(clientID, handlerName, &handler);

            }
            else if (votos[i] == '5')
            {
                numero5(clientID, handlerName, &handler);

            }
            else if (votos[i] == '6')
            {
                numero6(clientID, handlerName, &handler);

            }
            else if (votos[i] == '7')
            {
                numero7(clientID, handlerName, &handler);

            }
            else if (votos[i] == '8')
            {
                numero8(clientID, handlerName, &handler);

            }
            else if (votos[i] == '9')
            {
                numero9(clientID, handlerName, &handler);

            }
        }

        numeroconfirm(clientID, handlerName, &handler); // quando acabar o loop  chama a fuunção de  confirmar
    }

    fclose(arquivo);
    return 0;
}





void inicioJUNTA1(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA1);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 10), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
} /// bota a junta 1 em tal posicão inicial para facilitar 

void inicioJUNTA2(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 5), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
}

void inicioJUNTA3(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA3);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 10), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
}

void inicioJUNTA4(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA4);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(0.121 * PI), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
}

void inicioJUNTA5(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA5);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)(0.065 * PI), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
}

void inicioJUNTA6(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA6);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)(0 * PI), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
}

void inicio0(int clientID, simxChar* handlerName, int* handler) { //essa função chama todas as outras funções de inicio

    inicioJUNTA2(clientID, handlerName, handler);
    inicioJUNTA3(clientID, handlerName, handler);
    inicioJUNTA4(clientID, handlerName, handler);
    inicioJUNTA5(clientID, handlerName, handler);
    inicioJUNTA6(clientID, handlerName, handler);
    inicioJUNTA1(clientID, handlerName, handler);

}

void numero0(int clientID, simxChar* handlerName, int* handler) { // por tenativa e teste agnt procura angulos de juntas para apertar o botao 0 
    strcpy(handlerName, JUNTA3);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 20), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2200);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 4), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1600);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.7), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1400);

    ;// e no final desse função chamo esses funções de inicio para voltar a posição desejada


    inicio0(clientID, handlerName, handler);
}

void numero1(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA1);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 17.5), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1700);

    strcpy(handlerName, JUNTA3);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)(PI / 22), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3400);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 4), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2300);

    strcpy(handlerName, JUNTA5);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(0.0325 * PI), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1750);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.75), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(700);


    inicio0(clientID, handlerName, handler);
}

void numero2(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA1);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 12.8), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(900);

    strcpy(handlerName, JUNTA3);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)(PI / 19.8), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2900);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.78), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1600);

    strcpy(handlerName, JUNTA5);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 40), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.7), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(600);


    inicio0(clientID, handlerName, handler);
}

void numero3(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA3);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)(PI / 21.2), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3300);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.78), (simxInt)simx_opmode_oneshot_wait);

    strcpy(handlerName, JUNTA5);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)(0 * PI), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2200);

    strcpy(handlerName, JUNTA3);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)(PI / 20), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1100);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.6), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(600);


    inicio0(clientID, handlerName, handler);
}

void numero4(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA1);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 12.5), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(500);

    strcpy(handlerName, JUNTA3);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 40), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3000);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 4), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1500);

    strcpy(handlerName, JUNTA5);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)(PI / 12.5), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1000);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.81), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(500);

    inicio0(clientID, handlerName, handler);
}

void numero5(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA3);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 50), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.8), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    strcpy(handlerName, JUNTA5);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)(PI / 11), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1200);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.7), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(500);

    inicio0(clientID, handlerName, handler);
}

void numero6(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA1);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI*0.12), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    strcpy(handlerName, JUNTA3);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 80), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.8), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    strcpy(handlerName, JUNTA5);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)(PI / 11), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1200);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.6), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(500);

    inicio0(clientID, handlerName, handler);
}

void numero7(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA1);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 12.5), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(500);

    strcpy(handlerName, JUNTA3);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 21.2), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3000);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 4), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1500);

    strcpy(handlerName, JUNTA5);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)(PI / 12.5), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1000);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.81), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(500);

    inicio0(clientID, handlerName, handler);;
}

void numero8(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA3);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 31), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.8), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    strcpy(handlerName, JUNTA5);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)(PI / 11), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1200);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.7), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(500);

    inicio0(clientID, handlerName, handler);

}

void numero9(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA1);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI * 0.12), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    strcpy(handlerName, JUNTA3);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 50), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.8), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    strcpy(handlerName, JUNTA5);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)(PI / 11), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1200);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(PI / 3.6), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(500);

    inicio0(clientID, handlerName, handler);
}


void numeroconfirm(int clientID, simxChar* handlerName, int* handler) {
    strcpy(handlerName, JUNTA1);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(0.145 * PI), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1000);

    strcpy(handlerName, JUNTA3);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(0.033 * PI), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(0.28 * PI), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1500);

    strcpy(handlerName, JUNTA2);
    simxGetObjectHandle(clientID, (simxChar*)handlerName, handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, *handler, (simxFloat)-(0.291 * PI), (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(500);

    inicio0(clientID, handlerName, handler);
}