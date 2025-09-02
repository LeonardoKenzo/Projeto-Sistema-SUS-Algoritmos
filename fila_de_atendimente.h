#ifndef FILA_DE_ATENDIMENTO_H
    #define FILA_DE_ATENDIMENTO_H
    #include "paciente.h"

    typedef struct no_fila_ NO_FILA;
    typedef struct fila_de_atendimento_ Fila_De_Atendimento;

    Fila_De_Atendimento *Fila_Criar(int capacidade);
    bool Fila_Inserir(Fila_De_Atendimento *fila, PACIENTE *paciente);
    PACIENTE *Fila_Remover(Fila_De_Atendimento *fila);
    void Fila_Liberar(Fila_De_Atendimento **fila);
    bool Fila_Cheia(Fila_De_Atendimento *fila);
    bool Fila_Vazia(Fila_De_Atendimento *fila);

#endif