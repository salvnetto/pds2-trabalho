#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>


class Transacao {
protected:
    std::string data;
    double valor;
    std::string descricao;

public:
    Transacao(std::string data, double valor, std::string descricao) {
        if (valor <= 0) {
            throw std::invalid_argument("O valor da transacao nao pode ser zero ou negativo.");
        }
        this->data = data;
        this->valor = valor;
        this->descricao = descricao;
    }
    virtual ~Transacao() {}

    void setValor(double valor) {
        if (valor <= 0) {
            throw std::invalid_argument("O valor da transacao nao pode ser zero ou negativo.");
        }
        this->valor = valor;
    }

    double getValor() const {
        return valor;
    }

    void setData(std::string data) {
        this->data = data;
    }

    std::string getData() const {
        return data;
    }

    void setDescricao(std::string descricao) {
        this->descricao = descricao;
    }

    std::string getDescricao() const {
        return descricao;
    }

    virtual void relatorio() const = 0;
};

class Despesa : public Transacao {
private:
    std::string nome_cartao;
public:
    Despesa(std::string data, double valor, std::string descricao)
        : Transacao(data, valor, descricao) {}

    void setNomeCartao(std::string nome_cartao){
        this->nome_cartao = nome_cartao;
    }
    void relatorio() const override {
        if (nome_cartao.empty()) { 
            std::cout << "Despesa: " << descricao << " em " << data << " - Valor: " << valor << std::endl;
        }else{
            std::cout << "Despesa: " << descricao << " em " << data << " - Valor: " << valor << ", Cartao de Credito: " << nome_cartao << std::endl;
        }
    }
};

class Receita : public Transacao {
public:
    Receita(std::string data, double valor, std::string descricao)
        : Transacao(data, valor, descricao) {}

    void relatorio() const override {
        std::cout << "Receita: " << descricao << " em " << data << " - Valor: " << valor << std::endl;
    }
};

class CartaoDeCredito {
private:
    std::string nome_cartao;
    double limite;
    double fatura_mensal;
    std::vector<Despesa> despesas;

public:
    CartaoDeCredito(std::string nome_cartao, double limite) {
        if (limite < 0) {
            throw std::invalid_argument("O limite do cartao de credito nao pode ser negativo.");
        }
        this->nome_cartao = nome_cartao;
        this->limite = limite;
        this->fatura_mensal = 0;
    }

    void setNomeCartao(std::string nome_cartao) {
        this->nome_cartao = nome_cartao;
    }

    std::string getNomeCartao() const {
        return nome_cartao;
    }

    void setLimite(double limite) {
        if (limite < 0) {
            throw std::invalid_argument("O limite do cartao de credito nao pode ser negativo.");
        }
        this->limite = limite;
    }

    double getLimite() const {
        return limite;
    }

    Despesa adicionarCompra(std::string data, double valor, std::string descricao) {
        if (valor <= 0) {
            throw std::invalid_argument("O valor da compra deve ser positivo.");
        }
        if (fatura_mensal + valor > limite) {
            throw std::invalid_argument("A compra excede o limite do cartao de credito.");
        }
        Despesa novaDespesa(data, valor, descricao);
        novaDespesa.setNomeCartao(nome_cartao);
        despesas.push_back(novaDespesa);
        fatura_mensal += valor;

        return novaDespesa;
    }

    void pagarFatura(double valor) {
        if (valor <= 0) {
            throw std::invalid_argument("O valor do pagamento deve ser positivo.");
        }
        if (valor > fatura_mensal) {
            throw std::invalid_argument("O pagamento excede a fatura atual.");
        }
        fatura_mensal -= valor;
    }

    void relatorioDespesas() const {
        for (const auto& despesa : despesas) {
            despesa.relatorio();
        }
    }
};

class Conta {
private:
    std::string nome_conta;
    double saldo;
    std::vector<CartaoDeCredito> cartoes_de_credito;
    std::vector<std::unique_ptr<Transacao>> transacoes;

public:
    Conta(std::string nome_conta, double saldo) : nome_conta(nome_conta), saldo(saldo) {
        if (saldo < 0) {
            throw std::invalid_argument("O saldo da conta nao pode ser negativo.");
        }
    }

    void setNomeConta(std::string nome_conta) {
        this->nome_conta = nome_conta;
    }

    std::string getNomeConta() const {
        return nome_conta;
    }

    void setSaldo(double saldo) {
        if (saldo < 0) {
            throw std::invalid_argument("O saldo da conta nao pode ser negativo.");
        }
        this->saldo = saldo;
    }

    void getSaldo() const {
        std::cout << "Saldo da conta: " << saldo << std::endl;
    }

    void adicionarCartaoDeCredito(std::string nome_cartao, double limite) {
        CartaoDeCredito novoCartao(nome_cartao, limite);
        cartoes_de_credito.push_back(novoCartao);
    }

    CartaoDeCredito* encontrarCartaoDeCredito(std::string nome_cartao) {
        for (auto& cartao : cartoes_de_credito) {
            if (cartao.getNomeCartao() == nome_cartao) {
                return &cartao;
            }
        }
        return nullptr;
    }

