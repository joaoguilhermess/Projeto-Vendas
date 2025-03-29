# Arquivos Referentes ao Módulo de Cadastro de Clientes
## Projeto de Vendas da Matéria Programação 2

### clientes.cpp:
Arquivo CPP com a definição das funções:

### Ler Clientes:

	std::vector<Cliente> lerClientes();

#### Entrada:
	Nada
#### Saida:
	Vetor da struct Cliente

### Salvar Clientes:

	bool salvarClientes(std::vector<Cliente>& clientes);

#### Entrada:
	Vetor da struct Cliente
#### Saida:
	Booleano indicando Sucesso na Operação

### Pesquisar Cliente:

	bool pesquisarCliente(std::vector<Cliente>& clientes, Cliente& cliente, int id, const char* cpf);

#### Entrada:
	Vetor da struct Cliente, struct de Cliente na qual o cliente pesquisado vai ser definido caso sucesso, ID do Cliente, CPF do Cliente
#### Saida:
	Booleano indicando Sucesso na Operação

### Cadastar Cliente:

	bool cadastrarCliente(std::vector<Cliente>& clientes, Cliente& cliente, const char* nome, const char* cpf);

#### Entrada:
	Vetor da struct Cliente, struct de Cliente na qual o cliente cadastrado vai ser definido caso sucesso, NOME do Cliente, CPF do Cliente
#### Saida:
	Booleano indicando Sucesso na Operação

### Excluir Cliente:

	bool excluirCliente(std::vector<Cliente>& clientes, int id);

#### Entrada:
	Vetor da struct Cliente, ID do respectivo cliente a ser deletado;
#### Saida:
	Booleano indicando Sucesso na Operação

### clientes.h: 
Arquivo Header com a definição das respectivas constantes, funções e bibliotecas.

### clientes.txt:
Referente Aos Clientes Salvos.

#### Estrutura:

	ID do Cliente
	NOME do Cliente
	CPF do Cliente
	ID do Cliente
	NOME do Cliente
	CPF do Cliente
	ID do Cliente
	NOME do Cliente
	CPF do Cliente	
	...