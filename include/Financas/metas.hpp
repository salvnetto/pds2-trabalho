#ifndef METAS_HPP
#define METAS_HPP

#include "meta.hpp"
#include <string>

class MetaEconomia : public Meta {
public:
    MetaEconomia(std::string obj, double alvo, double atual);
    std::string getObjetivo() const override;
    double getValorAlvo() const override;
    double getValorAtual() const override;
    void setValorAtual(double valor) override;
    double progresso() const override;

private:
    std::string objetivo;
    double valorAlvo;
    double valorAtual;
};

#endif // METAS_HPP
