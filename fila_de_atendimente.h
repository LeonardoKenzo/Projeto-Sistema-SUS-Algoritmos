#ifndef FILA_DE_ATENDIMENTO_H
    #define FILA_DE_ATENDIMENTO_H
    #include "paciente.h"

    typedef struct fila_de_atendimento_ FILA_DE_ATENDIMENTO;

    FILA_DE_ATENDIMENTO *fila_criar(int capacidade);
    bool fila_inserir(FILA_DE_ATENDIMENTO *fila, PACIENTE *paciente);
    PACIENTE *fila_remover(FILA_DE_ATENDIMENTO *fila);
    void fila_liberar(FILA_DE_ATENDIMENTO **fila);
    bool fila_cheia(FILA_DE_ATENDIMENTO *fila);
    bool fila_vazia(FILA_DE_ATENDIMENTO *fila);

#endif