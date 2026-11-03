#include <iostream>
#include <string>
#include <iomanip>

int main(){
  double dados[3];
  std::string classificacao, etapaAtual[2] = {"Massa Corporal","Altura"}, medida[2] = {"Kg","m"};

  for(int i = 0; i < 2; i++){
    while(true){
      std::cout<<"Digite a "<<etapaAtual[i]<<" "<<medida[i]<<":"<<std::endl;
      std::cin>>dados[i];

      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(1000,'\n');
      }
      else{ 
        if(dados[i] > 0){
          break;
        }
        else if(dados[i] == 0){
          std::cout<<dados[i]<<" Não existe "<<etapaAtual[i]<<" de pessoa igual a zero!"<<std::endl;
        }
        else{
          std::cout<<dados[i]<<" Não pode ser negativo"<<std::endl;
        }
      }
    }
  
  }
  dados[2] = dados[0]/(dados[1] * dados[1]);

  if(dados[2] > 0 && dados[2] < 18.5){
    classificacao =  "Abaixo do Peso";
  }
  else if(dados[2] >= 18.5 && dados[2] < 25){
    classificacao = "Faixa Usual";
  }
  else if(dados[2] >= 25 && dados[2] < 30){
    classificacao = "Sobrepeso";
  }
  else if(dados[2] >= 30){
    classificacao = "Obesidade";
  }
  else{
    std::cout<<"ERRO por favor contate-nos";
    return 0;
  }

  std::cout<<std::fixed<<std::setprecision(2)<<std::endl<<" Peso: "<<dados[0]<<std::endl<<" Altura: "<<dados[1]<<std::endl<<" Indice de Massa Corporal: "<<dados[2]<<std::endl<<" Situação: "<<classificacao<<std::endl;
  return 0;
}
