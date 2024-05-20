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

    if (Qnume != 64 && Qletra != 0) {
        return -1;
    }

    arquivo.close();

    return 1;
}

/*VerificaAtaque vai analisar possíveis ataques entre as rainhas, pelas diagonais, colunas e linhas*/
int VerificaAtaque(const std::string &filename)
{
    if (VerificaTabuleiro(filename) == -1)
    {
        return -1;
    }
    if (VerificaTabuleiro(filename) == -11)
    {
        return -11;
    }