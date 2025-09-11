#ifndef HISTORICO_H
    #define HISTORICO_H
    #include <stdbool.h>

    typedef struct historico_ HISTORICO;
    HISTORICO *historico_criar();
    bool historico_remover_procedimento(HISTORICO *historico);
    bool historico_inserir_procedimento(HISTORICO *historico, char *procedimento);
    void historico_printar(HISTORICO *historico);
    void historico_free(HISTORICO **historico);

#endif