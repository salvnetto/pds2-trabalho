<<<<<<<< HEAD:include/orcamento.hpp
#ifndef ORCAMENTO_HPP
#define ORCAMENTO_HPP
========
#ifndef METAS_H
#define METAS_H
>>>>>>>> 316f9403b62fc1581f44ab1a99ce9fcb3a15edda:include/metas.h

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

#endif // METAS_H
