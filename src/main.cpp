#include "usuario.hpp"
#include "validador.hpp"
#include "investimento.hpp"
#include "acao.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <sstream>
#include <map>

void menuMetasEconomia(Conta& minhaConta) {
    int escolha;
    while (true) {
        try {
            std::cout<< "\n===============x===============";
            std::cout << "\nMenu de Metas de Economia:\n";
            std::cout << "1. Adicionar Meta de Economia\n";
            std::cout << "2. Ver Metas de Economia\n";
            std::cout << "3. Atualizar Economia\n";
            std::cout << "4. Ver Progresso das Metas\n";
            std::cout << "5. Voltar\n";
            std::cout << "Escolha uma opcao: ";
            std::cout<< "\n===============x===============\n";

            std::cin >> escolha;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Opcao invalida! Por favor, tente novamente.\n";
                continue;
            }

            std::string objetivo;
            double valorAlvo, valorAtual;           
            switch (escolha) {
                case 1: {
                    std::cout << "\nAdicionar Meta de Economia\n";
                    std::cout << "Objetivo: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, objetivo);
                    std::cout << "Valor Alvo: ";
                    std::cin >> valorAlvo;
                    std::cout << "Valor Atual: ";
                    std::cin >> valorAtual;
                    minhaConta.adicionarMetaEconomia(objetivo, valorAlvo, valorAtual);
                    break;
                }
                case 2: {
                    minhaConta.getMetasEconomia();
                    break;
                }
                case 3: {
                    std::cout << "\nAtualizar Valor da Meta de Economia\n";
                    std::cout << "Objetivo: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, objetivo);
                    std::cout << "Valor Atual: ";
                    std::cin >> valorAtual;
                    minhaConta.atualizarValorAtualMetaEconomia(objetivo, valorAtual);
                    break;
                }
                case 4: {
                    minhaConta.getProgressoMetas();
                    break;
                }
                case 5:
                    return;
                default:
                    std::cout << "Opcao invalida! Por favor, tente novamente.\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << std::endl;
        }
    }
}

void menuInvestimentos(Conta& minhaConta) {
    int escolha;
    while (true) {
        try {
            std::cout<< "\n===============x===============";
            std::cout << "\nMenu de Investimentos:\n";
            std::cout << "1. Adicionar Investimento\n";
            std::cout << "2. Ver Investimentos\n";
            std::cout << "3. Ver Lucro Total\n";
            std::cout << "4. Voltar\n";
            std::cout << "Escolha uma opcao: ";
            std::cout<< "\n===============x===============\n";

            std::cin >> escolha;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Opcao invalida! Por favor, tente novamente.\n";
                continue;
            }

            switch (escolha) {
                case 1: {
                    std::string tipoInvestimento, nome, ticker;
                    double valorAtual, valorInicial, taxaRetorno;
                    std::cout << "\nAdicionar Investimento\n";
                    std::cout << "Tipo de Investimento (Investimento/Acao): ";
                    std::cin >> tipoInvestimento;
                    std::cout << "Nome do Investimento/Acao: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, nome);
                    std::cout << "Valor Atual: ";
                    std::cin >> valorAtual;
                    std::cout << "Valor Inicial: ";
                    std::cin >> valorInicial;
                    std::cout << "Taxa de Retorno (decimal): ";
                    std::cin >> taxaRetorno;
                    if (tipoInvestimento == "Acao") {
                        std::cout << "Ticker: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::getline(std::cin, ticker);
                        minhaConta.adicionarInvestimento(std::make_unique<Acao>(nome, valorAtual, valorInicial, taxaRetorno, ticker));
                    } else {
                        minhaConta.adicionarInvestimento(std::make_unique<Investimento>(nome, valorAtual, valorInicial, taxaRetorno));
                    }
                    break;
                }
                case 2: {
                    minhaConta.getInvestimentos();
                    break;
                }
                case 3: {
                    minhaConta.verLucroTotal();
                    break;
                }
                case 4:
                    return;
                default:
                    std::cout << "Opcao invalida! Por favor, tente novamente.\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << std::endl;
        }
    }
}

