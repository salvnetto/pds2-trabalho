<<<<<<< HEAD:src/orcamento.cpp
#include "orcamento.hpp"
=======
#include "metas.h"
>>>>>>> 316f9403b62fc1581f44ab1a99ce9fcb3a15edda:src/metas.cpp

MetaEconomia::MetaEconomia(std::string obj, double alvo, double atual)
    : objetivo(obj), valorAlvo(alvo), valorAtual(atual) {}

std::string MetaEconomia::getObjetivo() const {
    return objetivo;
}

double MetaEconomia::getValorAlvo() const {
    return valorAlvo;
}

double MetaEconomia::getValorAtual() const {
    return valorAtual;
}

void MetaEconomia::setValorAtual(double valor) {
    valorAtual = valor;
}

double MetaEconomia::progresso() const {
    if (valorAlvo == 0) {
        return 0;
    } else {
        return (valorAtual / valorAlvo) * 100.0;
    }
}
