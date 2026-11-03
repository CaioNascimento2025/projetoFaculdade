#include <iostream>
#include <vector>
#include <string>

int validadorNumero(std::vector <std::string> vetor, int indice){

  int numeroValido;
  while (true){
    std::cout<<"Digite  "<<vetor[indice]<<":"<<std::endl;
    std::cin>>numeroValido;

    if(std::cin.fail()){
      std::cout<<"=============================="<<std::endl;
      std::cout<<"  Você adicionou Letras"<<std::endl;
      std::cout<<"=============================="<<std::endl;
      std::cin.clear();
      std::cin.ignore(1000,'\n');
    }
    else{

      if(std::cin.peek() != '\n'){
        std::cout<<"============================"<<std::endl;
        std::cout<<" Você adicionou letra e número"<<std::endl;
        std::cout<<"============================"<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        continue;
      }
      else{
        if(numeroValido <= 0){
          std::cout<<"=========================="<<std::endl;
          std::cout<<"   Digite um valor maior que  0"<<std::endl;
          std::cout<<"=========================="<<std::endl;
          std::cin.clear();
          std::cin.ignore(1000,'\n');
          continue;
        }
        else{
          if(numeroValido >= 1 && numeroValido <= 10){
            std::cout<<"Você escolheu: "<<numeroValido<<std::endl;
            break;
          }
          std::cout<<"Número maior que 10"<<std::endl;
          std::cin.clear();
          std::cin.ignore(1000,'\n');
        }

      }
    }
  }
  return numeroValido;
}


int main(){
  std::vector <std::string>  mensagemSistema = {"um Número entre 1 a 10"};
  bool entradaValida = false;
  int numeroUsuario;
  do{
    numeroUsuario = validadorNumero(mensagemSistema,0);
    entradaValida = true;
  }
  while(!entradaValida);


  return 0;
}
