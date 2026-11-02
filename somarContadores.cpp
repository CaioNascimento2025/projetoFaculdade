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
        if(numeroValido < 0){
          std::cout<<"=========================="<<std::endl;
          std::cout<<"   Digite um valor maior ou igual a 0"<<std::endl;
          std::cout<<"=========================="<<std::endl;
          std::cin.clear();
          std::cin.ignore(1000,'\n');
          continue;
        }
        break;
        
      }
    }
  }
  return numeroValido;
}


int main(){
  int numeroUsuario = validadorNumero(), inicioLoop, totalContador;
  
  totalContador = 0;
  
  for(inicioLoop = 1; inicioLoop <= numeroUsuario; inicioLoop++){
    totalContador+= inicioLoop;
  }
  std::cout<<"Total: "<<totalContador<<std::endl;
  return 0;
}
