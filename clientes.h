#ifndef HEADER_CLIENTES
#define HEADER_CLIENTES

#include <fstream>
#include <string>

#define ARQUIVO_CLIENTES "clientes.txt"
#define TAMANHO_NOME 64 + 1
#define TAMANHO_CPF 11 + 1

bool verificarCliente(const char* cpf);

bool cadastrarCliente(const char* nome, const char* cpf);

void testarVerificacao();
void testarCadastro();
#endif