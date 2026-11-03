#include <iostream>
#include <vector>
#include <string>

double validadorNumero(std::vector <std::string> vetor, int indice){
  
  double numeroValido;
  while (true){
    std::cout<<"Digite  "<<vetor[indice]<<":"<<std::endl;
    std::cin>>numeroValido;
    
    if(std::cin.fail()){
      std::cout<<"=============================="<<std::endl;
      std::cout<<"  Você adicionou Letras"<<std::endl;
      std::cout<<"=============================="<<std::endl;
      std::cin.clear();
      std::cin.ignore(1000,'\n');
    }
    else{

      if(std::cin.peek() != '\n'){
        std::cout<<"============================"<<std::endl;
        std::cout<<" Você adicionou letra e número"<<std::endl;
        std::cout<<"============================"<<std::endl;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        continue;
      }
      else{
        if(numeroValido < 0){
          std::cout<<"=========================="<<std::endl;
          std::cout<<"   Digite um valor maior ou igual a 0"<<std::endl;
          std::cout<<"=========================="<<std::endl;
          std::cin.clear();
          std::cin.ignore(1000,'\n');
          continue;
        }
        else{
          if(numeroValido >= 0 && numeroValido <= 10){
            break;
          }
          std::cout<<"Número maior que 10"<<std::endl;
          std::cin.clear();
          std::cin.ignore(1000,'\n');
        }

      }
    }
  }
  return numeroValido;
}

int main(){
  std::vector <double> notas; 
  std::vector <std::string> etapaAtual = {"Primeira Nota", "Segunda Nota","Terceira Nota","Quarta Nota","Quinta Nota","Sexta Nota","Sétima Nota","Oitava Nota","Nona Nota","Décima Nota"};
  double notaUsuario;
  double somaNotas;

  somaNotas = 0;

  for(int i = 0; i < etapaAtual.size(); i++){
    notaUsuario = validadorNumero(etapaAtual, i);
    somaNotas += notaUsuario;
    notas.push_back(notaUsuario);
  }
  notas.push_back(somaNotas/notas.size());
  std::cout<<"Média: "<<notas[(notas.size()-1)]<<std::endl;
  return 0;
}
