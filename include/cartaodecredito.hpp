#ifndef CARTAODECREDITO_HPP
#define CARTAODECREDITO_HPP

#include <string>
#include <vector>

class CartaoDeCredito {
private:
    std::string numero;
    double limite;
    int cvv;
    std::string dataValidade;
    std::vector<double> despesas;

public:
    CartaoDeCredito(std::string numero, double limite, int cvv, std::string dataValidade);
    
    void adicionarDespesa(double valor);
    double somaDespesas() const;
    void imprimirInformacoes() const;
};

#endif
