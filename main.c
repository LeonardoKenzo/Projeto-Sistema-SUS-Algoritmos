#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

int main(void){
    int id;
    char *nome;

    nome = (char *)calloc(100, sizeof(char));
    scanf(" %[^\n] %d", nome, &id); //Debug: precisa melhorar o scanf

    PACIENTE *pacienteTeste = Paciente_Criar(id, nome);
    
    printf("Nome: %s\nID: %d\n", Paciente_GetNome(pacienteTeste), Paciente_GetID(pacienteTeste));

    Paciente_Free(&pacienteTeste);

    return 0;
}