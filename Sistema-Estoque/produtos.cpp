#include "sistema.h"

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
    cout<<totalProdutos;
    cout<<"Digite o Código do Produto"<<endl;
    cin>>codigo[totalProdutos];

    cout<<"Digite o Nome do Produto"<<endl;
    cin>>nome[totalProdutos];

    cout<<"Digite O Preço do Produto"<<endl;
    cin>>preco[totalProdutos];

    cout<<"Digite a quantidade do produto";
    cin>>quantidade[totalProdutos];
    
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
      cout<<codigo[i]<<"          "<<nome[i]<<"          "<<preco[i]<<"          "<<"          "<<quantidade[i]<<endl;
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
    cout<<"Preço:      "<<preco[posicao]<<endl;
    cout<<"Quantidade: "<<quantidade[posicao]<<endl;
  }
  else{
    cout<<"============================================"<<endl;
    cout<<"Produto não encontrado na base de Dados"<<endl;
    cout<<"============================================"<<endl;
  }
}