void menuTransacoes(Conta& minhaConta) {
    int escolha;
    while (true) {
        try {
            std::cout<< "\n===============x===============";
            std::cout << "\nMenu de Transacões:\n";
            std::cout << "1. Adicionar Despesa\n";
            std::cout << "2. Adicionar Depósito\n";
            std::cout << "3. Ver Histórico de Transacões\n";
            std::cout << "4. Voltar\n";
            std::cout << "Escolha uma opcao: ";
            std::cout<< "\n===============x===============\n";

            std::cin >> escolha;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Opcao invalida! Por favor, tente novamente.\n";
                continue;
            }

            switch (escolha) {
                case 1: {
                    std::string data, descricao, nomeCartao;
                    double valor;
                    char escolhaCartaoCredito;
                    bool usarCartaoCredito;
                    std::cout << "\nAdicionar Despesa\n";
                    std::cout << "Data (AAAA-MM-DD): ";
                    std::cin >> data;
                    std::cout << "Valor: ";
                    std::cin >> valor;
                    std::cout << "Descricao: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, descricao);
                    std::cout << "Usar cartao de credito? (s/n): ";
                    std::cin >> escolhaCartaoCredito;
                    usarCartaoCredito = (escolhaCartaoCredito == 's' || escolhaCartaoCredito == 'S');
                    if (usarCartaoCredito) {
                        std::cout << "Nome do Cartao: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::getline(std::cin, nomeCartao);
                    }
                    minhaConta.adicionarTransacao("despesa", usarCartaoCredito, nomeCartao, data, valor, descricao);
                    break;
                }
                case 2: {
                    std::string data, descricao;
                    double valor;
                    std::cout << "\nAdicionar Depósito\n";
                    std::cout << "Data (AAAA-MM-DD): ";
                    std::cin >> data;
                    std::cout << "Valor: ";
                    std::cin >> valor;
                    std::cout << "Descricao: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, descricao);
                    minhaConta.adicionarTransacao("receita", false, "", data, valor, descricao);
                    break;
                }
                case 3:
                    minhaConta.getHistoricoDeTransacoes();
                    break;
                case 4:
                    return;
                default:
                    std::cout << "Opcao invalida! Por favor, tente novamente.\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << std::endl;
        }
    }
}

void menuCartoesDeCredito(Conta& minhaConta) {
    int escolha;
    while (true) {
        try {
            std::cout<< "\n===============x===============";
            std::cout << "\nMenu de Cartões de Credito:\n";
            std::cout << "1. Adicionar Cartao\n";
            std::cout << "2. Remover Cartao\n";
            std::cout << "3. Ver Histórico de Transacões do Cartao\n";
            std::cout << "4. Pagar Fatura\n";
            std::cout << "5. Voltar\n";
            std::cout << "Escolha uma opcao: ";
            std::cout<< "\n===============x===============\n";

            std::cin >> escolha;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Opcao invalida! Por favor, tente novamente.\n";
                continue;
            }

            switch (escolha) {
                case 1: {
                    std::string nomeCartao;
                    std::string numeroCartao;
                    double limite;
                    std::cout << "\nAdicionar Cartao\n";
                    std::cout << "Nome do Cartao: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, nomeCartao);
                    std::cout << "Numero do Cartao: ";
                    std::getline(std::cin, numeroCartao);
                    std::cout << "Limite do Cartao: ";
                    std::cin >> limite;
                    minhaConta.adicionarCartaoDeCredito(nomeCartao, limite,numeroCartao);
                    break;
                }
                case 2: {
                    std::string nomeCartao;
                    std::cout << "\nRemover Cartao\n";
                    std::cout << "Nome do Cartao: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, nomeCartao);
                    try {
                        minhaConta.excluirCartaoDeCredito(nomeCartao);
                    } catch (const std::invalid_argument& e) {
                        std::cout << "Erro: " << e.what() << std::endl;
                    }
                    break;
                }
                case 3: {
                    minhaConta.getHistoricoDeTransacoesCartaoDeCredito();
                    break;
                }
                case 4: {
                    std::string nomeCartao;
                    double valor;
                    std::cout << "\nPagar Fatura\n";
                    std::cout << "Nome do Cartao: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, nomeCartao);
                    std::cout << "Valor: ";
                    std::cin >> valor;
                    try {
                        CartaoDeCredito* cartao = minhaConta.encontrarCartaoDeCredito(nomeCartao);
                        if (cartao) {
                            cartao->pagarFatura(valor);
                            std::cout << "Fatura paga com sucesso.\n";
                        } else {
                            std::cout << "Cartao de credito nao encontrado.\n";
                        }
                    } catch (const std::invalid_argument& e) {
                        std::cout << "Erro: " << e.what() << std::endl;
                    }
                    break;
                }
                case 5:
                    return;
                default:
                    std::cout << "Opcao invalida! Por favor, tente novamente.\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << std::endl;
        }
    }
}

void menuPrincipal(Conta& minhaConta) {
    int escolha;
    while (true) {
        try {
            std::cout<< "\n===============x===============";
            std::cout << "\nMenu Principal:\n";
            std::cout << "1. Transacões\n";
            std::cout << "2. Cartões de Credito\n";
            std::cout << "3. Saldo da Conta\n";
            std::cout << "4. Investimentos\n";
            std::cout << "5. Metas de Economia\n";
            std::cout << "6. Sair\n";
            std::cout << "Escolha uma opcao: ";
            std::cout<< "\n===============x===============\n";

            std::cin >> escolha;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Opcao invalida! Por favor, tente novamente.\n";
                continue;
            }

            switch (escolha) {
                case 1:
                    menuTransacoes(minhaConta);
                    break;
                case 2:
                    menuCartoesDeCredito(minhaConta);
                    break;
                case 3:
                    minhaConta.getSaldo();
                    break;
                case 4:
                    menuInvestimentos(minhaConta);
                    break;
                case 5:
                    menuMetasEconomia(minhaConta);
                    break;
                case 6:
                    std::cout << "Saindo...\n";
                    return; 
                default:
                    std::cout << "Opcao invalida! Por favor, tente novamente.\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << std::endl;
        }
    }
}

