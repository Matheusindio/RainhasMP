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

    std::ifstream arquivo(filename);

    std::string linha1, linha2, linha3, linha4, linha5, linha6, linha7, linha8;
    std::string linhaExtra;

    if (std::getline(arquivo, linha1) &&
        std::getline(arquivo, linha2) &&
        std::getline(arquivo, linha3) &&
        std::getline(arquivo, linha4) &&
        std::getline(arquivo, linha5) &&
        std::getline(arquivo, linha6) &&
        std::getline(arquivo, linha7) &&
        std::getline(arquivo, linha8) &&
        !std::getline(arquivo, linhaExtra))
    {
    }
    else
    {
        return -1;
    }
    arquivo.close();

    int valueReturn = 1;
    int arrayLine1[8]; 
    int arrayLine2[8];
    int arrayLine3[8];
    int arrayLine4[8];
    int arrayLine5[8]; //  Armazenando os primeiros numeros
    int arrayLine6[8];
    int arrayLine7[8];
    int arrayLine8[8];
