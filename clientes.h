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

bool pesquisarCliente(Cliente& cliente, int _id, const char* _cpf);

bool cadastrarCliente(const char* nome, const char* cpf);

void testarVerificacao();
void testarCadastro();
#endif