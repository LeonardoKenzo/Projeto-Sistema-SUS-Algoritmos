#include "fila_de_atendimente.h"
#include "paciente.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct fila_de_atendimento_
{
    PACIENTE **pacientes;
    int capacidade;
    int inicio;
    int fim;
    fila_de_atendimento* proximo;
};

fila_de_atendimento *Fila_Criar(int capacidade){
    fila_de_atendimento *fila = (fila_de_atendimento *)malloc(sizeof(fila_de_atendimento));
    if (fila == NULL) {
        return NULL;
    }
    fila->pacientes = (PACIENTE **)malloc(capacidade * sizeof(PACIENTE *));
    if (fila->pacientes == NULL) {
        free(fila);
        return NULL;
    }
    fila->capacidade = capacidade;
    fila->inicio = 0;
    fila->fim = 0;
    fila->proximo = NULL;
    return fila;
}

bool fila_vazia(fila_de_atendimento *fila) {
    if (fila == NULL) {
        return true;
    }
    return fila->inicio == fila->fim;
}

bool fila_cheia(fila_de_atendimento *fila) {
    if (fila == NULL) {
        return false;
    }
    return (fila->fim + 1) % fila->capacidade == fila->inicio;
}

bool fila_inserir(fila_de_atendimento *fila, PACIENTE *paciente) {
    if ((fila == NULL && !fila_cheia(fila)) || paciente == NULL) {
        return false;
    }

    fila->pacientes[fila->fim] = paciente;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->proximo = fila->pacientes[fila->fim];
    return true;
}

PACIENTE *fila_remover(fila_de_atendimento *fila) {
    if (fila == NULL && !Fila_Vazia(fila)) {
        return NULL;
    }
    PACIENTE *pacienteRemovido = fila->pacientes[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    return pacienteRemovido;
}

void fila_liberar(fila_de_atendimento **fila) {
    if (fila == NULL || *fila == NULL) {
        return;
    }
    free((*fila)->pacientes);
    free(*fila);
    *fila = NULL;
}
