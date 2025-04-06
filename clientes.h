#ifndef HEADER_CLIENTES
#define HEADER_CLIENTES

#include <windows.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#define ARQUIVO_CLIENTES "clientes.txt"
#define TAMANHO_NOME 64 + 1
#define TAMANHO_CPF 14 + 1
#define PARTE_CLIENTES 64

struct Cliente {
	int id;
	char nome[TAMANHO_NOME];
	char cpf[TAMANHO_CPF];
};

struct ListaClientes {
	int tamanho;
	int quantidade;
	Cliente* clientes;
};

// ListaClientes lerClientes();

// bool salvarClientes(Cliente* clientes);

// bool pesquisarCliente(Cliente* clientes, Cliente& cliente, int id, const char* cpf);

// bool cadastrarCliente(Clientes clientes, Cliente& cliente, const char* nome, const char* cpf);

// bool excluirCliente(Cliente* clientes, int id);

#endif