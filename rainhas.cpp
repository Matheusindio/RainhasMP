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

// convertendo
    int countLine = 0;
    int countTotal = 0;
    int *arrays[] = {
        arrayLine1, arrayLine2, arrayLine3, arrayLine4,
        arrayLine5, arrayLine6, arrayLine7, arrayLine8};

    vector<string> linhas =
        {linha1, linha2, linha3, linha4, linha5, linha6, linha7, linha8};

    int attackSameLine[8] = {10, 10, 10, 10, 10, 10, 10, 10};

    std::string ataques = ""; //  String para salvat ataques

    for (int i = 0; i < 8; i++)
    {
        //  colocando lista em array de inteiros
        countLine = 0;
        for (int y = 0; y < 8; y++)
        {
            attackSameLine[y] = 10;
        }

        for (int j = 0; j < 8; j++)
        {
            if (linhas[i][j] - '0' == 1 || linhas[i][j] - '0' == 0)
            {
                arrays[i][j] = linhas[i][j] - '0';
                if (arrays[i][j] == 1)
                {
                    countLine += 1;
                    countTotal += 1;
                }
            }
            else
            {
                return -1;
            } //  caracter diferente de 1 e 0
        }

        //  Ataque em linha
        if (countLine >= 2)
        {
            for (int x = 0; x < 8; x++)
            {
                if (arrays[i][x] == 1)
                {
                    for (int a = 0; a < 8; a++)
                    {
                        if (attackSameLine[a] == 10)
                        {
                            attackSameLine[a] = x;
                            break;
                        }
                    }
                }
            }
            for (int b = 0; b < 7; b++)
            {
                if (attackSameLine[b] != 10 && attackSameLine[b + 1] != 10)
                {
                    ataques += std::to_string(i + 1);
                    ataques += ",";
                    ataques += std::to_string(attackSameLine[b] + 1);
                    ataques += "            ";
                    ataques += std::to_string(i + 1);
                    ataques += ",";
                    ataques += std::to_string(attackSameLine[b + 1] + 1);
                    ataques += "\n";
                    valueReturn = 0;
                }
            }
        }
    }

    if (countTotal > 8 || countTotal < 8)
    { //  mais ou menos de 8 rainhas
        return -1;
    }

    //  verificacao colunas
    bool shouldBreak = false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (arrays[i][j] == 1)
            {
                shouldBreak = false;
                for (int y = i; y < 8; y++)
                {
                    for (int x = j; x < 8; x++)
                    {
                        if (arrays[y][x] == 1 && i != y && x == j)
                        {
                            ataques += std::to_string(i + 1);
                            ataques += ",";
                            ataques += std::to_string(j + 1);
                            ataques += "            ";
                            ataques += std::to_string(y + 1);
                            ataques += ",";
                            ataques += std::to_string(x + 1);
                            ataques += "\n";

                            valueReturn = 0;
                            shouldBreak = true;
                            break;
                        }
                    }
                    if (shouldBreak)
                    {
                        break;
                    }
                }
            }
        }
    }

    //  verificacao diagonais direita
    int cont = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (arrays[i][j] == 1)
            {
                cont = 1;
                for (int y = i + 1; y < 8; y++)
                {
                    if (j + cont >= 8)
                    {
                        break;
                    }
                    if (arrays[y][j + cont] == 1)
                    {
                        ataques += std::to_string(i + 1);
                        ataques += ",";
                        ataques += std::to_string(j + 1);
                        ataques += "            ";
                        ataques += std::to_string(y + 1);
                        ataques += ",";
                        ataques += std::to_string(j + cont + 1);
                        ataques += "\n";
                        valueReturn = 0;
                        break;
                    }
                    cont += 1;
                }
            }
        }
    }

    //  verificacao diagonais esquerda
    cont = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (arrays[i][j] == 1)
            {
                cont = 1;
                for (int y = i + 1; y < 8; y++)
                {
                    if (j - cont < 0)
                    {
                        break;
                    }
                    if (arrays[y][j - cont] == 1)
                    {
                        ataques += std::to_string(i + 1);
                        ataques += ",";
                        ataques += std::to_string(j + 1);
                        ataques += "            ";
                        ataques += std::to_string(y + 1);
                        ataques += ",";
                        ataques += std::to_string(j - cont + 1);
                        ataques += "\n";
                        valueReturn = 0;
                        break;
                    }
                    cont += 1;
                }
            }
        }
    }
    if (valueReturn == 0)
    {
        std::string nome = "ataques/ataques - ";
        nome += filename;
        std::string word = "tabuleiros/";
        size_t pos = nome.find(word);
        if (pos != std::string::npos)
        {
            nome.erase(pos, word.length());
        }

        std::ofstream file(nome);
        if (file.is_open())
        {
            file << ataques;
            file.close();
        }
        else
        {
            std::cerr << "Erro ao criar o arquivo: " << nome << std::endl;
        }
    }
    return valueReturn;