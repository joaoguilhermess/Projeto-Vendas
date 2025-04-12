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

ListaClientes lerClientes();

bool cadastrarCliente(ListaClientes& lista, Cliente& cliente, const char* nome, const char* cpf);

bool pesquisarCliente(ListaClientes& lista, Cliente& cliente, int id, const char* cpf);

bool excluirCliente(ListaClientes& lista, Cliente& cliente);

void adicionarCliente(ListaClientes& lista, Cliente& cliente);

bool salvarClientes(ListaClientes& lista);

void limparClientes(ListaClientes& lista);

#endif