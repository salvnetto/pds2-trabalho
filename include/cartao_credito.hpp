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
    //1 = visa
    //2 = mastercard etc

public:
    CartaoDeCredito(std::string nome_cartao, double limite, std::string numero_cartao);
    ~CartaoDeCredito();

    void setNomeCartao(std::string nome_cartao);
    std::string getNomeCartao() const;

    void setLimite(double limite);
    double getLimite() const;

    std::string getNumeroCartao() const;

    Despesa adicionarCompra(std::string data, double valor, std::string descricao);
    void pagarFatura(double valor);
    void relatorioDespesas() const;
};
//Pode fazer, de alguma forma, de cada tipo de cartao ter uma forma diferente de validar o

class Visa : public CartaoDeCredito{
public:

};
class MasterCard : public CartaoDeCredito{
public:

};
class Elo : public CartaoDeCredito{
public:

};
#endif // CARTAODECREDITO_H
