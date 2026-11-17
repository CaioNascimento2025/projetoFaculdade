
#include "sistema.h"
#include <limits>

int validarInteiro(void (*funcao)(),string mensagem)
{
    int numero;

    while (true)
    {
        if(mensagem == " "){
          cout<<endl;
          funcao();
        }else{
          cout<<endl;
          cout<<mensagem<<endl;
        }
 
        cout << "\nEscolha uma opcao: ";
        cin >> numero;

        if (cin.fail())
        {
            cout<<"==============================================="<<endl;
            cout << "Digite apenas numeros inteiros!\n";
            cout<<"==============================================="<<endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (cin.peek() != '\n' && cin.peek() != EOF)
        {
            cout<<"=============================================="<<endl; 
            cout << "Nao misture numeros com letras!\n";
            cout<<"=============================================="<<endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (numero < 0)
        {
            cout<<"==========================================="<<endl;
            cout << "Numero invalido!\n";
            cout<<"==========================================="<<endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return numero;
    }
}

double validarDouble(void (*funcao)(),string mensagem)
{
    double numero;

    while (true)
    {	
        if(mensagem == " "){
          cout<<endl;
          funcao();
        }else{
          cout<<endl;
          cout<< mensagem<<endl;
        }

        cin >> numero;

        // Primeiro erro: entrada inválida
        if (cin.fail())
        {
            cout<<"=========================================================="<<endl;
            cout << "\nErro: digite um numero decimal valido!\n";
            cout<<"=========================================================="<<endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        // Segundo erro: letras ou caracteres após o número
        if (cin.peek() != '\n' && cin.peek() != EOF)
        {
            cout<<"========================================================================"<<endl;
            cout << "\nErro: nao misture numeros com letras ou caracteres!\n";
            cout<<"========================================================================"<<endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        // Terceiro erro: número menor ou igual a zero
        if (numero <= 0)
        {
            cout<<"======================================================"<<endl;
            cout << "\nErro: o valor deve ser maior que zero!\n";
            cout<<"======================================================"<<endl;

            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return numero;
    }
}
