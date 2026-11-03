#include <iostream>


int validadorNumero(){

  int numeroValido;
  while (true){
    std::cout<<"Digite um número inteiro: "<<std::endl;
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
        break;
      } 
    }
  }
  return numeroValido;
}
int main(){
  int numero, inicioLoop, fimLoop;
  
  numero = validadorNumero();
  std::cout<<"xxxxxxxxxxxxxxxxxxxxxxxxx"<<std::endl;  
  for(inicioLoop = 1, fimLoop = 10; inicioLoop <= fimLoop; inicioLoop++){
    std::cout<<numero<<" X "<<inicioLoop<<" = "<<(numero*inicioLoop)<<std::endl;
  }
  std::cout<<"xxxxxxxxxxxxxxxxxxxxxxxxx"<<std::endl;
  std::cout<<"Fim do Programa"<<std::endl;
  return 0;
}
