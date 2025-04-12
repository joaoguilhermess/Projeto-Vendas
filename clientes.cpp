#include "clientes.h"

ListaClientes lerClientes() {
	std::ifstream arquivo(ARQUIVO_CLIENTES, std::ios::in);

	ListaClientes lista;

	lista.tamanho = PARTE_CLIENTES;
	lista.quantidade = 0;
	lista.clientes = new Cliente[lista.tamanho];

	if (!arquivo) return lista;

	std::string idTemp;
	std::string nomeTemp;
	std::string cpfTemp;

	while (true) {
		if (!std::getline(arquivo, idTemp)) break;
		if (!std::getline(arquivo, nomeTemp)) break;
		if (!std::getline(arquivo, cpfTemp)) break;

		if (std::stoi(idTemp) <= 0 && cpfTemp.length() != TAMANHO_CPF - 1 && nomeTemp.length() == 0) continue;

		Cliente cliente;

		cliente.id = std::stoi(idTemp);

		std::fill(std::begin(cliente.nome), std::end(cliente.nome), '\0');
		std::copy(nomeTemp.begin(), nomeTemp.end(), cliente.nome);

		std::fill(std::begin(cliente.cpf), std::end(cliente.cpf), '\0');
		std::copy(cpfTemp.begin(), cpfTemp.end(), cliente.cpf);

		adicionarCliente(lista, cliente);
	}

	arquivo.close();

	return lista;
}

bool cadastrarCliente(ListaClientes& lista, Cliente& cliente, const char* nome, const char* cpf) {
	if (std::strlen(nome) == 0 || std::strlen(nome) > TAMANHO_NOME - 1) return false;
	if (std::strlen(cpf) != TAMANHO_CPF - 1) return false;
	if (pesquisarCliente(lista, cliente, 0, cpf)) return false;

	if (lista.quantidade > 0) cliente.id = lista.clientes[lista.quantidade - 1].id + 1;
	else cliente.id = 1;

	std::fill(std::begin(cliente.nome), std::end(cliente.nome), '\0');
	std::copy(nome, nome + std::strlen(nome), cliente.nome);

	std::fill(std::begin(cliente.cpf), std::end(cliente.cpf), '\0');
	std::copy(cpf, cpf + strlen(cpf), cliente.cpf);

	adicionarCliente(lista, cliente);

	return salvarClientes(lista);
}

bool pesquisarCliente(ListaClientes& lista, Cliente& cliente, int id, const char* cpf) {
	for (int i = 0; i < lista.quantidade; i++) {
		if (lista.clientes[i].id == id || (std::strlen(lista.clientes[i].cpf) == std::strlen(cpf) && std::equal(std::begin(lista.clientes[i].cpf), std::end(lista.clientes[i].cpf), cpf))) {
			cliente = lista.clientes[i];

			return true;
		}
	}

	return false;
}

bool excluirCliente(ListaClientes& lista, Cliente& cliente) {
	for (int i = 0; i < lista.quantidade; i++) {
		if (lista.clientes[i].id == cliente.id) {
			for (int i2 = i; i2 < lista.quantidade - 1; i2++) {
				lista.clientes[i2] = lista.clientes[i2 + 1];
			}

			lista.quantidade -= 1;

			return salvarClientes(lista);
		}
	}

	return false;
}

void adicionarCliente(ListaClientes& lista, Cliente& cliente) {
	if (lista.tamanho == lista.quantidade) {
		int tamanho = lista.tamanho + PARTE_CLIENTES;

		Cliente* novosClientes = new Cliente[tamanho];

		for (int i = 0; i < lista.quantidade; i++) novosClientes[i] = lista.clientes[i];

		delete[] lista.clientes;
		
		lista.tamanho = tamanho;
		lista.clientes = novosClientes;
	}

	lista.clientes[lista.quantidade++] = cliente;
}

bool salvarClientes(ListaClientes& lista) {
	std::ofstream arquivo(ARQUIVO_CLIENTES, std::ios::out | std::ios::trunc);

	if (!arquivo) return false;

	for (int i = 0; i < lista.quantidade; i++) {
		arquivo << lista.clientes[i].id;
		arquivo << "\n";
		arquivo << lista.clientes[i].nome;
		arquivo << "\n";
		arquivo << lista.clientes[i].cpf;
		arquivo << "\n";
	}

	arquivo.close();

	return true;
}

void limparClientes(ListaClientes& lista) {
	delete[] lista.clientes;

	lista.clientes = nullptr;
}