    void adicionarTransacao(std::string tipo, bool cartao_de_credito, std::string nome_cartao, std::string data, double valor, std::string descricao) {
        if (tipo == "receita") {
            transacoes.push_back(std::make_unique<Receita>(data, valor, descricao));
            saldo += valor;
        } else if (tipo == "despesa") {
            if (cartao_de_credito) {
                CartaoDeCredito* cartao = encontrarCartaoDeCredito(nome_cartao);
                if (cartao) {
                    Despesa despesa = cartao->adicionarCompra(data, valor, descricao);
                    transacoes.push_back(std::make_unique<Despesa>(despesa));
                } else {
                    throw std::invalid_argument("Cartao de credito nao encontrado.");
                }
            } else {
                transacoes.push_back(std::make_unique<Despesa>(data, valor, descricao));
                saldo -= valor;
            }
        } else {
            throw std::invalid_argument("Tipo de transacao invalido, por favor use: 'receita' ou 'despesa'");
        }
    }

    void excluirCartaoDeCredito(std::string nome_cartao) {
        auto it = std::find_if(cartoes_de_credito.begin(), cartoes_de_credito.end(),
            [&nome_cartao](const CartaoDeCredito& cartao) {
                return cartao.getNomeCartao() == nome_cartao;
            });

        if (it != cartoes_de_credito.end()) {
            cartoes_de_credito.erase(it);
        } else {
            throw std::invalid_argument("Cartao de credito nao encontrado: " + nome_cartao);
        }
    }

    void getHistoricoDeTransacoes() const {
        std::cout << "Histórico de transacões para '" << nome_conta << "':" << std::endl;
        for (const auto& transacao : transacoes) {
            transacao->relatorio();
        }
    }
    void getHistoricoDeTransacoesCartaoDeCredito() const {
        for (const auto& cartao : cartoes_de_credito) {
            std::cout << "Nome do Cartao: " << cartao.getNomeCartao() << std::endl;
            std::cout << "Histórico de Transacões:\n";
            cartao.relatorioDespesas();
            std::cout << std::endl;
        }
    }
};

class Usuario{
private:
    std::string nome_usuario;
    std::string senha;
    std::vector<std::unique_ptr<Conta>> contas;
public:
    Usuario(std::string nome_usuario, std::string senha) : nome_usuario(nome_usuario), senha(senha) {}
    Usuario(const Usuario& outro) : nome_usuario(outro.nome_usuario), senha(outro.senha) {}
    ~Usuario() {}

    void setNomeUsuario(std::string nome_usuario){
        this->nome_usuario = nome_usuario;
    }
    std::string getNomeUsuario() const {
        return nome_usuario;
    }

    bool validarSenha(const std::string& senha_digitada) const {
        return senha == senha_digitada;
    }

    void adicionarContaBancaria(std::string nome_conta, double saldo){
        auto nova_conta = std::make_unique<Conta>(nome_conta, saldo);
        contas.push_back(std::move(nova_conta));
    }
    Conta* encontrarContaBancaria(std::string nome_conta) {
        for (auto& conta : contas) {
            if (conta->getNomeConta() == nome_conta) {
                return conta.get();
            }
        }
        return nullptr;
    }
};


#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <sstream>
#include <map>


void menuTransacoes(Conta& minhaConta) {
    int escolha;
    while (true) {
        try {
            std::cout << "\nMenu de Transacões:\n";
            std::cout << "1. Adicionar Despesa\n";
            std::cout << "2. Adicionar Depósito\n";
            std::cout << "3. Ver Histórico de Transacões\n";
            std::cout << "4. Voltar\n";
            std::cout << "Escolha uma opcao: ";

            std::cin >> escolha;

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
            std::cout << "\nMenu de Cartões de Credito:\n";
            std::cout << "1. Adicionar Cartao\n";
            std::cout << "2. Remover Cartao\n";
            std::cout << "3. Ver Histórico de Transacões do Cartao\n";
            std::cout << "4. Pagar Fatura\n";
            std::cout << "5. Voltar\n";
            std::cout << "Escolha uma opcao: ";

            std::cin >> escolha;

            switch (escolha) {
                case 1: {
                    std::string nomeCartao;
                    double limite;
                    std::cout << "\nAdicionar Cartao\n";
                    std::cout << "Nome do Cartao: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, nomeCartao);
                    std::cout << "Limite do Cartao: ";
                    std::cin >> limite;
                    minhaConta.adicionarCartaoDeCredito(nomeCartao, limite);
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
            std::cout << "\nMenu Principal:\n";
            std::cout << "1. Transacões\n";
            std::cout << "2. Cartões de Credito\n";
            std::cout << "3. Saldo da Conta\n";
            std::cout << "4. Sair\n";
            std::cout << "Escolha uma opcao: ";
            std::cin >> escolha;

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
            std::cout << "\nSelecione uma Conta Bancaria:\n";
            std::cout << "1. Selecionar conta\n";
            std::cout << "2. Criar conta\n";
            std::cout << "3. Sair\n";
            std::cout << "Escolha uma opcao: ";
            std::cin >> escolha;

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
            std::cout << "\nBem-vindo:\n";
            std::cout << "1. Log In\n";
            std::cout << "2. Cadastrar\n";
            std::cout << "3. Sair\n";
            std::cout << "Escolha uma opcao: ";
            std::cin >> escolha;

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
                        if (usuario.getNomeUsuario() == nome_usuario && usuario.validarSenha(senha)) {
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
                    std::cout << "Senha: ";
                    std::cin >> senha;
                    {
                        Usuario novo_usuario(nome_usuario, senha);
                        usuarios.push_back(novo_usuario);
                    }
                    break;
                case 3:
                    std::cout << "Saindo...\n";
                    return 0;
                default:
                    std::cout << "Opcao invalida! Por favor, tente novamente.\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Erro: " << e.what() << std::endl;
        }
    }
    return 0;
}
                   
                   
