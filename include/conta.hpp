#ifndef CONTA_HPP
#define CONTA_HPP

#include <string>
#include <vector>
#include <memory>
<<<<<<< HEAD:include/conta.hpp
#include "cartao_credito.hpp"
#include "investimento.hpp"
#include "orcamento.hpp"
=======
#include "cartao_credito.h"
#include "investimento.h"
#include "metas.h"
>>>>>>> 316f9403b62fc1581f44ab1a99ce9fcb3a15edda:include/conta.h

class Conta {
private:
    std::string nome_conta;
    double saldo;
    std::vector<CartaoDeCredito> cartoes_de_credito;
    std::vector<std::unique_ptr<Transacao>> transacoes;
    std::vector<Investimento> investimentos;
    std::vector<MetaEconomia> metas_economia;

public:
    Conta(std::string nome_conta, double saldo);
    //~Conta();

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

    void adicionarMetaEconomia(std::string obj, double alvo, double atual); 
    void getMetasEconomia() const;
    void atualizarValorAtualMetaEconomia(const std::string& objetivo, double novoValorAtual);
};

#endif // CONTA_H
