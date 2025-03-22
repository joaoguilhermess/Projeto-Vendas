#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

#define ARQUIVO_CLIENTES "clientes.txt"
#define TAMANHO_NOME 64 + 1
#define TAMANHO_CPF 11 + 1

bool verificarCliente(const char* cpf) {
	std::ifstream clientes(ARQUIVO_CLIENTES, std::ios::in);

	if (!clientes) return false;

	std::string _cpf;
	std::string _nome;

	bool existe = false;

	while (true) {
		if (!getline(clientes, _cpf)) break;
		if (!getline(clientes, _nome)) break;

		if (_cpf == cpf) {
			existe = true;
			break;
		}
	}

	clientes.close();

	return existe;
}

bool cadastrarCliente(const char* nome, const char* cpf) {
	if (verificarCliente(cpf)) return false;

	std::ofstream clientes(ARQUIVO_CLIENTES, std::ios::out | std::ios::app);

	if (!clientes) return false;

	clientes << "\n";
	clientes << cpf;
	clientes << "\n";
	clientes << nome;

	clientes.close();

	return true;
}

void testarVerificação() {
	char cpf[TAMANHO_CPF] = "001";

	std::cout << "Verificar Cliente: "<< cpf << " Resultado: " << (verificarCliente(cpf) ? "Existe" : "Não Existe");
	std::cout << "\n";
}

void testarCadastro() {
	char nome[TAMANHO_NOME] = "Nomedegente Sobrenomedeanimal";
	char cpf[TAMANHO_CPF] = "12345678901";

	std::cout << "Cadastrar Cliente: " << nome << " CPF: " << cpf << " Resultado: " << (cadastrarCliente(nome, cpf) ? "Sucesso" : "Falha");
	std::cout << "\n";
}

int main() {
	SetConsoleOutputCP(65001);

	testarVerificação();

	testarCadastro();

	return 0;
}