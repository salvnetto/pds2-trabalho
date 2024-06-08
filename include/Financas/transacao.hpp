#ifndef TRANSACOES_HPP
#define TRANSACOES_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Transacao {
protected:
    std::string data;
    double valor;
    std::string descricao;

public:
    Transacao(std::string data, double valor, std::string descricao);
    virtual ~Transacao();

    void setValor(double valor);
    double getValor() const;

    void setData(std::string data);
    std::string getData() const;

    void setDescricao(std::string descricao);
    std::string getDescricao() const;

    virtual void relatorio() const = 0;
};

class Despesa : public Transacao {
private:
    std::string nome_cartao;
public:
    Despesa(std::string data, double valor, std::string descricao);
    void setNomeCartao(std::string nome_cartao);
    void relatorio() const override;
};

class Receita : public Transacao {
public:
    Receita(std::string data, double valor, std::string descricao);
    void relatorio() const override;
};

#endif // TRANSACOES_H
