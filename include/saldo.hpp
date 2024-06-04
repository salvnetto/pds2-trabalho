#ifndef SALDO_H
#define SALDO_H

#include <iostream>
#include <map>
#include <string>

class Saldo {
private:
    double saldo_atual;
    std::map<std::string, double> historico_transacoes;

public:
    Saldo(double saldo_inicial = 0.0);

    double obter_saldo_atual() const;
    void adicionar_transacao(const std::string& descricao, double valor);
    const std::map<std::string, double>& obter_historico_transacoes() const;
};

#endif
