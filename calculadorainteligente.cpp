#include <iostream>
#include <string>
#include <tuple>
#include <vector>

std::tuple <double,double,char> validadorEntrada(std::vector <std::string> lista){
  int tamanhoLista = lista.size();
  std::tuple <double,double,char> tupleUsuario = {0,0,'x'}; 

  for(int i = 0; i < tamanhoLista; i++ ){
    while (true){
      std::cout<<"Digite "<<lista[i]<<std::endl;
      
      switch (i){
        case 0:
          std::cin>>std::get<0>(tupleUsuario);
          break;
        case 1:
          std::cin>>std::get<1>(tupleUsuario);
          break;
        case 2:
          std::cin>>std::get<2>(tupleUsuario);
          break;
        default:
          std::cout<<"Erro por favor contate - nos"<<std::endl;
      }
        

      if(std::cin.fail()){                                    
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout<<"==============================="<<std::endl;
        std::cout<<" Não é uma entrada Válida"<<std::endl;
        std::cout<<"==============================="<<std::endl;
      }
      else{
        
        if(i == 2){
          if(std::get<2>(tupleUsuario) == '+' || std::get<2>(tupleUsuario) == '-' || std::get<2>(tupleUsuario) == '*' || std::get<2>(tupleUsuario) == '/'){
            break;
          }
          else{
            std::cout<<"Escolha um operador Válido"<<std::endl;
            std::cin.ignore(1000,'\n');
            continue;
          }
        } 
        else{
          if(std::cin.peek() != '\n'){
            if (i == 0){
              std::cout<<" Não é permitido"<<std::endl;
              std::cin.ignore(1000,'\n');
              continue;
            }
            else if (i == 1){
              std::cout<<" Não é permitido"<<std::endl;
              std::cin.ignore(1000,'\n');
              continue;
            }
          }
          break;
        }

      }
    }
  }
  return tupleUsuario;
}


int main(){

  double primeiroNumero, segundoNumero;
  char operador;
  std::vector <std::string> etapaAtual = {"Primeiro Número","Segundo Número","Operação ( + igual adição, - igual subtração, * igual multiplicação, / igual divisão" };   
  
  std::tie(primeiroNumero, segundoNumero, operador) = validadorEntrada(etapaAtual);
  
  switch(operador){
    case '+':
      std::cout<<primeiroNumero<<" "<<operador<<" "<<segundoNumero<<" = "<<(primeiroNumero+segundoNumero)<<std::endl;
      break;
    case '-':
      std::cout<<primeiroNumero<<" "<<operador<<" "<<segundoNumero<<" = "<<(primeiroNumero-segundoNumero)<<std::endl;
      break;
    case '*':
      std::cout<<primeiroNumero<<" "<<operador<<" "<<segundoNumero<<" = "<<(primeiroNumero*segundoNumero)<<std::endl;
      break;
    case '/':
      if(segundoNumero == 0){
        bool contemZero = true;
        while(contemZero){
          std::cout<<"Não é possível dividir um núnero por 0, Escolha outro número: "<<std::endl;
          std::cin>>segundoNumero;
          if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000,'\n');
          }
          else{
            if(segundoNumero != 0  && std::cin.peek() == '\n'){
              contemZero = false;
            }
            else{
              std::cin.ignore(1000,'\n');
              continue;
            }
          }
        }
      }

      std::cout<<primeiroNumero<<" "<<operador<<" "<<segundoNumero<<" = "<<(primeiroNumero/segundoNumero)<<std::endl;
      break;

    default:
      std::cout<<"ERRO por favor contate - nos"<<std::endl;
  }
  
  return 0;
}
