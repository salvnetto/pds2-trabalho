#ifndef CARTAODECREDITO_HPP
#define CARTAODECREDITO_HPP

#include <string>
#include <vector>
#include "transacao.hpp"

class CartaoDeCredito {
private:
    std::string nome_cartao;
    double limite;
    double fatura_mensal;
    std::vector<Despesa> despesas;
    std::string numero_cartao;
    int type;
public:
    CartaoDeCredito(std::string nome_cartao, double limite, std::string numero_cartao);
    ~CartaoDeCredito(){};

    void setNomeCartao(std::string nome_cartao);
    std::string getNomeCartao() const;

    void setLimite(double limite);
    double getLimite() const;

    std::string getNumeroCartao() const;

    Despesa adicionarCompra(std::string data, double valor, std::string descricao);
    void pagarFatura(double valor);
    void relatorioDespesas() const;
};
#endif // CARTAODECREDITO_H
