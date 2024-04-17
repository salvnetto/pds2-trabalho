#include "saldo.hpp"



Saldo::Saldo(double saldo_inicial) : saldo_atual(saldo_inicial) {}

double Saldo::obter_saldo_atual() {
    return saldo_atual;
}

void Saldo::adicionar_transacao(std::string descricao, double valor) {
    if((saldo_atual + valor) < 0){
        std::cout << "ERRO: Valor a ser debitado e maior que o saldo atual" << std::endl;
    }else{
        saldo_atual += valor;
        historico_transacoes[descricao] = valor;
    }
}

std::map<std::string, double> Saldo::obter_historico_transacoes() {
    return historico_transacoes;
}

void Saldo::obter_relatorio(){
    if(historico_transacoes.empty()){
        std::cout << "Nenhuma transação registrada.\n";
        return;
    }
    int num_transacoes_pos = 0;
    int num_transacoes_neg = 0;
    double media_gastos,media_ganhos;
    for (const auto& transacao : historico_transacoes) {
        if(transacao.second > 0){
            
            num_transacoes_pos ++;
            media_ganhos += transacao.second;
        }
        if(transacao.second < 0){
            num_transacoes_neg ++;
            media_gastos += transacao.second;
        }
    }
    if(num_transacoes_pos > 0){
        media_ganhos = media_ganhos/num_transacoes_pos;
        std::cout << "Media de valores recebidos: " << media_ganhos << std::endl;
    } else {
        std::cout << "Nenhum valor recebido registrado." << std::endl;
    }
    if(num_transacoes_neg > 0){
        media_gastos = media_gastos/num_transacoes_neg;
        std::cout << "Media de valores gastos: " << media_gastos << std::endl;
    } else{
        std::cout << "Nenhum valor gasto registrado." << std::endl;
    }

    
}