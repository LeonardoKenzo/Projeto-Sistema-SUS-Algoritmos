#ifndef HISTORICO_H
    #define HISTORICO_H

    typedef struct historico_ HISTORICO;
    HISTORICO *Historico_Criar();
    void Historico_Free(HISTORICO **historico);

#endif