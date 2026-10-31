#include <iostream>
#include <vector>
#include <string>

int main(){
  std::vector <double> notas;
  std::string ordem[2] = {"Primeira","Segunda"}, situacao;
  double nota, media;

  for(int i = 0; i < 2; i++){
    
    while(true){
      std::cout<<"Digite a "<<ordem[i]<<" Nota"<<std::endl;
      std::cin>>nota;

      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(1000,'\n');
      }
      else{
        if(nota < 0 || nota > 10){
          continue;
        }
        notas.push_back(nota);
        double somaNotas = 0;
        for(int j = 0; j < notas.size(); j++){
       
          somaNotas += notas[j];
          media = somaNotas/notas.size();
        }

        break;
      }
    }
  }

  if(media >= 7){
    situacao = "Aprovado";
  }
  else if(media >= 4 && media < 7){
    situacao = "Recuperação";
  }
  else if (media >= 0 && media < 4){
   situacao = "Reprovado";
  }
  else{
    std::cout<<"ERRO por favor nos informe a situação";
  }

  std::cout<<"Média: "<<media<<" Situação:  "<<situacao<<std::endl;
  
  return 0;
}
