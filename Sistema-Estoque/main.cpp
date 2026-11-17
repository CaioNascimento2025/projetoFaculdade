#include "sistema.h"

int main()
{
    int opcao;

    do
    {
        opcao = validarInteiro(exibirMenu," ");

        switch (opcao)
        {
            case 1:
                cadastrarProduto();
                break;

            case 2:
                listarProdutos();
                break;

            case 3:
            {
                int codigoPesquisa;

                codigoPesquisa = validarInteiro(exibirMenu,"Digite o Código do Produto: ");

                pesquisarProduto(codigoPesquisa);

                break;
            }

            case 4:
                entradaEstoque();
                break;

            case 5:
                realizarVenda();
                break;

            case 6:
                gerarRelatorio();
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
