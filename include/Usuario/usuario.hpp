#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>
#include <memory>
#include "conta.hpp"

class Usuario {
private:
    std::string nome_usuario;
    std::string senha;
    std::vector<std::unique_ptr<Conta>> contas;

public:
    Usuario(std::string nome_usuario, std::string senha);
    Usuario(const Usuario& outro);
    ~Usuario();

    void setNomeUsuario(std::string nome_usuario);
    std::string getNomeUsuario() const;

    bool validarSenha(const std::string& senha_digitada) const;

    void adicionarContaBancaria(std::string nome_conta, double saldo);
    Conta* encontrarContaBancaria(std::string nome_conta);
    void mostrarContaBancaria();
};

#endif // USUARIO_H
