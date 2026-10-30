#include <iostream>
#include <string>
#include <vector>

int main(){
  int numeros[3], maiorNumero = 0, numero_atual, quantidade;
  std::string ordem[3] = {"Primeiro","Segundo","Terceiro"};
  std::vector <int> quantidadeVezes, numerosRepetidos; 
  int tamanho = sizeof(numeros)/4;
  
  for (int i = 0; i < tamanho; i++){
 
    do{
      std::cout<<"Digite o "<<ordem[i]<<" número:"<<std::endl;
      std::cin>>numeros[i];
      
      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(1000,'\n');
      }
      else{
        if(i == 0){
         maiorNumero = numeros[i];
        }
        else if(maiorNumero < numeros[i]){
          maiorNumero = numeros[i];
        }
 
       break;
     }
 
    }
    while(true);
  }
  
  for(int numero:numeros){
    numero_atual = numero;
    quantidade = 0;
    for(int i = 0; i < tamanho; i++){
      if(numero_atual == numeros[i]){
        quantidade++;
        continue;
      }
    }
    bool jaExiste = false;
    for(int numero: numerosRepetidos){
      
      if(numero_atual == numero){
        jaExiste = true;
        break;
      }
    }
      if(quantidade > 1 && jaExiste == false){
        numerosRepetidos.push_back(numero_atual);
        quantidadeVezes.push_back(quantidade);
      }
  }  

  for(int j = 0; j < quantidadeVezes.size(); j++){
    if(quantidadeVezes[j] > 1){
      std::cout<<" O número: "<<numerosRepetidos[j]<<" Apareceu: "<<quantidadeVezes[j]<<" Vezes"<<std::endl;
    }
  }
  std::cout<<"O maior número é: "<<maiorNumero<<std::endl;
  
  return 0;
}
