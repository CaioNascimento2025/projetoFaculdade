#include <iostream>

int main(){

  int inicioLoop, fimLoop, contadorPares;
  
  contadorPares = 0;

  for(inicioLoop = 1, fimLoop = 100; inicioLoop <= fimLoop; inicioLoop++){

    if(inicioLoop%2 == 0){
      contadorPares++;
      if(inicioLoop%10 == 0){
        std::cout<<inicioLoop<<std::endl;
        continue;
      }
      if(inicioLoop != fimLoop){
        std::cout<<inicioLoop<<" - ";
      }
      else{
        std::cout<<inicioLoop<<std::endl;
      }
    }
  }
  std::cout<<"Total de números pares: "<<contadorPares<<std::endl;
  std::cout<<"Fim do Programa"<<std::endl;
  return 0;
}
