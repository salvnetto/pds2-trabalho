#include <iostream>
#include <fstream>
#include <limits>

#include <Metas.hpp>


 void Metas::definirMetas() {
        std::ofstream arquivo("./build/metas.txt", std::ios_base::app); // continua se arquivo existir
        if (arquivo.is_open()) {
            std::string meta;
            std::cout << "Digite suas metas de economia, (digite FIM para encerrar):\n";
            while (true) {
                double valor;
                std::string descricao;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Descricao da meta: ";
                std::getline(std::cin, descricao);

                if (descricao == "FIM")
                    break;

                std::cout << "Valor da meta (R$): ";
                std::cin >> valor;

                arquivo <<"- " << descricao << ": " << valor << std::endl;
            }
            std::cout << "Metas salvas no arquivo metas.txt.\n";
            arquivo.close();
        } else {
            std::cout << "Criando novo arquivo...";
            std::ofstream novoArquivo("./build/metas.txt"); // cria arquivo se n existir
            if (novoArquivo.is_open()) {
                std::string meta;
                std::cout << "Digite suas metas de economia, (primeiro o valor, depois sua descricao) (digite FIM para encerrar):\n";
                while (true) {
                double valor;
                std::string descricao;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Descricao da meta: ";
                std::getline(std::cin, descricao);

                if (descricao == "FIM")
                    break;

                std::cout << "Valor da meta (R$): ";
                std::cin >> valor;

                arquivo <<"- " << descricao << ": " << valor << std::endl;
            }
                std::cout << "Metas salvas no novo arquivo metas.txt.\n";
                novoArquivo.close();
            } else {
                std::cerr << "Erro ao criar o arquivo.\n";
            }
        }
 }