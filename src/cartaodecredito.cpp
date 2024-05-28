#include "CartaoDeCredito.hpp"
#include <iostream>

CartaoDeCredito::CartaoDeCredito(std::string numero, double limite, int cvv, std::string dataValidade)
    : numero(numero), limite(limite), cvv(cvv), dataValidade(dataValidade) {}

void CartaoDeCredito::adicionarDespesa(double valor) {
    despesas.push_back(valor);
}

double CartaoDeCredito::somaDespesas() const {
    double total = 0;
    for (double despesa : despesas) {
        total += despesa;
    }
    return total;
}

void CartaoDeCredito::imprimirInformacoes() const {
    std::cout << "Número do Cartão: " << numero << std::endl;
    std::cout << "Limite: " << limite << std::endl;
    std::cout << "CVV: " << cvv << std::endl;
    std::cout << "Data de Validade: " << dataValidade << std::endl;
    std::cout << "Total de Despesas: " << somaDespesas() << std::endl;
}

