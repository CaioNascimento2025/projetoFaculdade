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
  
  if(numero > 0){
    descricao =" É um número Positivo";
  }
  else if(numero < 0){
    descricao =" É um número Negativo";
  }
  else{
    descricao =" É igual a Zero";
  }

  std::cout<<numero<<descricao<<std::endl;
  
  return 0;
}
