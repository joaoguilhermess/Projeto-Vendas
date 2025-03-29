#ifndef HEADER_CLIENTES
#define HEADER_CLIENTES

#include <windows.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

#define ARQUIVO_CLIENTES "clientes.txt"
#define TAMANHO_NOME 64 + 1
#define TAMANHO_CPF 14 + 1

struct Cliente {
	int id;
	char nome[TAMANHO_NOME];
	char cpf[TAMANHO_CPF];
};

std::vector<Cliente> lerClientes();

bool salvarClientes(std::vector<Cliente>& clientes);

bool pesquisarCliente(std::vector<Cliente>& clientes, Cliente& cliente, int id, const char* cpf);

bool cadastrarCliente(std::vector<Cliente>& clientes, Cliente& cliente, const char* nome, const char* cpf);

bool excluirCliente(std::vector<Cliente>& clientes, int id);

#endif