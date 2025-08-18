#ifndef HISTORICO_H
    #define HISTORICO_H
    #include <stdbool.h>

    typedef struct historico_ HISTORICO;
    HISTORICO *Historico_Criar();
    void Historico_Free(HISTORICO **historico);
    void Historico_Mostrar(HISTORICO *historico);
    bool Historico_EstaCheio(HISTORICO *historico);
    bool Historico_EstaVazio(HISTORICO *historico);
    bool Historico_RemoverProcedimento(HISTORICO *historico);
    bool Historico_InserirProcedimento(HISTORICO *historico, char *procedimento);

#endif