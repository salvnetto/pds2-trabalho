#ifndef VALIDADOR_HPP
#define VALIDADOR_HPP

#include <string>
#include <vector>
#include "usuario.hpp"

class Validador {
public:
    static bool validarNomeUsuario(const std::string& nome_usuario, const std::vector<Usuario>& usuarios);
    static bool validarSenha(const std::string& senha);
};

#endif // VALIDADOR_HPP