#include <stdio.h>
#include <stdlib.h>
#include "relacao_de_pacientes.h"

#define CAPACIDADE_INICIAL 10

struct relacao_de_pacientes_{
    PACIENTE **pacientes;
    int quantidade;
    int capacidade;
};

int busca_binaria_indice(Relacao_De_Pacientes **relacao, int id, int inicio, int fim){
    if (inicio > fim){
        return -1;
    }

    int meio = inicio + (fim - inicio) / 2;
    int id_meio = paciente_get_id((*relacao)->pacientes[meio]);

    if (id_meio == id){
        return meio;
    }
    else if (id_meio > id){
        return busca_binaria_indice(relacao, id, inicio, meio-1);
    }
    else if (id_meio < id){
        return busca_binaria_indice(relacao, id, meio+1, fim);
    }
}

int busca_binaria_insercao(Relacao_De_Pacientes **relacao, int id){
    int inicio = 0;
    int fim = ((*relacao)->quantidade)-1;

    while (inicio <= fim){
        int meio = inicio + (fim - inicio)/2;
        int id_meio = paciente_get_id((*relacao)->pacientes[meio]);

        if (id_meio < id){
            inicio = meio + 1;
        }else{
            fim = meio - 1;
        }
    }
    return inicio;
}

Relacao_De_Pacientes *relacao_criar(){
    Relacao_De_Pacientes *relacao;
    relacao = (Relacao_De_Pacientes*)malloc(sizeof(Relacao_De_Pacientes));
    if (relacao == NULL) {
        return NULL;
    }
    relacao->pacientes = (PACIENTE **)malloc(CAPACIDADE_INICIAL * sizeof(PACIENTE*));
    if (relacao->pacientes == NULL) {
        free(relacao);
        return NULL;
    }
    relacao->capacidade = CAPACIDADE_INICIAL;
    relacao->quantidade = 0;
    return relacao;
}

void relacao_free(Relacao_De_Pacientes **relacao){
    if (relacao == NULL || *relacao == NULL){
        return;
    }else{
        for (int i = 0; i < (*relacao)->quantidade; i++){
            paciente_free(&((*relacao)->pacientes[i]));
        }
        free((*relacao)->pacientes);
        (*relacao)->capacidade = 0;
        (*relacao)->quantidade = 0;
        free(*relacao);
        *relacao = NULL;
        return;
    }
}

bool relacao_esta_vazia(Relacao_De_Pacientes **relacao){
    if (relacao == NULL || *relacao == NULL){
        return true;
    }else{
        return (*relacao)->quantidade == 0;
    }
}

void relacao_listar_pacientes(Relacao_De_Pacientes **relacao){
    if (relacao == NULL || *relacao == NULL || relacao_esta_vazia(relacao)){
        printf("Relação Vazia ou inexistente\n");
        return;
    }else{
        printf("%-10s | %-30s\n", "ID", "NOME");

        for (int i = 0; i < (*relacao)->quantidade; i++){        
            PACIENTE *p = (*relacao)->pacientes[i];
            int id = paciente_get_id(p);
            char *nome = paciente_get_nome(p);

            printf("%-10d | %-30s\n", id, nome);
        }
    }
    printf("Total de pacientes: %d\n\n", (*relacao)->quantidade);
    return;
}

PACIENTE *registro_busca(Relacao_De_Pacientes **relacao, int id){
    if (relacao == NULL || *relacao == NULL || relacao_esta_vazia(relacao)){
        printf("Relação Vazia ou inválida\n");
        return NULL;
    }else{
        int aux = busca_binaria_indice(relacao, id, 0, ((*relacao)->quantidade)-1);
        if (aux == -1){
            return NULL;
        }else{
            return (*relacao)->pacientes[aux];
        }
    }
}

bool relacao_inserir_paciente(Relacao_De_Pacientes **relacao, PACIENTE *paciente){
    if (relacao == NULL || *relacao == NULL){
        printf("Relação inválida\n");
        return NULL;
    }

    int id_atual = paciente_get_id(paciente);

    if (registro_busca(relacao, id_atual) != NULL){
        printf("Um paciente com mesmo Id já foi registrado\n");
        return false;
    }

    if ((*relacao)->capacidade == (*relacao)->quantidade){
        PACIENTE **aux = realloc((*relacao)->pacientes, (((*relacao)->capacidade) * 2) * sizeof(PACIENTE*));
        if (aux == NULL){
            printf("Limite de memória máximo atingido\n");
            return false;
        }else{
            (*relacao)->pacientes = aux;
            (*relacao)->capacidade = (((*relacao)->capacidade) * 2);
        }
    }

    int indice_insercao = busca_binaria_insercao(relacao, id_atual);
    for (int i = (*relacao)->quantidade; i > indice_insercao; i--){
        (*relacao)->pacientes[i] = (*relacao)->pacientes[i-1];
    }
    (*relacao)->pacientes[indice_insercao] = paciente;
    (*relacao)->quantidade += 1;

    return true;
}
    
bool relacao_apagar_paciente(Relacao_De_Pacientes **relacao, int id){
    if(relacao == NULL || *relacao == NULL){
        printf("Relação inválida\n");
        return false;
    }

    int indice = busca_binaria_indice(relacao, id, 0, ((*relacao)->quantidade)-1);
    if (indice == -1){
        printf("Paciente inexistente\n");
        return false;
    }else{
        PACIENTE* paciente_a_remover = (*relacao)->pacientes[indice];
        paciente_free(&paciente_a_remover);

        for (int i = indice; i < ((*relacao)->quantidade)- 1; i++){
            (*relacao)->pacientes[i] = (*relacao)->pacientes[i+1];
        }

        (*relacao)->quantidade -= 1;
        return true;
    }
}