/*Aqui o código principal*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector;

/*Função VerificaTabuleiro verifica se o tabuleiro é válido, retornando -11 se o arquivo tem problema, -1 se é um tabuleiro inválido e 0 se é válido*/
int VerificaTabuleiro(const std::string& myinput) {
    std::ifstream arquivo(myinput);

    if (!arquivo) {
        return -11;
    }

    int Qletra = 0;
    int Qnume = 0;
    char carac;

    while (arquivo.get(carac)) {
        if (isalpha(carac)) {
            Qletra++;
        } else if (isdigit(carac)) {
            Qnume++;
        }

}
