# Projeto 1 – Pronto Socorro SUS
## 📌 Introdução

O projeto consiste em simular um sistema de atendimento médico de emergência, seguindo a ordem de chegada dos pacientes e registrando seu histórico de procedimentos. Utiliza Tipos Abstratos de Dados (TADs) como filas, listas e pilhas para gerenciar pacientes, fila de espera e persistência de dados para armazenar o histórico médico.

## 🎯 Objetivo

**Implementar um sistema que:**

- Cadastre pacientes (com ID único e nome).
- Gerencie a fila de espera sem prioridade, apenas por ordem de chegada.
- Mantenha o histórico médico do paciente com possibilidade de desfazer o último procedimento.
- Registre óbito do paciente.
- Persista os dados em disco, carregando-os ao iniciar o sistema e salvando-os ao encerrar.

## 🧍 Estrutura do Paciente

|**Campo**|**Descrição**                                    |
|---------|-------------------------------------------------|
|Id       |Identificador único do paciente                  |
|Nome     |Nome completo do paciente                        |
|Histórico|Até 10 procedimentos, texto ≤ 100 caracteres cada|

## 💻 Interface do Sistema

**Menu do Sistema:**
1. Registrar paciente
2. Registrar óbito de paciente.
3. Adicionar procedimento ao histórico
4. Desfazer procedimento do histórico
5. Chamar paciente para atendimento
6. Mostrar fila de espera
7. Mostrar histórico do paciente
8. Sair

## 📚 Estruturas de Dados Utilizadas

O sistema foi desenvolvido com TADs (Tipos Abstratos de Dados) específicos para cada funcionalidade principal:

### 🔹 Histórico Médico → Pilha

Implementado como um array fixo de até 10 procedimentos por paciente

- **Justificativa:** a pilha (LIFO) permite desfazer o último procedimento de forma eficiente.

- **Eficiência:** inserção e remoção em O(1).

- **Adequação:** reflete bem a ideia de "desfazer" ações médicas recentes.

### 🔹 Fila de Atendimento → Fila Circular

Estrutura de fila baseada em vetor circular, com controle de início e fim

- **Justificativa:** garante o atendimento em ordem de chegada (FIFO), sem prioridades.

- **Eficiência:** inserções e remoções em O(1).

- **Adequação:** modela diretamente a dinâmica real de espera em pronto socorro.

### 🔹 Relação de Pacientes → Lista Dinâmica Ordenada

Vetor dinâmico redimensionável, mantido ordenado pelo ID do paciente e acessado por busca binária

- **Justificativa:** facilita cadastro, exclusão e consulta de pacientes de forma organizada.

- **Eficiência:**
  - Busca em O(log n) (busca binária).
  - Inserção/remoção em O(n) devido ao deslocamento de elementos. (Inserção Ordenada)

- **Adequação:** adequado para registros persistentes onde consultas rápidas por ID são frequentes.

## 💾 Persistência dos Dados

- **Ao iniciar** → Carregar lista de pacientes, fila de espera e históricos salvos.
- **Ao encerrar** → Salvar todos os dados em disco.
  
Implementado com:
- Um TAD de I/O centralizado que cria e lê arquivos binários para salvar os dados

## 👨‍🎓 Alunos Responsáveis
Leonardo Kenzo Tanaka [Github: [LeonardoKenzo](https://github.com/LeonardoKenzo)]

Pedro Teidi de Sa Yamacita [Github: [pedroYamacita](https://github.com/pedroYamacita)]

Gustavo de Faria Fernandes [Github: [Gustavo-Fernandes04](https://github.com/Gustavo-Fernandes04)]
