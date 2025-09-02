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
    Fila_De_Atendimento* proximo;
};

Fila_De_Atendimento *Fila_Criar(int capacidade){
    Fila_De_Atendimento *fila = (Fila_De_Atendimento *)malloc(sizeof(Fila_De_Atendimento));
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

bool Fila_Vazia(Fila_De_Atendimento *fila) {
    if (fila == NULL) {
        return true;
    }
    return fila->inicio == fila->fim;
}

bool Fila_Cheia(Fila_De_Atendimento *fila) {
    if (fila == NULL) {
        return false;
    }
    return (fila->fim + 1) % fila->capacidade == fila->inicio;
}

bool Fila_Inserir(Fila_De_Atendimento *fila, PACIENTE *paciente) {
    if ((fila == NULL && !Fila_Cheia(fila)) || paciente == NULL) {
        return false;
    }

    fila->pacientes[fila->fim] = paciente;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->proximo = fila->pacientes[fila->fim];
    return true;
}

PACIENTE *Fila_Remover(Fila_De_Atendimento *fila) {
    if (fila == NULL && !Fila_Vazia(fila)) {
        return NULL;
    }
    PACIENTE *pacienteRemovido = fila->pacientes[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    return pacienteRemovido;
}

void Fila_Liberar(Fila_De_Atendimento **fila) {
    if (fila == NULL || *fila == NULL) {
        return;
    }
    free((*fila)->pacientes);
    free(*fila);
    *fila = NULL;
}
