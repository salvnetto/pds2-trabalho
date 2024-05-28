#include <iostream>
#include "Saldo.hpp"
#include "Metas.hpp"
#include "Banco.hpp"
#include "ContaBancaria.hpp"
#include "CartaoDeCredito.hpp"

using namespace std;

void mostrarMenu() {
    cout << "\nBem vindo ao nosso aplicativo de Controle Financeiro Pessoal. \nSelecione uma opcao:" << endl;
    cout << "0 - Sair do programa" << endl;
    cout << "1 - Conferir Saldo Atual" << endl;
    cout << "2 - Conferir Historico de Transacoes" << endl;
    cout << "3 - Definir metas pessoais" << endl;
    cout << "4 - Adicionar uma Transicao" << endl;
    cout << "5 - Criar uma nova conta" << endl;
    cout << "6 - Pesquisar uma conta" << endl;
    cout << "7 - Listar todas as contas" << endl;
    cout << "8 - Associar Cartao de Credito a uma Conta" << endl;
    cout << "9 - Adicionar Despesa no Cartao de Credito" << endl;
    cout << "10 - Mostrar Informaçoes do Cartão de Credito" << endl;
}

int main() {
    Banco banco;
    Saldo conta(1000);
    Metas metas;

    conta.adicionar_transacao("Deposito", 500);
    conta.adicionar_transacao("Compra de alimentos", -200);
    conta.adicionar_transacao("Pagamento de conta de luz", -100);

    double transicao;
    std::string descricao;
    int escolha = -1;

    while (escolha != 0) {
        mostrarMenu();
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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, descricao);

                cout << "Adicione a Transicao: R$: ";
                cin >> transicao;
                conta.adicionar_transacao(descricao, transicao);
                break;
            case 5: {
                int id;
                string cliente;
                cout << "Digite o ID da nova conta: ";
                cin >> id;
                cout << "Digite o nome do cliente: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, cliente);

                ContaBancaria* novaConta = banco.criaConta(id, cliente);
                if (novaConta) {
                    cout << "Conta criada com sucesso!" << endl;
                } else {
                    cout << "Erro ao criar a conta. ID pode ser duplicado ou o banco está cheio." << endl;
                }
                break;
            }
            case 6: {
                int id;
                cout << "Digite o ID da conta a ser pesquisada: ";
                cin >> id;

                ContaBancaria* contaEncontrada = banco.pesquisa(id);
                if (contaEncontrada) {
                    contaEncontrada->imprime();
                } else {
                    cout << "Conta não encontrada." << endl;
                }
                break;
            }
            case 7:
                banco.listaContas();
                break;
            case 8: {
                int id;
                cout << "Digite o ID da conta a qual deseja associar o cartao: ";
                cin >> id;

                ContaBancaria* contaEncontrada = banco.pesquisa(id);
                if (contaEncontrada) {
                    string numero;
                    double limite;
                    int cvv;
                    string dataValidade;

                    cout << "Digite o numero do cartao: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, numero);
                    cout << "Digite o limite do cartão: ";
                    cin >> limite;
                    cout << "Digite o CVV: ";
                    cin >> cvv;
                    cout << "Digite a data de validade (MM/AA): ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, dataValidade);

                    CartaoDeCredito* cartao = new CartaoDeCredito(numero, limite, cvv, dataValidade);
                    contaEncontrada->associarCartao(cartao);

                    cout << "Cartão de crédito associado com sucesso." << endl;
                } else {
                    cout << "Conta não encontrada." << endl;
                }
                break;
            }
            case 9: {
                int id;
                cout << "Digite o ID da conta para adicionar uma despesa no cartao: ";
                cin >> id;

                ContaBancaria* contaEncontrada = banco.pesquisa(id);
                if (contaEncontrada && contaEncontrada->obterCartao()) {
                    double despesa;
                    cout << "Digite o valor da despesa: ";
                    cin >> despesa;
                    contaEncontrada->obterCartao()->adicionarDespesa(despesa);

                    cout << "Despesa adicionada com sucesso." << endl;
                } else {
                    cout << "Conta ou cartão não encontrados." << endl;
                }
                break;
            }
            case 10: {
                int id;
                cout << "Digite o ID da conta para mostrar informações do cartao: ";
                cin >> id;

                ContaBancaria* contaEncontrada = banco.pesquisa(id);
                if (contaEncontrada && contaEncontrada->obterCartao()) {
                    contaEncontrada->obterCartao()->imprimirInformacoes();
                } else {
                    cout << "Conta ou cartão não encontrados." << endl;
                }
                break;
            }
            default:
                cout << "Opcao invalida" << endl;
                break;
        }
    }

    return 0;
}
