#include <iostream>
#include <string>
int main(){
  int numero;
  std::string descricao;
  
  do{
    std::cout<<"Digite um número inteiro:"<<std::endl;
    std::cin>>numero;
    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(1000,'\n');
    }
    else{
      break;
    }
  }
  while(true);
  
  if(numero%2 == 0){
    descricao = " é um número PAR";
  }
  else{
    descricao = " é um número IMPAR";
  }

  std::cout<<numero<<descricao<<std::endl;

  return 0;
}
