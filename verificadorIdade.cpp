#include <iostream>

int main(){
  int idade;
  std::string descricao;
  do{
    std::cin>>idade;

    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(1000,'\n');
    }
    else{
      if(0 <= idade && idade< 18){
        descricao =  " Menor de Idade";
      }
      else if(idade >= 18){
        descricao = " Maior de Idade";
      }
      else{
        continue;
      }
      
      break;
    }
  }
  while(true);

  std::cout<<idade<<descricao<<std::endl;

  return 0;
}
