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
          if(numeroValido >= 1 && numeroValido <= 20){
            break;
          }
          std::cout<<"Número maior que 20"<<std::endl;
          std::cin.clear();
          std::cin.ignore(1000,'\n');
        }

      }
    }
  }
  return numeroValido;
}
int main(){
  int numeroUsuario, contador;
  std::vector <std::string> mensagemUsuario = {"Entre 1 a 20"};
  numeroUsuario = validadorNumero(mensagemUsuario,0);
  
  contador = 1;
  for(int i = numeroUsuario; i != 1; i--) {
    contador *= i;

  }
  
  std::cout<<"Número Selecionado: "<<numeroUsuario<<std::endl<<"Fatorial Resultado: "<<contador<<std::endl;
  return 0;
}
