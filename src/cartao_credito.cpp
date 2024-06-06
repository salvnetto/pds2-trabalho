#include "cartao_credito.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>

CartaoDeCredito::CartaoDeCredito(std::string nome_cartao, double limite, std::string numero_cartao) {
    if (limite < 0) {
        throw std::invalid_argument("O limite do cartao de credito nao pode ser negativo.");
    }
    this->nome_cartao = nome_cartao;
    this->limite = limite;
    this->numero_cartao = numero_cartao;
    this->fatura_mensal = 0;
}
CartaoDeCredito::~CartaoDeCredito(){}

void CartaoDeCredito::setNomeCartao(std::string nome_cartao) {
    this->nome_cartao = nome_cartao;
}

std::string CartaoDeCredito::getNomeCartao() const {
    return nome_cartao;
}

void CartaoDeCredito::setLimite(double limite) {
    if (limite < 0) {
        throw std::invalid_argument("O limite do cartao de credito nao pode ser negativo.");
    }
    this->limite = limite;
}

double CartaoDeCredito::getLimite() const {
    return limite;
}

std::string CartaoDeCredito::getNumeroCartao() const {
    return numero_cartao;
}

Despesa CartaoDeCredito::adicionarCompra(std::string data, double valor, std::string descricao) {
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

void CartaoDeCredito::pagarFatura(double valor) {
    if (valor <= 0) {
        throw std::invalid_argument("O valor do pagamento deve ser positivo.");
    }
    if (valor > fatura_mensal) {
        throw std::invalid_argument("O pagamento excede a fatura atual.");
    }
    fatura_mensal -= valor;
}

void CartaoDeCredito::relatorioDespesas() const {
    for (const auto& despesa : despesas) {
        despesa.relatorio();
    }
}
