// sistema.h

#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <string>

using namespace std;

const int LIMITE = 50;

// Vetores compartilhados
extern int codigo[LIMITE];
extern string nome[LIMITE];
extern double preco[LIMITE];
extern int quantidade[LIMITE];

extern int totalProdutos;

// Funções
void exibirMenu();

void cadastrarProduto();
void listarProdutos();
void pesquisarProduto(int codigoPesquisa);

void entradaEstoque();
void realizarVenda();

void gerarRelatorio();

#endif

