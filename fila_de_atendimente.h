#ifndef FILA_DE_ATENDIMENTO_H
    #define FILA_DE_ATENDIMENTO_H
    #include "paciente.h"

    typedef struct fila_de_atendimento_ fila_de_atendimento;

    fila_de_atendimento *fila_criar(int capacidade);
    bool fila_inserir(fila_de_atendimento *fila, PACIENTE *paciente);
    PACIENTE *fila_remover(fila_de_atendimento *fila);
    void fila_liberar(fila_de_atendimento **fila);
    bool fila_cheia(fila_de_atendimento *fila);
    bool fila_vazia(fila_de_atendimento *fila);

#endif