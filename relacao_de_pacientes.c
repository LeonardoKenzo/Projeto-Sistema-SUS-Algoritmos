#include <stdio.h>
#include <stdlib.h>
#include "relacao_de_pacientes.h"

#define CAPACIDADE_INICIAL 10

struct relacao_de_pacientes_{
    PACIENTE **pacientes;
    int quantidade;
    int capacidade;
};

int BuscaBinaria_Indice(Relacao_De_Pacientes **relacao, int id, int inicio, int fim){
    if (inicio > fim){
        return -1;
    }

    int meio = inicio + (fim - inicio) / 2;
    int id_meio = Paciente_GetID((*relacao)->pacientes[meio]);

    if (id_meio == id){
        return meio;
    }
    else if (id_meio > id){
        return BuscaBinaria_Indice(relacao, id, inicio, meio-1);
    }
    else if (id_meio < id){
        return BuscaBinaria_Indice(relacao, id, meio+1, fim);
    }
}

int BuscaBinaria_Insercao(Relacao_De_Pacientes **relacao, int id){
    int inicio = 0;
    int fim = ((*relacao)->quantidade)-1;

    while (inicio <= fim){
        int meio = inicio + (fim - inicio)/2;
        int id_meio = Paciente_GetID((*relacao)->pacientes[meio]);

        if (id_meio < id){
            inicio = meio + 1;
        }else{
            fim = meio - 1;
        }
    }
    return inicio;
}

Relacao_De_Pacientes *Relacao_Criar(){
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

void Relacao_Free(Relacao_De_Pacientes **relacao){
    if (relacao == NULL || *relacao == NULL){
        return;
    }else{
        for (int i = 0; i < (*relacao)->quantidade; i++){
            Paciente_Free(&((*relacao)->pacientes[i]));
        }
        free((*relacao)->pacientes);
        (*relacao)->capacidade = 0;
        (*relacao)->quantidade = 0;
        free(*relacao);
        *relacao = NULL;
        return;
    }
}

bool Relacao_EstaVazia(Relacao_De_Pacientes **relacao){
    if (relacao == NULL || *relacao == NULL){
        return true;
    }else{
        return (*relacao)->quantidade == 0;
    }
}

void Relacao_Listar_Pacientes(Relacao_De_Pacientes **relacao){
    if (relacao == NULL || *relacao == NULL || Relacao_EstaVazia(relacao)){
        printf("Relação Vazia ou inexistente\n");
        return;
    }else{
        printf("%-10s | %-30s\n", "ID", "NOME");

        for (int i = 0; i < (*relacao)->quantidade; i++){        
            PACIENTE *p = (*relacao)->pacientes[i];
            int id = Paciente_GetID(p);
            char *nome = Paciente_GetNome(p);

            printf("%-10d | %-30s\n", id, nome);
        }
    }
    printf("Total de pacientes: %d\n\n", (*relacao)->quantidade);
    return;
}

PACIENTE *Registro_Busca(Relacao_De_Pacientes **relacao, int id){
    if (relacao == NULL || *relacao == NULL || Relacao_EstaVazia(relacao)){
        printf("Relação Vazia ou inválida\n");
        return NULL;
    }else{
        int aux = BuscaBinaria_Indice(relacao, id, 0, ((*relacao)->quantidade)-1);
        if (aux == -1){
            return NULL;
        }else{
            return (*relacao)->pacientes[aux];
        }
    }
}

bool Relacao_InserirPaciente(Relacao_De_Pacientes **relacao, PACIENTE *paciente){
    if (relacao == NULL || *relacao == NULL){
        printf("Relação inválida\n");
        return NULL;
    }

    int id_atual = Paciente_GetID(paciente);

    if (Registro_Busca(relacao, id_atual) != NULL){
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

    int indice_insercao = BuscaBinaria_Insercao(relacao, id_atual);
    for (int i = (*relacao)->quantidade; i > indice_insercao; i--){
        (*relacao)->pacientes[i] = (*relacao)->pacientes[i-1];
    }
    (*relacao)->pacientes[indice_insercao] = paciente;
    (*relacao)->quantidade += 1;

    return true;
}
    
bool Relacao_ApagarPaciente(Relacao_De_Pacientes **relacao, int id){
    if(relacao == NULL || *relacao == NULL){
        printf("Relação inválida\n");
        return false;
    }

    int indice = BuscaBinaria_Indice(relacao, id, 0, ((*relacao)->quantidade)-1);
    if (indice == -1){
        printf("Paciente inexistente\n");
        return false;
    }else{
        PACIENTE* paciente_a_remover = (*relacao)->pacientes[indice];
        Paciente_Free(&paciente_a_remover);

        for (int i = indice; i < ((*relacao)->quantidade)- 1; i++){
            (*relacao)->pacientes[i] = (*relacao)->pacientes[i+1];
        }

        (*relacao)->quantidade -= 1;
        return true;
    }
}