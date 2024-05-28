#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <iostream>
#include <string>
#include <iomanip>
#include "CartaoDeCredito.hpp"

class ContaBancaria {
private:
    int id;
    std::string cliente;
    float saldo;
    std::string titular;
    CartaoDeCredito* cartaoDeCredito;

public:
    void associarCartao(CartaoDeCredito* cartao);
    CartaoDeCredito* obterCartao() const;
    void imprimirInformacoes() const;

    ContaBancaria(int id, const std::string &cliente);
    void imprime() const;
    int getId() const;
    const std::string& getCliente() const;
    float getSaldo() const;
    ContaBancaria(std::string titular, double saldo);
    ~ContaBancaria();

};

#endif