void menuConta(Usuario& usuario) {
    int escolha;
    while (true) {
        try {
            std::cout<< "\n===============x===============";
            std::cout << "\nSelecione uma Conta Bancaria:\n";
            std::cout << "1. Selecionar conta\n";
            std::cout << "2. Criar conta\n";
            std::cout << "3. Mostrar contas disponiveis\n";
            std::cout << "4. Sair\n";
            std::cout << "Escolha uma opcao: ";
            std::cout<< "\n===============x===============\n";
            std::cin >> escolha;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Opcao invalida! Por favor, tente novamente.\n";
                continue;
            }

            std::string conta;
            switch (escolha) {
                case 1:
                    std::cout << "Digite o nome da conta: ";
                    std::cin >> conta;
                    try {
                        Conta* conta_bancaria = usuario.encontrarContaBancaria(conta);
                        if (conta_bancaria) {
                            menuPrincipal(*conta_bancaria);
                        } else {
                            std::cout << "Conta nao encontrada.\n";
                        }
                    } catch (const std::invalid_argument& e) {
                        std::cout << "Erro: " << e.what() << std::endl;
                    }
                    break;
                case 2:
                    double saldo;
                    std::cout << "Digite o nome da conta: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, conta);
                    std::cout << "Digite o saldo da conta: ";
                    std::cin >> saldo;
                    if (usuario.encontrarContaBancaria(conta) == nullptr) {
                        usuario.adicionarContaBancaria(conta, saldo);
                    } else {
                        std::cout << "Nome da conta ja existe. Por favor, escolha outro.\n";
                    }
                    break;
                case 3:
                    usuario.mostrarContaBancaria();
                    break;
                case 4:
                    std::cout << "Saindo...\n";
                    return;
                default:
                    std::cout << "Opcao invalida! Por favor, tente novamente.\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << std::endl;
        }
    }
}

int main() {
    int escolha;
    std::vector<Usuario> usuarios;

    while (true) {
        try {
            std::cout<< "\n===============x===============";
            std::cout << "\nBem-vindo:\n";
            std::cout << "1. Log In\n";
            std::cout << "2. Cadastrar\n";
            std::cout << "3. Sair\n";
            std::cout << "Escolha uma opcao: ";
            std::cout<< "\n===============x===============\n";
            std::cin >> escolha;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Opcao invalida! Por favor, tente novamente.\n";
                continue;
            }

            bool usuario_encontrado = false;
            std::string nome_usuario;
            std::string senha;
            switch (escolha) {
                case 1:
                    std::cout << "\nLog In\n";
                    std::cout << "Nome de Usuario: ";
                    std::cin >> nome_usuario;
                    std::cout << "Senha: ";
                    std::cin >> senha;

                    for (auto& usuario : usuarios) {
                        if (usuario.getNomeUsuario() == Encriptador::encriptar(nome_usuario) && usuario.validarSenha(Encriptador::encriptar(senha))) {
                            std::cout << "Login realizado com sucesso!" << std::endl;
                            menuConta(usuario);
                            usuario_encontrado = true;
                            break;
                        }
                    }
                    if (!usuario_encontrado) {
                        std::cout << "Nome de usuario ou senha invalidos.\n";
                    }
                    break;
                case 2:
                    std::cout << "\nCadastrar\n";
                    std::cout << "Nome de Usuario: ";
                    std::cin >> nome_usuario;
                    if (!Validador::validarNomeUsuario(nome_usuario, usuarios)) {
                        std::cout << "Nome de usuario invalido ou já existe. Lembre de nao usar numeros no nome. \nPor favor, tente novamente.\n";
                        continue;
                    }
                    std::cout << "Senha: ";
                    std::cin >> senha;
                    if (!Validador::validarSenha(senha)) {
                        std::cout << "Senha invalida. A senha deve conter pelo menos uma letra e um numero. Por favor, tente novamente.\n";
                        continue;
                    }
                    nome_usuario = Encriptador::encriptar(nome_usuario);
                    senha = Encriptador::encriptar(senha);
                    usuarios.emplace_back(nome_usuario, senha);
                    std::cout << "Usuario cadastrado com sucesso!\n";
                    break;
                case 3:
                    std::cout << "Saindo...\n";
                    return 0;
                default:
                    std::cout << "Opcao invalida! Por favor, tente novamente.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Erro: " << e.what() << "\n";
        }
    }

    return 0;
}
