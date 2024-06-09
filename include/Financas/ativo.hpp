#ifndef ATIVO_HPP
#define ATIVO_HPP

#include <string>

class Ativo {
public:
    virtual ~Ativo() {}
    virtual std::string getNome() const = 0;
    virtual double getValorAtual() = 0;
    virtual double calcularLucroTotal() const = 0;
};

#endif // ATIVO_HPP
