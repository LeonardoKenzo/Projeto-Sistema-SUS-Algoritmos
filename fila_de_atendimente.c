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
    FILA_DE_ATENDIMENTO* proximo;
};

FILA_DE_ATENDIMENTO *Fila_Criar(int capacidade){
    FILA_DE_ATENDIMENTO *fila = (FILA_DE_ATENDIMENTO *)malloc(sizeof(FILA_DE_ATENDIMENTO));
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

bool fila_vazia(FILA_DE_ATENDIMENTO *fila) {
    if (fila == NULL) {
        return true;
    }
    return fila->inicio == fila->fim;
}

bool fila_cheia(FILA_DE_ATENDIMENTO *fila) {
    if (fila == NULL) {
        return false;
    }
    return (fila->fim + 1) % fila->capacidade == fila->inicio;
}

bool fila_inserir(FILA_DE_ATENDIMENTO *fila, PACIENTE *paciente) {
    if ((fila == NULL && !fila_cheia(fila)) || paciente == NULL) {
        return false;
    }

    fila->pacientes[fila->fim] = paciente;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->proximo = fila->pacientes[fila->fim];
    return true;
}

PACIENTE *fila_remover(FILA_DE_ATENDIMENTO *fila) {
    if (fila == NULL && !Fila_Vazia(fila)) {
        return NULL;
    }
    PACIENTE *pacienteRemovido = fila->pacientes[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    return pacienteRemovido;
}

void fila_liberar(FILA_DE_ATENDIMENTO **fila) {
    if (fila == NULL || *fila == NULL) {
        return;
    }
    free((*fila)->pacientes);
    free(*fila);
    *fila = NULL;
}
