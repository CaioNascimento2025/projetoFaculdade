#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int validadorNumero(std::vector <std::string> vetor, int indice){

  int numeroValido;
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
          std::cout<<"   Digite um valor maior que  0"<<std::endl;
          std::cout<<"=========================="<<std::endl;
          std::cin.clear();
          std::cin.ignore(1000,'\n');
          continue;
        }
        else{
          if(numeroValido >= 1){
            break;
          }
        }

      }
    }
  }
  return numeroValido;
}

void limparEntrada (){
  std::cin.clear();
  std::cin.ignore(1000,'\n');
}

int main(){
  int entradaUsuario, contador;
  std::vector <std::string> etapaAtual = {"Primeiro número Fatorial","Último número Fatorial"};
  int entradas[2] ={0, 0};
  std::vector <int> numerosPrimos;
  contador = 0;
  bool numeroPrimo;
  
  do{
    entradaUsuario = validadorNumero(etapaAtual,contador);   
    entradas[contador] = entradaUsuario;
    if(entradas[0] > entradas[1] && contador == 1){
      std::cout<<"O Primeiro número é maior do que o Segundo Número"<<std::endl;
      limparEntrada();
      continue;
    }

    contador++;
  }
  while(contador <= 1);
    
  for(int inicioLoop = entradas[0], fimLoop = entradas[1]; inicioLoop <= fimLoop; inicioLoop++){
    
    double raizQuadradaContador = std::sqrt(inicioLoop);

    numeroPrimo = inicioLoop >= 2;

    int contadorDivisoes = 0;

    for(int i = 2; i <= raizQuadradaContador; i++){

      if(inicioLoop % i == 0){

          contadorDivisoes++;

          if(contadorDivisoes > 0){
              numeroPrimo = false;
              break;
          }
        }
      }
    if (numeroPrimo){
      std::cout<<"Número Primo: "<<inicioLoop<<std::endl;
      numerosPrimos.push_back(inicioLoop);
    }
  } 
  

  
  return 0;
}
