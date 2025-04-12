#include "clientes.h"

#include <locale.h>
#include <conio.h>

void testarPesquisa(ListaClientes& lista) {
	int id1 = 1;
	const char* cpf1 = "";

	Cliente cliente;

	std::cout << "Pesquisando Cliente com ID (ID Válido): " << id1;
	std::cout << "\n";
	std::cout << "\n";

	if (pesquisarCliente(lista, cliente, id1, cpf1)) {
		std::cout << "Cliente Encontrado!";
		std::cout << "\n";
		std::cout << "\n";

		std::cout << "ID: " << cliente.id;
		std::cout << "\n";
		std::cout << "NOME: " << cliente.nome;
		std::cout << "\n";
		std::cout << "CPF: " << cliente.cpf;
		std::cout << "\n";
	} else {
		std::cout << "Cliente Não Encontrado!";
		std::cout << "\n";
	}

	std::cout << "\n";

	int id2 = 0;
	const char* cpf2 = "000.000.000-00";

	std::cout << "Pesquisando Cliente com CPF (CPF Inválido): " << cpf2;
	std::cout << "\n";
	std::cout << "\n";

	if (pesquisarCliente(lista, cliente, id2, cpf2)) {
		std::cout << "Cliente Encontrado!";
		std::cout << "\n";
		std::cout << "\n";
		
		std::cout << "ID: " << cliente.id;
		std::cout << "\n";
		std::cout << "NOME: " << cliente.nome;
		std::cout << "\n";
		std::cout << "CPF: " << cliente.cpf;
		std::cout << "\n";
	} else {
		std::cout << "Cliente Não Encontrado!";
		std::cout << "\n";
	}

	std::cout << "\n";
}

void testarCadastro(ListaClientes& lista, Cliente& cliente) {
	const char* nome = "Nomedegente Sobrenomedeanimal";
	const char* cpf = "123.456.789-01";

	std::cout << "Cadastrando Cliente:";
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "NOME: " << nome;
	std::cout << "\n";
	std::cout << "CPF: " << cpf;
	std::cout << "\n";

	std::cout << "\n";

	if (cadastrarCliente(lista, cliente, nome, cpf)) {
		std::cout << "Sucesso No Cadastro!";
		std::cout << "\n";
	} else {
		std::cout << "Falha No Cadastro!";
		std::cout << "\n";
	}

	std::cout << "\n";

	std::cout << "Tentando Cadastrar O Mesmo Cliente (Falha Iminente):";
	std::cout << "\n";
	std::cout << "\n";

	if (cadastrarCliente(lista, cliente, nome, cpf)) {
		std::cout << "Sucesso No Cadastro!";
		std::cout << "\n";
	} else {
		std::cout << "Falha No Cadastro!";
		std::cout << "\n";
	}

	std::cout << "\n";
}

void testarExcluir(ListaClientes& lista, Cliente& cliente) {
	std::cout << "Excluindo O Mesmo Cliente:";
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "ID: " << cliente.id;
	std::cout << "\n";
	std::cout << "NOME: " << cliente.nome;
	std::cout << "\n";
	std::cout << "CPF: " << cliente.cpf;
	std::cout << "\n";
	std::cout << "\n";

	if (excluirCliente(lista, cliente)) {
		std::cout << "Sucesso Na Exclusão!";
		std::cout << "\n";
	} else {
		std::cout << "Falha Na Exclusão!";
		std::cout << "\n";
	}
	
	std::cout << "\n";
}

int main() {
	SetConsoleOutputCP(65001);
	
	setlocale(LC_ALL, "portuguese");

	std::cout << "Lendo Arquivo de Clientes...";
	std::cout << "\n";
	std::cout << "\n";

	ListaClientes lista = lerClientes();

	std::cout << "Memória Dinamicamente Alocada Para: " << lista.tamanho << " Clientes";
	std::cout << "\n";

	std::cout << "Clientes Lidos: " << lista.quantidade;
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "Mostrando os 3 Primeiros Clientes:";
	std::cout << "\n";
	std::cout << "\n";

	for (int i = 0; i < lista.quantidade; i++) {
		std::cout << "ID: " << lista.clientes[i].id;
		std::cout << "\n";
		std::cout << "NOME: " << lista.clientes[i].nome;
		std::cout << "\n";
		std::cout << "CPF: " << lista.clientes[i].cpf;
		std::cout << "\n";
		std::cout << "\n";

		if (i == 3 - 1) break;
	}

	testarPesquisa(lista);

	Cliente cliente;

	testarCadastro(lista, cliente);

	testarExcluir(lista, cliente);

	std::cout << "Limpando Memória...";
	std::cout << "\n";

	limparClientes(lista);

	std::cout << "\n";
	
	std::cout << "Aperte Qualquer Tecla Para Continuar.";
	std::cout << "\n";

	getch();

	return 0;
}