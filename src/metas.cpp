#include <iostream>
#include <fstream>

#include <Metas.hpp>


void Metas::definirMetas() {
    std::ofstream arquivo("metas.txt");
    if (arquivo.is_open()) {
        std::string meta;
        std::cout << "Digite suas metas de economia, (primeiro o valor, depois sua descrição) (digite FIM para encerrar):\n";
        while (true) {
            std::getline(std::cin, meta);
            if (meta == "FIM")
                break;
            arquivo << meta << std::endl;
        }
        std::cout << "Metas salvas no arquivo metas.txt.\n";
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo.\n";
    }
}
