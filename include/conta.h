#ifndef CONTA_H
#define CONTA_H

#include <string>
#include <vector>
#include <memory>
#include "cartao_credito.h"
#include "investimento.h"

class Conta {
private:
    std::string nome_conta;
    double saldo;
    std::vector<CartaoDeCredito> cartoes_de_credito;
    std::vector<std::unique_ptr<Transacao>> transacoes;
    std::vector<Investimento> investimentos;

public:
    Conta(std::string nome_conta, double saldo);
    ~Conta();

    void setNomeConta(std::string nome_conta);
    std::string getNomeConta() const;

    void setSaldo(double saldo);
    void getSaldo() const;

    void adicionarCartaoDeCredito(std::string nome_cartao, double limite, std::string numero_cartao);
    CartaoDeCredito* encontrarCartaoDeCredito(std::string nome_cartao);

    void adicionarTransacao(std::string tipo, bool cartao_de_credito, std::string nome_cartao, std::string data, double valor, std::string descricao);

    void excluirCartaoDeCredito(std::string nome_cartao);
    void getHistoricoDeTransacoes() const;
    void getHistoricoDeTransacoesCartaoDeCredito() const;

    void adicionarInvestimento(std::string nome, double valor_atual, double valor_inicial, double taxa_retorno);
    void getInvestimentos();
    void verLucroTotal();

};

#endif // CONTA_H
