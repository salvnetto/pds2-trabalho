#ifndef INVESTIMENTO_H
#define INVESTIMENTO_H

#include <iostream>

class Investimento {
private:
    std::string nome;
    double valorAtual;
    double valorInicial;
    double taxaRetorno;

public:
    Investimento(std::string nome, double valorAtual, double valorInicial, double taxaRetorno);
    ~Investimento();

    std::string getNome() const;
    double getValorAtual();
    double getValorInicial() const;
    double getTaxaRetorno() const;

    double calcularLucroTotal() const;
};

#endif