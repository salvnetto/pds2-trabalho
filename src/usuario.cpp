#include "usuario.h"
#include <stdexcept>

Usuario::Usuario(std::string nome_usuario, std::string senha) : nome_usuario(nome_usuario), senha(senha) {}

Usuario::Usuario(const Usuario& outro) : nome_usuario(outro.nome_usuario), senha(outro.senha) {}

Usuario::~Usuario() {}

void Usuario::setNomeUsuario(std::string nome_usuario) {
    this->nome_usuario = nome_usuario;
}

std::string Usuario::getNomeUsuario() const {
    return nome_usuario;
}

bool Usuario::validarSenha(const std::string& senha_digitada) const {
    return senha == senha_digitada;
}

void Usuario::adicionarContaBancaria(std::string nome_conta, double saldo) {
    auto nova_conta = std::make_unique<Conta>(nome_conta, saldo);
    contas.push_back(std::move(nova_conta));
}

Conta* Usuario::encontrarContaBancaria(std::string nome_conta) {
    for (auto& conta : contas) {
        if (conta->getNomeConta() == nome_conta) {
            return conta.get();
        }
    }
    return nullptr;
}
