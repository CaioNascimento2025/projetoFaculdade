#include "sistema.h"
#include <iomanip>

void exibirMenu()
{
    cout << "============================\n";
    cout << "     ESTOQUE DE PRODUTOS\n";
    cout << "============================\n";

    cout << "1 - Cadastrar Produto\n";
    cout << "2 - Listar Produtos\n";
    cout << "3 - Pesquisar Produto\n";
    cout << "4 - Entrada no Estoque\n";
    cout << "5 - Registrar Venda\n";
    cout << "6 - Relatorio\n";
    cout << "0 - Sair\n";
}

void gerarRelatorio()
{
    if (totalProdutos == 0)
    {
        cout<<"==========================================="<<endl;
        cout << "Nenhum produto cadastrado!"<<endl;
        cout<<"==========================================="<<endl;
        return;
    }

    int totalUnidades = 0;
    int produtosEstoqueBaixo = 0;

    double valorEstoque = 0.0;

    int maiorEstoque = 0;
    int menorEstoque = 0;

    for (int i = 0; i < totalProdutos; i++)
    {
        // Somar todas as unidades
        totalUnidades += quantidade[i];

        // Calcular valor total do estoque
        valorEstoque += preco[i] * quantidade[i];

        // Identificar maior estoque
        if (quantidade[i] > quantidade[maiorEstoque])
        {
            maiorEstoque = i;
        }

        // Identificar menor estoque
        if (quantidade[i] < quantidade[menorEstoque])
        {
            menorEstoque = i;
        }

        // Identificar estoque baixo
        if (quantidade[i] < 5)
        {
            produtosEstoqueBaixo++;
        }
    }

    cout << fixed << setprecision(2);

    cout <<endl<< "========== RELATORIO DO ESTOQUE =========="<<endl;

    cout <<endl<< "Quantidade de produtos cadastrados: "
         << totalProdutos << endl;

    cout << "Quantidade total de unidades: "
         << totalUnidades << endl;

    cout << "Valor total do estoque: R$ "
         << valorEstoque << endl;

    cout << "Produto com maior estoque: "
         << nome[maiorEstoque]
         << " (" << quantidade[maiorEstoque] << " unidades)"<<endl;

    cout << "Produto com menor estoque: "
         << nome[menorEstoque]
         << " (" << quantidade[menorEstoque] << " unidades)"<<endl;

    cout << "Produtos com estoque baixo: "
         << produtosEstoqueBaixo << endl;

    cout <<endl<< "=========================================="<<endl;
}
