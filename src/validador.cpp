#include "validador.hpp"
#include <cctype>
#include <regex>

bool Validador::validarNomeUsuario(const std::string& nome_usuario, const std::vector<Usuario>& usuarios) {
    // Verifica se o nome de usuário possui números
    for (char c : nome_usuario) {
        if (std::isdigit(c)) {
            return false;
        }
    }

    // Verifica se o nome de usuário já está registrado
    for (const auto& usuario : usuarios) {
        if (usuario.getNomeUsuario() == nome_usuario) {
            return false;
        }
    }

    return true;
}

bool Validador::validarSenha(const std::string& senha) {
    // Verifica se a senha possui pelo menos uma letra e um número
    bool has_letter = false;
    bool has_digit = false;
    for (char c : senha) {
        if (std::isalpha(c)) {
            has_letter = true;
        }
        if (std::isdigit(c)) {
            has_digit = true;
        }
    }
    return has_letter && has_digit;
}
