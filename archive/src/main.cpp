#include <iostream>
#include <limits>  // Adicionar esta linha para usar numeric_limits
#include "Saldo.hpp"
#include "Banco.hpp"
#include "ContaBancaria.hpp"
#include "CartaoDeCredito.hpp"

using namespace std;

void mostrarMenu() {
    cout << "\nBem vindo ao nosso aplicativo de Controle Financeiro Pessoal. \nSelecione uma opcao:" << endl;
    cout << "0 - Sair do programa" << endl;
    cout << "1 - Conferir Saldo Atual" << endl;
    cout << "2 - Conferir Historico de Transacoes" << endl;
    cout << "3 - Adicionar uma Transacao" << endl;
    cout << "4 - Criar uma nova conta" << endl;
    cout << "5 - Pesquisar uma conta" << endl;
    cout << "6 - Listar todas as contas" << endl;
    cout << "7 - Associar Cartao de Credito a uma Conta" << endl;
    cout << "8 - Adicionar Despesa no Cartao de Credito" << endl;
    cout << "9 - Mostrar Informacoes do Cartao de Credito" << endl;
}

int main() {
    Banco banco;

    int escolha = -1;

    while (escolha != 0) {
        mostrarMenu();
        cin >> escolha;

        switch (escolha) {
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            case 1: {
                int id;
                cout << "Digite o ID da conta: ";
                cin >> id;

                ContaBancaria* conta = banco.pesquisa(id);
                if (conta) {
                    cout << "Saldo Atual: R$" << conta->obterSaldoAtual() << endl;
                } else {
                    cout << "Conta não encontrada." << endl;
                }
                break;
            }
            case 2: {
                int id;
                cout << "Digite o ID da conta: ";
                cin >> id;

                ContaBancaria* conta = banco.pesquisa(id);
                if (conta) {
                    cout << "Historico de transacoes: " << endl;
                    for (const auto& transacao : conta->obterHistoricoTransacoes()) {
                        cout << "- " << transacao.first << ": " << transacao.second << endl;
                    }
                } else {
                    cout << "Conta não encontrada." << endl;
                }
                break;
            }
            case 3: {
                int id;
                cout << "Digite o ID da conta: ";
                cin >> id;

                ContaBancaria* conta = banco.pesquisa(id);
                if (conta) {
                    cout << "Deseja usar saldo ou cartão de crédito? (0 - Saldo, 1 - Cartão de Crédito): ";
                    int opcao;
                    cin >> opcao;
                    double valor;
                    string descricao;

                    cout << "Adicione a Descricao: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, descricao);

                    cout << "Adicione o Valor: R$ ";
                    cin >> valor;

                    if (opcao == 0) {
                        conta->adicionarTransacao(descricao, valor);
                    } else {
                        CartaoDeCredito* cartao = conta->obterCartao();
                        if (cartao) {
                            cartao->adicionarDespesa(valor);
                        } else {
                            cout << "Nenhum cartão de crédito associado." << endl;
                        }
                    }
                } else {
                    cout << "Conta não encontrada." << endl;
                }
                break;
            }
            case 4: {
                int id;
                string cliente;
                cout << "Digite o ID da nova conta: ";
                cin >> id;
                cout << "Digite o nome do cliente: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, cliente);

                ContaBancaria* novaConta = banco.criaConta(id, cliente);
                if (novaConta) {
                    double saldoInicial;
                    cout << "Deseja adicionar um saldo inicial à conta? (0 - Não, 1 - Sim): ";
                    int opcao;
                    cin >> opcao;
                    if (opcao == 1) {
                        cout << "Digite o valor do saldo inicial: R$ ";
                        cin >> saldoInicial;
                        novaConta->adicionarTransacao("Saldo Inicial", saldoInicial);
                    }
                    cout << "Conta criada com sucesso!" << endl;
                } else {
                    cout << "Erro ao criar a conta. ID pode ser duplicado ou o banco está cheio." << endl;
                }
                break;
            }
            case 5: {
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
            case 6:
                banco.listaContas();
                break;
            case 7: {
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
            case 8: {
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
            case 9: {
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
