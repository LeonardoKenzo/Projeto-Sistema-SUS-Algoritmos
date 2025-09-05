#ifndef RELACAO_DE_PACIENTES_H
    #define RELACAO_DE_PACIENTES_H
    #include <stdbool.h>
    #include "paciente.h"
    #include "historico.h"

    typedef struct relacao_de_pacientes_ Relacao_De_Pacientes;

    Relacao_De_Pacientes *Relacao_Criar();
    void Relacao_Free(Relacao_De_Pacientes **relacao);
    void Relacao_Listar_Pacientes(Relacao_De_Pacientes **relacao);
    bool Relacao_EstaVazia(Relacao_De_Pacientes **relacao);
    PACIENTE *Registro_Busca(Relacao_De_Pacientes **relacao, int id);
    bool Relacao_ApagarPaciente(Relacao_De_Pacientes **relacao, int id);
    bool Relacao_InserirPaciente(Relacao_De_Pacientes **relacao, PACIENTE *paciente);

#endif