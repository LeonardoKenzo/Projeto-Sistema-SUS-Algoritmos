#ifndef HISTORICO_H
    #define HISTORICO_H
    #include <stdbool.h>

    typedef struct historico_ HISTORICO;
    HISTORICO *historico_criar();
    void historico_free(HISTORICO **historico);
    void historico_printar(HISTORICO *historico);
    bool historico_esta_cheio(HISTORICO *historico);
    bool historico_esta_vazio(HISTORICO *historico);
    bool historico_remover_procedimento(HISTORICO *historico);
    bool historico_inserir_procedimento(HISTORICO *historico, char *procedimento);

#endif