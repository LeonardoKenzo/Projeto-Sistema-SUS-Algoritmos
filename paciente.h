#ifndef PACIENTE_H
    #define PACIENTE_H
    #include "historico.h"
    
    typedef struct paciente_ PACIENTE;
    PACIENTE *Paciente_Criar(int id, char *nome);
    void Paciente_Free(PACIENTE **paciente);


    //Teste --------------------------------------
    int Paciente_GetID(PACIENTE *paciente);
    char *Paciente_GetNome(PACIENTE *paciente);

#endif