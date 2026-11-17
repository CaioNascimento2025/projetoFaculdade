#include "sistema.h"
#include <iomanip>

void exibirMenu(){
  cout<<"========================================================="<<endl;
  cout<<"             ESTOQUE DE PRODUTOS                         "<<endl;
  cout<<"========================================================="<<endl;
  cout<<endl<<endl;

  cout<<"1 - Cadastrar Produto"<<endl;
  cout<<"2 - Listar Produtos"<<endl;
  cout<<"3 - Pesquisar Produto"<<endl;
  cout<<"4 - Registrar Entrada no Estoque"<<endl;
  cout<<"5 - Registrar Venda"<<endl;
  cout<<"6 - Relatório do Estoque"<<endl;
  cout<<"0 - Sair"<<endl;

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
