#include <iostream>
#include <vector>
#include <string>
#include <cmath>

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
        if(numeroValido < 0){
          std::cout<<"=========================="<<std::endl;
          std::cout<<"   Digite um valor maior que  0"<<std::endl;
          std::cout<<"=========================="<<std::endl;
          std::cin.clear();
          std::cin.ignore(1000,'\n');
          continue;
        }
        else{
          if(numeroValido >= 1){
            break;
          }
        }

      }
    }
  }
  return numeroValido;
}


int main (){
  int numeroUsuario, contadorDivisores;
  bool numeroPrimo = false;
  double raizQuadrada;
  std::string resultado;
  std::vector <std::string> mensagemUsuario = {"Numero não Negativo"};
  numeroUsuario = validadorNumero(mensagemUsuario,0);
  contadorDivisores = 0;
  raizQuadrada = std::sqrt(numeroUsuario);

  for(int i = 1; i <= raizQuadrada; i++){
    if(numeroUsuario%i == 0){
      contadorDivisores++;

      if(contadorDivisores >= 2){
        numeroPrimo = false;
        break;
      }
    }
    numeroPrimo = true;
  }
  
  if(numeroPrimo == 0){
    resultado = "Falso";
  }
  else{
    resultado = "Verdadeiro";
  }
  std::cout<<"Número: "<<numeroUsuario<<std::endl<<"Número Primo: "<<resultado<<std::endl;
 
  return 0;
}
