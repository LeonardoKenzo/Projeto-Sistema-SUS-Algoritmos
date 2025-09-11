#ifndef PACIENTE_H
    #define PACIENTE_H
    #include "historico.h"
    
    typedef struct paciente_ PACIENTE;
    PACIENTE *paciente_criar(int id, char *nome);
    HISTORICO *paciente_get_historico(PACIENTE *paciente);
    void paciente_free(PACIENTE **paciente); //Essa funcao da free tambem no historico relacionado a ele
    int paciente_get_id(PACIENTE *paciente);
    int paciente_get_obito(PACIENTE *paciente);
    char *paciente_get_nome(PACIENTE *paciente);

#endif