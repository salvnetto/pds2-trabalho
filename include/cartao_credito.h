#ifndef CARTAODECREDITO_H
#define CARTAODECREDITO_H

#include <string>
#include <vector>
#include "transacao.h"

class CartaoDeCredito {
private:
    std::string nome_cartao;
    double limite;
    double fatura_mensal;
    std::vector<Despesa> despesas;

public:
    CartaoDeCredito(std::string nome_cartao, double limite);

    void setNomeCartao(std::string nome_cartao);
    std::string getNomeCartao() const;

    void setLimite(double limite);
    double getLimite() const;

    Despesa adicionarCompra(std::string data, double valor, std::string descricao);
    void pagarFatura(double valor);
    void relatorioDespesas() const;
};

#endif // CARTAODECREDITO_H
