# Projeto 1 – Pronto Socorro SUS
## 📌 Introdução

O projeto consiste em simular um sistema de atendimento médico de emergência, seguindo a ordem de chegada dos pacientes e registrando seu histórico de procedimentos. Utiliza Tipos Abstratos de Dados (TADs) como filas, listas e pilhas para gerenciar pacientes, fila de espera e persistência de dados para armazenar o histórico médico.

## 🎯 Objetivo

**Implementar um sistema que:**

- Cadastre pacientes (com ID único e nome).
- Gerencie a fila de espera sem prioridade, apenas por ordem de chegada.
- Mantenha o histórico médico do paciente com possibilidade de desfazer o último procedimento.
- Persista os dados em disco, carregando-os ao iniciar o sistema e salvando-os ao encerrar.

## 🧍 Estrutura do Paciente

|**Campo**|**Descrição**                                    |
|---------|-------------------------------------------------|
|Id       |Identificador único do paciente                  |
|Nome     |Nome completo do paciente                        |
|Histórico|Até 10 procedimentos, texto ≤ 100 caracteres cada|

## 💾 Persistência dos Dados

- **Ao iniciar** → Carregar lista de pacientes, fila de espera e históricos salvos.
- **Ao encerrar** → Salvar todos os dados em disco.
  
Implementado com:
- Um TAD de I/O centralizado

## 💻 Interface do Sistema

**Menu do Sistema:**
1. Registrar paciente
2. Dar alta ao paciente
3. Adicionar procedimento ao histórico
4. Desfazer procedimento do histórico
5. Chamar paciente para atendimento
6. Mostrar fila de espera
7. Mostrar histórico do paciente
8. Sair

## 👨‍🎓 Alunos Responsáveis
Leonardo Kenzo Tanaka [Github: [LeonardoKenzo](https://github.com/LeonardoKenzo)]

Pedro Teidi de Sa Yamacita [Github: [pedroYamacita](https://github.com/pedroYamacita)]

Gustavo de Faria Fernandes [Github: [Gustavo-Fernandes04](https://github.com/Gustavo-Fernandes04)]
