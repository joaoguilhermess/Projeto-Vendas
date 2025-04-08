# Arquivos Referentes ao Módulo de Cadastro de Clientes
## Projeto de Vendas da Matéria Programação 2

### clientes.cpp:
Arquivo CPP com a definição das funções:

### Adicionar Clientes:

	void adicionarCliente(ListaClientes& lista, Cliente& cliente);

#### Observação:
	Função de uso interno, não utilize!

### Limpar Clientes:

	void limparClientes(ListaClientes& lista);

#### Entrada:
	struct ListaClientes que contem todos os clientes
#### Saida:
	Memória usada pela struct ListaClientes limpa

### Ler Clientes:

	ListaClientes lerClientes();

#### Entrada:
	Nada
#### Saida:
	struct ListaClientes que contem todos os clientes

### Salvar Clientes:

	bool salvarClientes(ListaClientes& lista);

#### Entrada:
	struct ListaClientes que contem todos os clientes
#### Saida:
	Booleano indicando Sucesso na Operação

### Pesquisar Cliente:

	bool pesquisarCliente(ListaClientes& lista, Cliente& cliente, int id, const char* cpf);

#### Entrada:
	struct ListaClientes, struct de Cliente na qual o cliente pesquisado vai ser definido caso sucesso, ID do Cliente, CPF do Cliente
#### Saida:
	Booleano indicando Sucesso na Operação

### Cadastar Cliente:

	bool cadastrarCliente(ListaClientes& lista, Cliente& cliente, const char* nome, const char* cpf);

#### Entrada:
	struct ListaClientes, struct de Cliente na qual o cliente cadastrado vai ser definido caso sucesso, NOME do Cliente, CPF do Cliente
#### Saida:
	Booleano indicando Sucesso na Operação

### Excluir Cliente:

	bool excluirCliente(ListaClientes& lista, Cliente& cliente)

#### Entrada:
	struct ListaClientes, Respectivo struct Cliente a ser deletado;
#### Saida:
	Booleano indicando Sucesso na Operação

### clientes.h: 
Arquivo Header com a definição das respectivas constantes, funções e bibliotecas.

### clientes.txt:
Referente Aos Clientes Salvos.

#### struct Clientes:
	struct Cliente {
		int id;
		char nome[TAMANHO_NOME];
		char cpf[TAMANHO_CPF];
	};

#### struct ListaClientes:
	struct ListaClientes {
		int tamanho;
		int quantidade;
		Cliente* clientes;
	};

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