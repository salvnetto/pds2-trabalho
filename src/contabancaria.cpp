#include "ContaBancaria.hpp"

ContaBancaria::ContaBancaria(int id, const std::string &cliente)
    : id(id), cliente(cliente), saldo(0.0f) {}

void ContaBancaria::imprime() const {
    std::cout << id << " " << cliente << " " << std::fixed << std::setprecision(2) << saldo << std::endl;
}

int ContaBancaria::getId() const {
    return id;
}

const std::string& ContaBancaria::getCliente() const {
    return cliente;
}

float ContaBancaria::getSaldo() const {
    return saldo;
}

ContaBancaria::ContaBancaria(std::string titular, double saldo)
    : titular(titular), saldo(saldo), cartaoDeCredito(nullptr) {}

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
    std::cout << "Saldo: " << saldo << std::endl;
    if (cartaoDeCredito) {
        cartaoDeCredito->imprimirInformacoes();
    } else {
        std::cout << "Nenhum cartão de crédito associado." << std::endl;
    }
}

CartaoDeCredito* ContaBancaria::obterCartao() const {
    return cartaoDeCredito;
}