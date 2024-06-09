#include "acao.hpp"

Acao::Acao(std::string nome, double valorAtual, double valorInicial, double taxaRetorno, std::string ticker)
    : Investimento(nome, valorAtual, valorInicial, taxaRetorno), ticker(ticker) {}

std::string Acao::getTicker() const {
    return ticker;
}
