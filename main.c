#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

void PrintarMenu();
void ProcessarComandos();

int main(void){
    //TESTE 
    PACIENTE *testePaciente = Paciente_Criar(1, "Carlos");
    Historico_InserirProcedimento(Paciente_GetHistorico(testePaciente), "Testando funcionalidade");
    ProcessarComandos();

    //LIBERAR MEMORIA
    Paciente_Free(&testePaciente);

    return 0;
}

void PrintarMenu(){
    printf("Selecione o Comando:\n");
    printf("1. Registrar paciente.\n");
    printf("2. Dar alta no paciente.\n");
    printf("3. Adicionar procedimento ao histórico médico.\n");
    printf("4. Desfazer procedimento do histórico médico.\n");
    printf("5. Chamar paciente para atendimento.\n");
    printf("6. Mostrar fila de espera.\n");
    printf("7. Mostrar histórico do paciente.\n");
    printf("8. Sair.\n");
}

void ProcessarComandos(){
    PrintarMenu();
    int comando;
    do{
        PrintarMenu();
        scanf(" %d", &comando);
        switch (comando)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            Historico_Printar(Paciente_GetHistorico());
            break;
        }
    }while(comando != 8);

    return;
}