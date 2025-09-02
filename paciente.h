#ifndef PACIENTE_H
    #define PACIENTE_H
    #include "historico.h"
    
    typedef struct paciente_ PACIENTE;
    PACIENTE *Paciente_Criar(int id, char *nome);
    HISTORICO *Paciente_GetHistorico(PACIENTE *paciente);
    void Paciente_Free(PACIENTE **paciente); //Essa funcao da free tambem no historico relacionado a ele
    int Paciente_GetID(PACIENTE *paciente);
    char *Paciente_GetNome(PACIENTE *paciente);

#endif