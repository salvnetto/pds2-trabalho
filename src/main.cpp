#include <iostream>
#include <string>

#include <saldo.hpp>
#include <metas.hpp>

using namespace std;

int main() {
    Saldo conta(1000);
    Metas metas;

    conta.adicionar_transacao("Depósito", 500);
    conta.adicionar_transacao("Compra de alimentos", -200);
    conta.adicionar_transacao("Pagamento de conta de luz", -100);

    // Exibindo o saldo atual e o histórico de transações
    cout << "Saldo atual: R$" << conta.obter_saldo_atual() << endl;
    cout << "Histórico de transações:" << endl;
    for (const auto& transacao : conta.obter_historico_transacoes()) {
        cout << "- " << transacao.first << ": " << transacao.second << endl;
    }
    cout  << "\nBem vindo ao nosso aplicativo de Controle Financeiro Pessoal. \nSelecione uma opcao:"<< endl;
    cout  << "1 - Conferir Saldo Atual"<< endl;
    cout  << "2 - Conferir Historico de Transacoes"<< endl;
    cout  << "3 - Definir metas pessoais"<< endl;
    cout  << "4 - Adicionar uma Transicao"<< endl;

    int escolha;
    cin >> escolha;
    double transicao;
    std::string descricao;

    switch (escolha){
        case 1:
        cout << "Saldo Atual: R$" << conta.obter_saldo_atual() << endl;
        break;

        case 2:
        cout << "Historico de transacoes: " << endl;
        for (const auto& transacao : conta.obter_historico_transacoes()) {
            cout <<"- " << transacao.first << ": " << transacao.second << endl;
            }
        break;

        case 3:
        metas.definirMetas();
        break;

        case 4:
        cout << "Adicione a Descricao - ";
        cin >> descricao;
        cout << "Adicione a Transicao: R$";
        cin >> transicao;
        conta.adicionar_transacao(descricao, transicao);
        break;

        default:
        std::cout << "Opcao invalida" << std::endl;
        break;
    }
    

    return 0;
}