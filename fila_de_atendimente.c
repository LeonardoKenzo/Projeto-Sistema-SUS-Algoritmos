#include "fila_de_atendimente.h"
#include "paciente.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct no_fila_
{
    PACIENTE *paciente;
    NO_FILA *proximo;
};


struct fila_de_atendimento_
{
    NO_FILA *inicio;
    NO_FILA *fim;
};

Fila_De_Atendimento *Fila_Criar(int capacidade){
    Fila_De_Atendimento *fila = (Fila_De_Atendimento *)malloc(sizeof(Fila_De_Atendimento));
    if (fila == NULL) {
        return NULL;
    }

    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

bool Fila_Vazia(Fila_De_Atendimento *fila) {
    if (fila == NULL) {
        return true;
    }
    return fila->inicio == NULL;
}

bool Fila_Cheia(Fila_De_Atendimento *fila) {
    //só é verdadeiro se faltar memória
    return false;
    }

bool Fila_Inserir(Fila_De_Atendimento *fila, PACIENTE *paciente) {
    if ((fila == NULL && !Fila_Cheia(fila)) || paciente == NULL) {
        return false;
    }
    NO_FILA *novo = (NO_FILA *)malloc(sizeof(NO_FILA));
    //verifica se memória foi alocada corretamente
    if(novo == NULL){
        return false;
    }

    novo->paciente = paciente;
    novo->proximo = NULL;
    //fila esta vazia, ngm aponta pra ele
    if(fila->inicio == NULL){
        fila->inicio = novo;
    } 
    //fila ja tem pelo menos um nó anterior q vai apontar para o novo
    else{
        fila->fim->proximo = novo;
    }
    fila->fim = novo;
    return true;
}

PACIENTE *Fila_Remover(Fila_De_Atendimento *fila) {
    if(fila == NULL || fila->inicio == NULL){
        return NULL;
    }
    NO_FILA *remover = fila->inicio;
    PACIENTE *pacienteRemovido = remover->paciente;
    
    fila->inicio = remover->proximo;
    ///se nao houver mais elementos, tanto inicio quanto fim apontam para NULL indicando fila vazia
    if(fila->inicio == NULL){
        fila->fim = NULL;
    }
    free(remover);
    return pacienteRemovido;
}
void Fila_Liberar(Fila_De_Atendimento **fila) {
    if (fila == NULL || *fila == NULL) {
        return;
    }
    NO_FILA *atual = (*fila)->inicio;
    while (atual != NULL){
        NO_FILA *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(*fila);
    *fila=NULL;
}
