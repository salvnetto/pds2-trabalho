#ifndef INVESTIMENTO_HPP
#define INVESTIMENTO_HPP

#include "ativo.hpp"

class Investimento : public Ativo {
public:
    Investimento(std::string nome, double valorAtual, double valorInicial, double taxaRetorno);
    ~Investimento();
    std::string getNome() const override;
    double getValorAtual() override;
    double calcularLucroTotal() const override;

    
    double getValorInicial() const;
    double getTaxaRetorno() const;

private:
    std::string nome;
    double valorAtual;
    double valorInicial;
    double taxaRetorno;
};

#endif // INVESTIMENTO_HPP
