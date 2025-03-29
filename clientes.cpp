#include "clientes.h"

std::vector<Cliente> lerClientes() {
	std::ifstream arquivo(ARQUIVO_CLIENTES, std::ios::in);

	std::vector<Cliente> clientes;

	if (!arquivo) return clientes;

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

		clientes.push_back(cliente);
	}

	arquivo.close();

	return clientes;
}

bool salvarClientes(std::vector<Cliente>& clientes) {
	std::ofstream arquivo(ARQUIVO_CLIENTES, std::ios::out | std::ios::trunc);

	if (!arquivo) return false;

	int quantidade = clientes.size();

	for (int i = 0; i < quantidade; i++) {
		arquivo << clientes[i].id;
		arquivo << "\n";
		arquivo << clientes[i].nome;
		arquivo << "\n";
		arquivo << clientes[i].cpf;
		arquivo << "\n";
	}

	arquivo.close();

	return true;
}

bool pesquisarCliente(std::vector<Cliente>& clientes, Cliente& cliente, int id, const char* cpf) {
	int quantidade = clientes.size();

	for (int i = 0; i < quantidade; i++) {
		if (clientes[i].id == id || (std::strlen(clientes[i].cpf) == std::strlen(cpf) && std::equal(std::begin(clientes[i].cpf), std::end(clientes[i].cpf), cpf))) {
			cliente = clientes[i];

			return true;
		}
	}

	return false;
}

bool cadastrarCliente(std::vector<Cliente>& clientes, Cliente& cliente, const char* nome, const char* cpf) {
	if (std::strlen(nome) == 0 || std::strlen(nome) > TAMANHO_NOME - 1) return false;
	if (std::strlen(cpf) != TAMANHO_CPF - 1) return false;
	if (pesquisarCliente(clientes, cliente, 0, cpf)) return false;

	int quantidade = clientes.size();

	if (quantidade > 0) cliente.id = clientes[quantidade - 1].id + 1;
	else cliente.id = 1;

	std::fill(std::begin(cliente.nome), std::end(cliente.nome), '\0');
	std::copy(nome, nome + std::strlen(nome), cliente.nome);

	std::fill(std::begin(cliente.cpf), std::end(cliente.cpf), '\0');
	std::copy(cpf, cpf + strlen(cpf), cliente.cpf);

	clientes.push_back(cliente);

	return salvarClientes(clientes);
}

bool excluirCliente(std::vector<Cliente>& clientes, Cliente& cliente) {
	int quantidade = clientes.size();

	for (int i = 0; i < quantidade; i++) {
		if (clientes[i].id == cliente.id) {
			clientes.erase(clientes.begin() + i);

			return salvarClientes(clientes);
		}
	}

	return false;
}

void testarPesquisa(std::vector<Cliente>& clientes) {
	int id = 0;
	const char* cpf = "998.028.014-83";

	Cliente cliente;

	bool existe = pesquisarCliente(clientes, cliente, id, cpf);

	if (existe) {
		std::cout << "o Cliente Existe";
		std::cout << "\n";
		std::cout << "Id: " << cliente.id;
		std::cout << "\n";
		std::cout << "Nome: " << cliente.nome;
		std::cout << "\n";
		std::cout << "CPF: " << cliente.cpf;
		std::cout << "\n";
	} else {
		std::cout << "o Cliente Não Existe";
		std::cout << "\n";
	}
}

void testarCadastro(std::vector<Cliente>& clientes, Cliente& cliente) {
	const char* nome = "Nomedegente Sobrenomedeanimal";
	const char* cpf = "123.456.789-01";

	bool sucesso = cadastrarCliente(clientes, cliente, nome, cpf);

	std::cout << "Cadastrar Cliente: " << nome << " CPF: " << cpf << " Resultado: " << (sucesso ? "Sucesso" : "Falha");
	std::cout << "\n";
}

void testarExcluir(std::vector<Cliente>& clientes, Cliente& cliente) {
	bool sucesso = excluirCliente(clientes, cliente);

	std::cout << "Excluir Cliente: " << cliente.id << " Resultado: " << (sucesso ? "Sucesso" : "Falha");
	std::cout << "\n";
}

int main() {
	SetConsoleOutputCP(65001);

	std::vector<Cliente> clientes = lerClientes();

	testarPesquisa(clientes);

	Cliente cliente;

	testarCadastro(clientes, cliente);

	testarExcluir(clientes, cliente);

	return 0;
}