#include "transacao.h"

// Implementação da classe Transacao
Transacao::Transacao(std::string data, double valor, std::string descricao) {
    if (valor <= 0) {
        throw std::invalid_argument("O valor da transacao nao pode ser zero ou negativo.");
    }
    this->data = data;
    this->valor = valor;
    this->descricao = descricao;
}

Transacao::~Transacao() {}

void Transacao::setValor(double valor) {
    if (valor <= 0) {
        throw std::invalid_argument("O valor da transacao nao pode ser zero ou negativo.");
    }
    this->valor = valor;
}

double Transacao::getValor() const {
    return valor;
}

void Transacao::setData(std::string data) {
    this->data = data;
}

std::string Transacao::getData() const {
    return data;
}

void Transacao::setDescricao(std::string descricao) {
    this->descricao = descricao;
}

std::string Transacao::getDescricao() const {
    return descricao;
}

// Implementação da classe Despesa
Despesa::Despesa(std::string data, double valor, std::string descricao)
    : Transacao(data, valor, descricao) {}

void Despesa::setNomeCartao(std::string nome_cartao) {
    this->nome_cartao = nome_cartao;
}

void Despesa::relatorio() const {
    if (nome_cartao.empty()) { 
        std::cout << "Despesa: " << descricao << " em " << data << " - Valor: " << valor << std::endl;
    } else {
        std::cout << "Despesa: " << descricao << " em " << data << " - Valor: " << valor << ", Cartao de Credito: " << nome_cartao << std::endl;
    }
}

// Implementação da classe Receita
Receita::Receita(std::string data, double valor, std::string descricao)
    : Transacao(data, valor, descricao) {}

void Receita::relatorio() const {
    std::cout << "Receita: " << descricao << " em " << data << " - Valor: " << valor << std::endl;
}
