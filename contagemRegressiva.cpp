#include <iostream>

int main(){

  int inicioLoop, fimLoop, contador;

  inicioLoop = 10;
  fimLoop = 0;
  contador = 1;
  while(inicioLoop >= fimLoop){
    if(contador%10 == 0){
      std::cout<<inicioLoop<<std::endl;
    }
    else{
      if(inicioLoop == fimLoop){
        std::cout<<inicioLoop<<std::endl;
        break;
      }
      std::cout<<inicioLoop<<" > ";
    }
    contador++;
    inicioLoop--;
  }

  return 0;
}
