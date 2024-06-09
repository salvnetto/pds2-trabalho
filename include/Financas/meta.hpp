#ifndef META_HPP
#define META_HPP

#include <string>

class Meta {
public:
    virtual ~Meta() {}
    virtual std::string getObjetivo() const = 0;
    virtual double getValorAlvo() const = 0;
    virtual double getValorAtual() const = 0;
    virtual void setValorAtual(double valor) = 0;
    virtual double progresso() const = 0;
};

#endif // META_HPP
