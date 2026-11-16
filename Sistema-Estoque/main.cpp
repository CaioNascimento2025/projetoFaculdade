#include "sistema.h"

int main()
{
    int opcao;

    do
    {
//        exibirMenu();
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                //cadastrarProduto();
                break;

            case 2:
                //listarProdutos();
                break;

            case 3:
            {
                int codigoPesquisa;

                cout << "Codigo: ";
                cin >> codigoPesquisa;

                //int posicao = pesquisarProduto(codigoPesquisa);

                //if (posicao == -1)
                    cout << "Produto nao encontrado!\n";

                break;
            }

            case 4:
                //entradaEstoque();
                break;

            case 5:
                //realizarVenda();
                break;

            case 6:
                //gerarRelatorio();
                break;

            case 0:
                cout << "Encerrando sistema...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}
