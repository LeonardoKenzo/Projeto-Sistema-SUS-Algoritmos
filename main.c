#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "fila_de_atendimento.h"
#include "relacao_de_pacientes.h"
#define TAMFILA 25

void printar_menu();
PACIENTE *ler_paciente(RELACAO_DE_PACIENTE *relacao);
void registrar_paciente(RELACAO_DE_PACIENTE *relacao, FILA_DE_ATENDIMENTO *fila, PACIENTE *novoPaciente);

int main(void){
    RELACAO_DE_PACIENTE *relacao = relacao_criar();
    FILA_DE_ATENDIMENTO *fila = fila_criar(TAMFILA);

    int comando;
    do{
        printar_menu();
        scanf(" %d", &comando);
        switch (comando)
        {
        case 1: //Registro de Pacientes
            PACIENTE *novoPaciente = ler_paciente(relacao);
            registrar_paciente(relacao, fila, novoPaciente);
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
            break;
        }
    }while(comando != 8);

    //LIBERAR MEMORIA
    fila_liberar(&fila);
    relacao_free(&relacao);

    return 0;
}

void printar_menu(){
    printf("Selecione o Comando:\n");
    printf("1. Registrar paciente.\n");
    printf("2. Registrar óbito de paciente.\n");
    printf("3. Adicionar procedimento ao histórico médico.\n");
    printf("4. Desfazer procedimento do histórico médico.\n");
    printf("5. Chamar paciente para atendimento.\n");
    printf("6. Mostrar fila de espera.\n");
    printf("7. Mostrar histórico do paciente.\n");
    printf("8. Sair.\n");
}

PACIENTE *ler_paciente(RELACAO_DE_PACIENTE *relacao){
    int id;
    char nome[100];
    //Le o nome e id do paciente
    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", nome);
    printf("Digite o id a ser registrado: ");
    scanf(" %d", &id);

    //Verifica se o id ja existe
    while(paciente_get_id(relacao_registro_busca(relacao, id)) != -1){
        printf("Esse id já existe, escolha outro: ");
        scanf(" %d", &id);
    }

    //Retorna o paciente dado
    PACIENTE *novoPaciente = paciente_criar(id, nome);
    return novoPaciente;
}

void registrar_paciente(RELACAO_DE_PACIENTE *relacao, FILA_DE_ATENDIMENTO *fila, PACIENTE *novoPaciente){
    //Se nao foi possivel inserir o paciente no registro libera memoria
    if(!relacao_inserir_paciente(relacao, novoPaciente)){
        paciente_free(&novoPaciente);
        return;
    }
    if(!fila_inserir(fila, novoPaciente)){
        relacao_apagar_paciente(relacao, paciente_get_id(novoPaciente));
        paciente_free(&novoPaciente);
        return;
    }
    printf("Paciente registrado e dentro da fila de espera!\nNome: %s\nId: %d\n\n", paciente_get_nome(novoPaciente), paciente_get_id(novoPaciente));
}