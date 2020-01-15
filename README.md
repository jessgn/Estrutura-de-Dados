# Estrutura-de-Dados

TRABALHO PRÁTICO II
  1. Aplicação de Pilha: O problema do labirinto (2.0 pontos)
  
  O objetivo deste exercício é usar uma pilha para implementar uma técnica conhecida como backtracking (ou retrocesso), frequentemente usada em Inteligência Artificial para resolver problemas por meio de tentativa e erro. Essa técnica é útil em situações em que, a cada instante, temos várias opções possíveis e não sabemos avaliar o melhor. Então, escolhemos uma delas e, caso essa escolha não leve à solução do problema, retrocedemos e fazemos uma nova escolha.
Para ilustrar o uso dessa técnica, aplicaremos o problema do rato em um labirinto. O rato está preso no labirinto e precisa achar o caminho que o leve a à saída.


2. Aplicação de Fila: cadastro de pacientes que necessitam de doação de coração (3.0 pontos)

  Um hospital de cardiologia precisa de um sistema para efetuar o cadastro de pacientes que necessitam de doação de coração. Para cada paciente que é incluído no sistema deve ser informado o nome, telefone e o grau de urgência para transplante. O grau de urgência é definido na seguinte escala: (5) Muito urgente; (4) Urgente; (3) Médio; (2) Pouco urgente; (1) Sem urgência.
Sempre que o hospital recebe um novo coração o sistema é consultado para obter o próximo paciente que deverá ser operado. O sistema informa o nome e o telefone do paciente. Também a qualquer momento é possível visualizar o tamanho da fila de espera. Observação: os
dados não precisam ser persistidos em arquivos, podem ficar armazenados somente na memória. 
O sistema deve ter o seguinte menu:
1. Cadastrar paciente (Nome, telefone e grau de urgência);
2. Buscar paciente (informar a posição do paciente na fila e o seu grau de urgência);
3. Próximo paciente a ser operado (retorna os dados do paciente e exclui da lista*);
4. Verificar tamanho da fila;
5. Sair.
* Ao excluir da lista o paciente que receberá a próxima doação de coração, seus dados devem ser gravados em um arquivo txt. Este arquivo armazenará os dados de todos os pacientes já transplantados.


