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
  if(totalProdutos >= 50){
    cout<<"================================="<<endl;
    cout<<"     ERRO! quantidade de produtos inválida"<<endl;
    cout<<"================================="<<endl;
    return;
  }
  else{
    cout<<"Código          Nome          Preço          Quantidade"<<endl;
    for(int i =0 ; i < totalProdutos; i++){
      cout<<codigo[i]<<"          "<<nome[i]<<"          "<<fixed<<setprecision(2)<<preco[i]<<"          "<<"          "<<quantidade[i]<<endl;
    }
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
