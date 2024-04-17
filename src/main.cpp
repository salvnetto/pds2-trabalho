#include <saldo.hpp>
#include <metas.hpp>

using namespace std;

int main() {
    Saldo conta(1000);
    Metas metas;

    conta.adicionar_transacao("Deposito", 500);
    conta.adicionar_transacao("Compra de alimentos", -200);
    conta.adicionar_transacao("Pagamento de conta de luz", -100);

    cout  << "\nBem vindo ao nosso aplicativo de Controle Financeiro Pessoal. \nSelecione uma opcao:"<< endl;

    double transicao;
    std::string descricao;
    int escolha = -1;

while(escolha != 0) {
    cout << "0 - Sair do programa" << endl; 
    cout << "1 - Conferir Saldo Atual"<< endl;
    cout << "2 - Conferir Historico de Transacoes"<< endl;
    cout << "3 - Definir metas pessoais"<< endl;
    cout << "4 - Adicionar uma Transicao"<< endl;
    cout << "5 - Gerar relatorio"<< endl;

    cin >> escolha;

    switch (escolha) {
        case 0:
            cout << "Saindo do programa..." << endl;
            break;
        case 1:
            cout << "Saldo Atual: R$" << conta.obter_saldo_atual() << endl;
            break;
        case 2:
            cout << "Historico de transacoes: " << endl;
            for (const auto& transacao : conta.obter_historico_transacoes()) {
                cout << "- " << transacao.first << ": " << transacao.second << endl;
            }
            break;
        case 3:
            metas.definirMetas();
            break;
        case 4:
            cout << "Adicione a Descricao: ";
            // precisa limpar o buffer do cin se n vai dar problema
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, descricao);

            cout << "Adicione a Transicao: R$: ";
            cin >> transicao;
            conta.adicionar_transacao(descricao, transicao);

            break;
        case 5:
            conta.obter_relatorio();
            break;
        default:
            cout << "Opcao invalida" << endl;
            break;
    }
}

    

    return 0;
}