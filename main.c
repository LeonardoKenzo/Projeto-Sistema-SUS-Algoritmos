#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "fila_de_atendimento.h"
#include "relacao_de_pacientes.h"
#define TAMFILA 25

PACIENTE *ler_paciente(RELACAO_DE_PACIENTE *relacao);
PACIENTE *buscar_paciente(RELACAO_DE_PACIENTE *relacao);
void registrar_paciente(RELACAO_DE_PACIENTE *relacao, FILA_DE_ATENDIMENTO *fila, PACIENTE *novoPaciente);
void adicionar_procedimento(RELACAO_DE_PACIENTE *relacao);
void mostrar_historico(RELACAO_DE_PACIENTE *relacao);
void printar_menu();

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
        case 2: //Registrar obito do Paciente
            break;
        case 3: //Adicionar procedimento ao historico medico
            adicionar_procedimento(relacao);
            break;
        case 4: //Desfazer procedimento do historico medico
            break;
        case 5: //Chamar paciente para atendimento
            break;
        case 6: //Mostrar fila de espera
            break;
        case 7: //Mostrar historico do paciente
            mostrar_historico(relacao);
            break;
        }
    }while(comando != 8);

    //LIBERAR MEMORIA
    fila_free(&fila);
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
    printf("\nDigite o nome do paciente: ");
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

void mostrar_historico(RELACAO_DE_PACIENTE *relacao){
    PACIENTE *paciente = buscar_paciente(relacao);
    printf("Paciente: %s\n", paciente_get_nome(paciente));
    historico_printar(paciente_get_historico(paciente));
    printf("\n");
}

void adicionar_procedimento(RELACAO_DE_PACIENTE *relacao){
    PACIENTE *paciente = buscar_paciente(relacao);

    //Insere o procedimento
    char procedimento[100];
    printf("Escreva o procedimento abaixo:\n");
    scanf(" %[^\n]", procedimento);
    historico_inserir_procedimento(paciente_get_historico(paciente), procedimento);
    printf("\n");
}

//Busca um paciente dentro do registro
PACIENTE *buscar_paciente(RELACAO_DE_PACIENTE *relacao){
    int id;
    PACIENTE *paciente;

    //Garante que o id deva existir
    do{
        printf("\nDigite o id do paciente: ");
        scanf(" %d", &id);
        paciente = relacao_registro_busca(relacao, id);
        if(paciente == NULL){
            printf("Paciente não registrado, digite um id válido.\n");
        }
    }while(paciente == NULL);

    return paciente;
}
