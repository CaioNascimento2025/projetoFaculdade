#include <iostream>
#include <string>

int main(){
  int idade;
  std::string faixaIdade;

  while(true){
    std::cout<<"Digite a sua Idade: "<<std::endl;
    std::cin>>idade;

    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(1000,'\n');
    }
    else{
      if(idade >= 0){
        break;
      }
      else{
        std::cout<<idade<<" Não pode ser negativo"<<std::endl;
      }
    }
  }

  if(idade >= 0 && idade <= 11){
    faixaIdade = "Criança";
  }
  else if(idade >= 12 && idade <= 17){
    faixaIdade = "Adolescente";
  }
  else if(idade >= 18 && idade <= 59){
    faixaIdade = "Adulto";
  }
  else if (idade >= 60 && idade <= 200){
    faixaIdade = "Idoso";
  }
  else{
    std::cout<<"ERRO! por favor contate - nos"<<std::endl;
    return 0;
}

  std::cout<<"Idade: "<<idade<<" Anos"<<" Você é: "<<faixaIdade<<std::endl;
  return 0;
}
