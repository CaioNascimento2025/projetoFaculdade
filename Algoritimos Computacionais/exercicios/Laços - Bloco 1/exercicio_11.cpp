#include <iostream>

int main(){
  int inicioLoop, fimLoop;

  for(inicioLoop = 1, fimLoop = 20; inicioLoop <= fimLoop; inicioLoop++ ){
    if(inicioLoop % 10 == 0){
      std::cout<<inicioLoop<<std::endl;
    }
    else{
      std::cout<<inicioLoop<<" < ";
    }
    
  }
  std::cout<<"Fim do Programa"<<std::endl;
  return 0;
}
