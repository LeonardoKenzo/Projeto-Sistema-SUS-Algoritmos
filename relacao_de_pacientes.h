#ifndef RELACAO_DE_PACIENTES_H
    #define RELACAO_DE_PACIENTES_H
    #include <stdbool.h>
    #include "paciente.h"
    #include "historico.h"

    typedef struct relacao_de_pacientes_ Relacao_De_Pacientes;

    Relacao_De_Pacientes *relacao_criar();
    void relacao_free(Relacao_De_Pacientes **relacao);
    void relacao_listar_pacientes(Relacao_De_Pacientes **relacao);
    bool relacao_esta_vazia(Relacao_De_Pacientes **relacao);
    PACIENTE *registro_busca(Relacao_De_Pacientes **relacao, int id);
    bool relacao_apagar_paciente(Relacao_De_Pacientes **relacao, int id);
    bool relacao_inserir_paciente(Relacao_De_Pacientes **relacao, PACIENTE *paciente);

#endif