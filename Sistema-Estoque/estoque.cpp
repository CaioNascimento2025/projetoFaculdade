#include "sistema.h"

void entradaEstoque()
{
    int codigoBusca;
    int quantidadeEntrada;
    bool encontrado = false;
    int posicao = -1;
    
    codigoBusca = validarInteiro(exibirMenu,"Código do Produto: ");

    for(int i = 0; i<totalProdutos; i++){
      if(codigoBusca == codigo[i]){
        posicao = i;
        encontrado = true;
        break;
      }
    }

    if (posicao == -1)
    {
        cout << "Produto nao encontrado!";
        return;
    }
    if(encontrado && posicao >= 0){
  
      quantidadeEntrada = validarInteiro(exibirMenu,"Quantidade recebida: ");

      if (quantidadeEntrada <= 0)
      {   cout<<"=================================="<<endl;
          cout << "Quantidade invalida!"<<endl;
          cout<<"=================================="<<endl;
          return;
      }

      quantidade[posicao] += quantidadeEntrada;
      cout<<"=============================="<<endl;
      cout << "Estoque atualizado!"<<endl;
      cout<<"=============================="<<endl;
    }
}

void realizarVenda()
{
    int codigoBusca;
    int quantidadeVenda;
    int posicao = -1;

    string texto1 = "\n===== REGISTRAR VENDA =====\n";

    string texto2 =  "Código do Produto";
    codigoBusca = validarInteiro(exibirMenu,(texto1 + texto2));

    // Localizar produto
    for(int i = 0; i < totalProdutos; i++){
      if(codigoBusca == codigo[i]){
        posicao = i;
        break;

      }
    }

    if (posicao == -1)
    {   
        cout<<"========================================="<<endl;
        cout << "Produto nao encontrado!"<<endl;
        cout<<"========================================="<<endl;
        return;
    }

    cout << "Produto: " << nome[posicao] << endl;
    cout << "Preco unitario: R$ " << preco[posicao] << endl;
    cout << "Estoque atual: " << quantidade[posicao] << endl;

    quantidadeVenda = validarInteiro(exibirMenu,"Quantidade Vendida");

    // Validar quantidade
    if (quantidadeVenda <= 0)
    {
        cout<<"======================================"<<endl;
        cout << "Quantidade invalida!"<<endl;
        cout<<"======================================"<<endl;
        return;
    }

    // Verificar estoque disponível
    if (quantidadeVenda <= quantidade[posicao])
    {
        double total = preco[posicao] * quantidadeVenda;

        // Atualizar estoque
        quantidade[posicao] -= quantidadeVenda;

        cout <<endl<< "===== VENDA REALIZADA ====="<<endl;
        cout << "Produto: " << nome[posicao] << endl;
        cout << "Quantidade: " << quantidadeVenda << endl;
        cout << "Valor unitario: R$ " << preco[posicao] << endl;
        cout << "Total: R$ " << total << endl;
        cout << "Estoque restante: " << quantidade[posicao] << endl;
    }
    else
    {
        cout<<"========================================="<<endl;
        cout <<endl<< "Venda nao realizada!"<<endl;
        cout << "Quantidade insuficiente em estoque."<<endl;
        cout<<"=========================================="<<endl;
    }
}
