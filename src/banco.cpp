#include "Banco.hpp"

Banco::Banco() : numeroDeContas(0) {
    for (int i = 0; i < 20; ++i) {
        contas[i] = nullptr;
    }
}

Banco::~Banco() {
    for (int i = 0; i < 20; ++i) {
        delete contas[i];
    }
}

ContaBancaria* Banco::criaConta(int id, const std::string &cliente) {
    if (numeroDeContas >= 20) {
        return nullptr;
    }
    for (int i = 0; i < numeroDeContas; ++i) {
        if (contas[i]->getId() == id) {
            return nullptr;
        }
    }
    contas[numeroDeContas] = new ContaBancaria(id, cliente);
    return contas[numeroDeContas++];
}

ContaBancaria* Banco::pesquisa(int id) const {
    for (int i = 0; i < numeroDeContas; ++i) {
        if (contas[i]->getId() == id) {
            return contas[i];
        }
    }
    return nullptr;
}

void Banco::listaContas() const {
    for (int i = 0; i < numeroDeContas; ++i) {
        contas[i]->imprime();
    }
}
