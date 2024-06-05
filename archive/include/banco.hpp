#ifndef BANCO_H
#define BANCO_H

#include "ContaBancaria.hpp"

class Banco {
private:
    int numeroDeContas;
    ContaBancaria* contas[20];

public:
    Banco();
    ~Banco();
    ContaBancaria* criaConta(int id, const std::string &cliente);
    ContaBancaria* pesquisa(int id) const;
    void listaContas() const;
};

#endif
