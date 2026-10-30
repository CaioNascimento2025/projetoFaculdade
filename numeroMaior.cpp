#include <iostream>
#include <string>
#include <vector>

int main(){
  std::vector <int> numerosDigitados;
  int numeros[3], maiorNumero = 0;
  std::string ordem[3] = {"Primeiro","Segundo","Terceiro"};
 
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
       numerosDigitados.push_back(numeros[i]);
       break;
     }
 
    }
    while(true);
  }
  
  std::cout<<"Os números digitados foram: [";
  for(int numero:numerosDigitados){
    std::cout<<numero<<" ";
  }
  std::cout<<"]"<<std::endl;
  
  std::cout<<"O maior número é: "<<maiorNumero<<std::endl;
  
  return 0;
}
