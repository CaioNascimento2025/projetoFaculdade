#include <iostream>
#include <vector>
#include <string>

int main(){
  double valorCompra, desconto;

  while(true){
    std::cout<<"Digite o preço da compra: "<<std::endl;
    std::cin>>valorCompra;

    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(1000,'\n');
    }
    else{
      if(valorCompra > 0){
        break;
      }
      else if(valorCompra == 0){
        std::cout<<valorCompra<<" Não existe produto grátis com valor R$ 0"<<std::endl;
      }
      else{
        std::cout<<valorCompra<<" Não pode ser negativo"<<std::endl;
      }
    }
  }

  if(valorCompra >= 0 && valorCompra < 100){
    desconto = 0;
  }
  else if(valorCompra >= 100 && valorCompra < 300){
    desconto = 5;
  }
  else if(valorCompra >= 300 && valorCompra < 500){
    desconto = 10;
  }
  else if(valorCompra >= 500){
    desconto = 15;
  }
  
  std::cout<<"O valor da compra é R$: "<<valorCompra<<" Desconto : "<<desconto<<"%"<<" Preço com Desconto R$: "<<(valorCompra - (valorCompra*desconto)/100)<<std::endl;

  return 0;
}
  
