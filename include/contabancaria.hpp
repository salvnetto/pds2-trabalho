#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <iostream>
#include <string>
#include <iomanip>
#include "CartaoDeCredito.hpp"
#include "Saldo.hpp" // Adicionar o include do Saldo

class ContaBancaria {
private:
    int id;
    std::string cliente;
    Saldo saldo; // Adicionar o objeto Saldo
    std::string titular;
    CartaoDeCredito* cartaoDeCredito;

public:
    ContaBancaria(int id, const std::string &cliente);
    void imprime() const;
    int getId() const;
    const std::string& getCliente() const;
    double obterSaldoAtual() const; // Método para obter saldo atual
    std::map<std::string, double> obterHistoricoTransacoes() const; // Método para obter histórico de transações
    void adicionarTransacao(const std::string& descricao, double valor); // Método para adicionar transação
    void ContaCartao(std::string titular, double saldo);
    ~ContaBancaria();

    void associarCartao(CartaoDeCredito* cartao);
    CartaoDeCredito* obterCartao() const;
    void imprimirInformacoes() const;
};

#endif
