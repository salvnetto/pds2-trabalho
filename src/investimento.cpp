#include "investimento.h"

Investimento::Investimento(std::string nome, double valorAtual, double valorInicial, double taxaRetorno) {
    this->nome = nome;
    this->valorAtual = valorAtual;
    this->valorInicial = valorInicial;
    this->taxaRetorno = taxaRetorno;
}

Investimento::~Investimento() {}

std::string Investimento::getNome() const {
    return nome;
}

double Investimento::getValorAtual() {
    valorAtual += valorAtual * taxaRetorno;
    return valorAtual;
}

double Investimento::getValorInicial() const {
    return valorInicial;
}

double Investimento::getTaxaRetorno() const {
    return taxaRetorno;
}

double Investimento::calcularLucroTotal() const {
    return (valorAtual - valorInicial);
}
