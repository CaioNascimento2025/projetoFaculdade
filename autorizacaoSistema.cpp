#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

std::vector <int> validadorEntrada(std::vector <std::string> lista){
  int entradaUsuario;
  std::vector <int> vetorUsuario;

  for(int i = 0; i < lista.size(); i++ ){
    while (true){
      std::cout<<"Digite "<<lista[i]<<std::endl;
      std::cin>>entradaUsuario;
      
      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout<<"==============================="<<std::endl;
        std::cout<<" Não é uma entrada Válida"<<std::endl;
        std::cout<<"==============================="<<std::endl;
      }
      else{
        if(entradaUsuario >= 0){
          vetorUsuario.push_back(entradaUsuario);
          break;
        }
        else{
          std::cout<<"========================"<<std::endl;
          std::cout<<"Não é possível usar valores NEGATIVOS"<<std::endl;
          std::cout<<"========================"<<std::endl;
        }
      }
    }
  }
  return vetorUsuario;
}

int main(){
  const char* senhaTexto = std::getenv("CODIGO_ACESSO");
  const char* statusTexto = std::getenv("USUARIO_ATIVO");
  std::vector <int> dadosUsuario;
  std::vector <std::string> etapaAtual = {"Código de acesso","Status usuário (1 - Sim) / (0 - Não)"};
  int senha, status;
  bool logout = false;

  if(senhaTexto != nullptr && statusTexto != nullptr){
    senha = std::atoi(senhaTexto);
    status = std::atoi(statusTexto);
  }
  else{
    std::cout<<"Você não possui uma senha e status Registrados em uma variável de ambiente!"<<std::endl;
    return 0;
  }
  
  while(!logout){
    dadosUsuario = validadorEntrada(etapaAtual);
    if(dadosUsuario[0] == senha && dadosUsuario[1] == status){
      std::cout<<"Senha e status corretos! seja Bem vindo"<<std::endl;  
      logout = true;
    }
    else{
      std::cout<<"Senha ou status não encontrado!"<<std::endl;
    }  
  }
  return 0;

}
