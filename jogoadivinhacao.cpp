#include <iostream>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif

void exibirMenu() {
    std::cout << u8"=== Menu do Jogo ===\n";
    std::cout << "1. Iniciar novo jogo\n";
    std::cout << "2. Sair do jogo\n";
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    int opcao;
    do {
        exibirMenu();
        std::cout << "\nEscolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                std::srand(static_cast<unsigned int>(std::time(nullptr)));
                int numeroSorteado = std::rand() % 100 + 1;
                int tentativa, tentativas = 0;

                std::cout << u8"\nBem-vindo ao jogo da adivinhação!\n";
                std::cout << u8"\nTente adivinhar o número entre 1 e 100.\n";

                do {
                    std::cout << u8"\nDigite sua tentativa: ";
                    std::cin >> tentativa;
                    tentativas++;

                    if (tentativa < numeroSorteado) {
                        std::cout << u8"\nTente novamente! O número é maior.\n";
                    } else if (tentativa > numeroSorteado) {
                        std::cout << u8"\nTente novamente! O número é menor.\n";
                    } else {
                        std::cout << u8"\nParabéns! Você acertou o número em " << tentativas << u8" tentativas!\n";
                    }

                } while (tentativa != numeroSorteado);
                break;
            }
            case 2:
                std::cout << u8"\nObrigado por jogar. Até mais!\n";
                break;
            default:
                std::cout << u8"\nOpção inválida. Tente novamente.\n";
        }
    } while (opcao != 2);

    return 0;
}
