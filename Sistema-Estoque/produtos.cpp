#include "sistema.h"
#include <algorithm> // Necessário para a função transform
#include <cctype>    // Necessário para tolower

int codigo[LIMITE];
string nome[LIMITE];
double preco[LIMITE];
int quantidade[LIMITE];

int totalProdutos = 0;

void cadastrarProduto(){
  if(totalProdutos >= 50){
    cout<<"==========================="<<endl;
    cout<<"ERRO ! BANCO DE DADOS CHEIO"<<endl;
    cout<<"==========================="<<endl;
    return;
  }
  else{
    bool codigoValido;
    do{
      codigoValido = true;
      codigo[totalProdutos] = validarInteiro(exibirMenu,"Digite o Código do Produto: ");
      for(int i =0; i < totalProdutos; i++){
        if(codigo[totalProdutos]==codigo[i]){
          codigoValido = false;
          cout<<endl<<"========================================================"<<endl;
          cout<<"        Código já registrado tente outro                      "<<endl;
          cout<<endl<<"========================================================"<<endl;
          break;
        }
      }

    }
    while(!codigoValido);
    cout<<endl;

    bool nomeValido;
    do{
      nomeValido = true;
      cout<<endl<<"Digite o Nome do Produto"<<endl;
      if(getline(cin >> ws, nome[totalProdutos])){
        // Encontra o último caractere que não seja espaço/tabulação
        size_t fim = nome[totalProdutos].find_last_not_of(" \t\n\r");
        if (fim != string::npos) {
          nome[totalProdutos] = nome[totalProdutos].substr(0, fim + 1);
        } 
        else {
          nome[totalProdutos] = ""; // Caso a string seja apenas espaços
        }
      }

      // Converte o texto digitado para caixa baixa
      transform(nome[totalProdutos].begin(), nome[totalProdutos].end(), nome[totalProdutos].begin(), ::tolower);

      for(int i =0; i < totalProdutos; i++){
        if(nome[totalProdutos]==nome[i] && totalProdutos != i){
          nomeValido = false;
          cout<<endl<<"========================================================"<<endl;
          cout<<"        Nome já registrado tente outro                      "<<endl;
          cout<<endl<<"========================================================"<<endl;
          break;
        }
      }

    }
    while(!nomeValido);

    preco[totalProdutos] = validarDouble(exibirMenu,"Digite o Preço do Produto: ");
    quantidade[totalProdutos] = validarInteiro(exibirMenu,"Digite a Quantidade do Produto: ");

    totalProdutos++;
  }
}


  

void listarProdutos(){

    if(totalProdutos == 0){
        cout << "Nenhum produto cadastrado!" << endl;
        return;
    }

    // Tamanhos mínimos dos cabeçalhos
    int maiorCodigo = 6;
    int maiorNome = 4;
    int maiorPreco = 5;
    int maiorQuantidade = 10;

    // Descobrir o maior tamanho de cada coluna
    for(int i = 0; i < totalProdutos; i++){

        maiorCodigo = max(maiorCodigo,
                          (int)to_string(codigo[i]).length());

        maiorNome = max(maiorNome,
                        (int)nome[i].length());

        string valorPreco = to_string(preco[i]);
        maiorPreco = max(maiorPreco,
                         (int)valorPreco.substr(0, valorPreco.find('.') + 3).length());

        maiorQuantidade = max(maiorQuantidade,
                              (int)to_string(quantidade[i]).length());
    }

    // Cabeçalho
    cout << left
         << setw(maiorCodigo + 6) << "Código"
         << setw(maiorNome + 4) << "Nome"
         << setw(maiorPreco + 5) << "Preço"
         << setw(maiorQuantidade + 9) << "Quantidade"
         << endl;

    // Produtos
    for(int i = 0; i < totalProdutos; i++){

        cout << left
             << setw(maiorCodigo + 6) << codigo[i]
             << setw(maiorNome + 4) << nome[i]
             << setw(maiorPreco + 5) << fixed << setprecision(2) << preco[i]
             << setw(maiorQuantidade + 9) << quantidade[i]
             << endl;
    }
}


void pesquisarProduto(int idProduto){
  bool encontrado = false;
  int posicao = -1;

  for(int i = 0; i < totalProdutos; i++){
    if(idProduto == codigo[i]){
      encontrado = true;
      posicao = i;
      break;
    }    
  }
  if(encontrado){
    cout<<"Código:     "<<codigo[posicao]<<endl;
    cout<<"Nome:       "<<nome[posicao]<<endl;
    cout<<"Preço:      "<<fixed<<setprecision(2)<<preco[posicao]<<endl;
    cout<<"Quantidade: "<<quantidade[posicao]<<endl;
  }
  else{
    cout<<"============================================"<<endl;
    cout<<"Produto não encontrado na base de Dados"<<endl;
    cout<<"============================================"<<endl;
  }
}
