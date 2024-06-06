#include "conta.h"
#include "investimento.h"
#include <algorithm>

Conta::Conta(std::string nome_conta, double saldo) : nome_conta(nome_conta), saldo(saldo) {
    if (saldo < 0) {
        throw std::invalid_argument("O saldo da conta nao pode ser negativo.");
    }
}
Conta::~Conta(){}

void Conta::setNomeConta(std::string nome_conta) {
    this->nome_conta = nome_conta;
}

std::string Conta::getNomeConta() const {
    return nome_conta;
}

void Conta::setSaldo(double saldo) {
    if (saldo < 0) {
        throw std::invalid_argument("O saldo da conta nao pode ser negativo.");
    }
    this->saldo = saldo;
}

void Conta::getSaldo() const {
    std::cout << "Saldo da conta: " << saldo << std::endl;
}

void Conta::adicionarCartaoDeCredito(std::string nome_cartao, double limite,std::string numero_cartao) {
    CartaoDeCredito novoCartao(nome_cartao, limite,numero_cartao);
    cartoes_de_credito.push_back(novoCartao);
}

CartaoDeCredito* Conta::encontrarCartaoDeCredito(std::string nome_cartao) {
    for (auto& cartao : cartoes_de_credito) {
        if (cartao.getNomeCartao() == nome_cartao) {
            return &cartao;
        }
    }
    return nullptr;
}

void Conta::adicionarTransacao(std::string tipo, bool cartao_de_credito, std::string nome_cartao, std::string data, double valor, std::string descricao) {
    if (tipo == "receita") {
        transacoes.push_back(std::make_unique<Receita>(data, valor, descricao));
        saldo += valor;
    } else if (tipo == "despesa") {
        if (cartao_de_credito) {
            CartaoDeCredito* cartao = encontrarCartaoDeCredito(nome_cartao);
            if (cartao) {
                Despesa despesa = cartao->adicionarCompra(data, valor, descricao);
                transacoes.push_back(std::make_unique<Despesa>(despesa));
            } else {
                throw std::invalid_argument("Cartao de credito nao encontrado.");
            }
        } else {
            transacoes.push_back(std::make_unique<Despesa>(data, valor, descricao));
            saldo -= valor;
        }
    } else {
        throw std::invalid_argument("Tipo de transacao invalido, por favor use: 'receita' ou 'despesa'");
    }
}

void Conta::excluirCartaoDeCredito(std::string nome_cartao) {
    auto it = std::find_if(cartoes_de_credito.begin(), cartoes_de_credito.end(),
        [&nome_cartao](const CartaoDeCredito& cartao) {
            return cartao.getNomeCartao() == nome_cartao;
        });

    if (it != cartoes_de_credito.end()) {
        cartoes_de_credito.erase(it);
    } else {
        throw std::invalid_argument("Cartao de credito nao encontrado: " + nome_cartao);
    }
}

void Conta::getHistoricoDeTransacoes() const {
    std::cout << "Histórico de transacões para '" << nome_conta << "':" << std::endl;
    for (const auto& transacao : transacoes) {
        transacao->relatorio();
    }
}

void Conta::getHistoricoDeTransacoesCartaoDeCredito() const {
    for (const auto& cartao : cartoes_de_credito) {
        std::cout << "Nome do Cartao: " << cartao.getNomeCartao() << std::endl;
        std::cout << "Histórico de Transacões:\n";
        cartao.relatorioDespesas();
        std::cout << std::endl;
    }
}


void Conta::adicionarInvestimento(std::string nome, double valor_atual, double valor_inicial, double taxa_retorno) {
    Investimento novo_investimento(nome, valor_atual, valor_inicial, taxa_retorno);
    investimentos.push_back(novo_investimento);
}

void Conta::getInvestimentos() {
    std::cout << "\nInvestimentos:\n";
    for (auto& investimento : investimentos) {
        std::cout << "Nome: " << investimento.getNome() << ", Valor Atual: $" << investimento.getValorAtual() << std::endl;
    }
}

void Conta::verLucroTotal() {
    for (auto& investimento : investimentos) {
        std::cout << "Nome: " << investimento.getNome() << ", Lucro Total $" << investimento.calcularLucroTotal() << std::endl;
    }
}


void Conta::adicionarMetaEconomia(std::string obj, double alvo, double atual) {
    MetaEconomia nova_meta(obj, alvo, atual);
    metas_economia.push_back(nova_meta);
}

void Conta::getMetasEconomia() const {
    if (metas_economia.empty()) {
        std::cout << "Nenhuma meta de economia definida.\n";
    } else {
        std::cout << "Metas de Economia:\n";
        for (const auto& meta : metas_economia) {
            std::cout << "Objetivo: " << meta.getObjetivo() << ", Valor Alvo: " << meta.getValorAlvo() << ", Valor Atual: " << meta.getValorAtual() << std::endl;
        }
    }
}

void Conta::atualizarValorAtualMetaEconomia(const std::string& objetivo, double novoValorAtual) {
    for (auto& meta : metas_economia) {
        if (meta.getObjetivo() == objetivo) {
            meta.setValorAtual(novoValorAtual);
            std::cout << "Valor atual da meta '" << objetivo << "' atualizado para " << novoValorAtual << ".\n";
            return;
        }
    }
    std::cout << "Meta de economia com o objetivo '" << objetivo << "' nao encontrada.\n";
}