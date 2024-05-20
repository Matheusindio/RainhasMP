/*Aqui o código principal*/

#include <iostream>
#include <fstream>

using namespace std;

/*Função VerificaTabuleiro verifica se o tabuleiro é válido, retornando -11 se o arquivo tem problema, -1 se é um tabuleiro inválido e 0 se é válido*/
int VerificaTabuleiro() {
    ifstream myinput;
    myinput.open("myinput", ios::in) 
    if (!myinput) {
        return -11;
    }

}