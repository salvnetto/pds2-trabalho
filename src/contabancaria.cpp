#include "ContaBancaria.hpp"

ContaBancaria::ContaBancaria(int id, const std::string &cliente)
    : id(id), cliente(cliente), saldo(0.0f) {}

void ContaBancaria::imprime() const {
    std::cout << id << " " << cliente << " " << std::fixed << std::setprecision(2) << saldo.obter_saldo_atual() << std::endl;
}

int ContaBancaria::getId() const {
    return id;
}

const std::string& ContaBancaria::getCliente() const {
    return cliente;
}

double ContaBancaria::obterSaldoAtual() const {
    return saldo.obter_saldo_atual();
}

std::map<std::string, double> ContaBancaria::obterHistoricoTransacoes() const {
    return saldo.obter_historico_transacoes();
}

void ContaBancaria::adicionarTransacao(const std::string& descricao, double valor) {
    saldo.adicionar_transacao(descricao, valor);
}

void ContaBancaria::ContaCartao(std::string titular, double saldo){
    this->titular = titular;
    this->saldo.adicionar_transacao("Saldo Inicial", saldo); // Inicializa o saldo
    cartaoDeCredito = nullptr;
}

ContaBancaria::~ContaBancaria() {
    delete cartaoDeCredito;
}

void ContaBancaria::associarCartao(CartaoDeCredito* cartao) {
    if (cartaoDeCredito) {
        delete cartaoDeCredito;
    }
    cartaoDeCredito = cartao;
}

void ContaBancaria::imprimirInformacoes() const {
    std::cout << "Titular: " << titular << std::endl;
    std::cout << "Saldo: " << saldo.obter_saldo_atual() << std::endl;
    if (cartaoDeCredito) {
        cartaoDeCredito->imprimirInformacoes();
    } else {
        std::cout << "Nenhum cartão de crédito associado." << std::endl;
    }
}

CartaoDeCredito* ContaBancaria::obterCartao() const {
    return cartaoDeCredito;
}
