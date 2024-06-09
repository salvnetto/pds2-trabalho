#ifndef ACAO_HPP
#define ACAO_HPP

#include "investimento.hpp"

class Acao : public Investimento {
public:
    Acao(std::string nome, double valorAtual, double valorInicial, double taxaRetorno, std::string ticker);
    std::string getTicker() const;

private:
    std::string ticker;
};

#endif // ACAO_HPP
