#ifndef ORCAMENTO_H
#define ORCAMENTO_H

#include <string>

class MetaEconomia {
private:
    std::string objetivo;
    double valorAlvo;
    double valorAtual;

public:
    MetaEconomia(std::string obj, double alvo, double atual);

    std::string getObjetivo() const;
    double getValorAlvo() const;
    double getValorAtual() const;

    void setValorAtual(double valor);

    double progresso() const;
};

#endif // ORCAMENTO_H
