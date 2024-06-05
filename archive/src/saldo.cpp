#include "Saldo.hpp"
#include <iostream>

Saldo::Saldo(double saldo_inicial) : saldo_atual(saldo_inicial) {}

double Saldo::obter_saldo_atual() const {
    return saldo_atual;
}

void Saldo::adicionar_transacao(const std::string& descricao, double valor) {
    if ((saldo_atual + valor) < 0) {
        std::cout << "ERRO: Valor a ser debitado é maior que o saldo atual" << std::endl;
    } else {
        saldo_atual += valor;
        historico_transacoes[descricao] = valor;
    }
}

const std::map<std::string, double>& Saldo::obter_historico_transacoes() const {
    return historico_transacoes;
}
