/**
*@file testa_rainhas.cpp
*/

#define CATCH_CONFIG_MAIN
#include "rainhas.hpp"
#include "catch.hpp"

/**
* TEST_CASE - casos sem solução
* Verifica_solucao será a função que responderá os requisitos do problema             
*/
TEST_CASE("solucoes invalidas para o problema", "[rainhas]") {
    REQUIRE(Verifica_solucao("teste_8_rainhas.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_13.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_14.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_15.txt") == 0);

    REQUIRE(Verifica_solucao("tabuleiros/teste_1.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_2.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_3.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_4.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_5.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_6.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_7.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_8.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_9.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_10.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_30.txt") == 0);
    REQUIRE(Verifica_solucao("tabuleiros/teste_31.txt") == 0);
}

/**
* TEST_CASE - casos com solução
* 
*/

TEST_CASE("solucoes validas para o problema", "[rainhas]") {
    REQUIRE(Verifica_solucao("tabuleiros/teste_11.txt") == 1);

    REQUIRE(Verifica_solucao("tabuleiros/teste_25.txt") == 1);
    REQUIRE(Verifica_solucao("tabuleiros/teste_26.txt") == 1);
    REQUIRE(Verifica_solucao("tabuleiros/teste_27.txt") == 1);
    REQUIRE(Verifica_solucao("tabuleiros/teste_28.txt") == 1);
    REQUIRE(Verifica_solucao("tabuleiros/teste_28.txt") == 1);
}

/**
* TEST_CASE - casos com invalidez
* 
*/
TEST_CASE("matriz invalida para o problema", "[rainhas]") {
    REQUIRE(Verifica_solucao("tabuleiros/teste_12.txt") == -1);
    REQUIRE(Verifica_solucao("tabuleiros/teste_16.txt") == -1);

    REQUIRE(Verifica_solucao("tabuleiros/teste_17.txt") == -1);
    REQUIRE(Verifica_solucao("tabuleiros/teste_18.txt") == -1);
    REQUIRE(Verifica_solucao("tabuleiros/teste_19.txt") == -1);
    REQUIRE(Verifica_solucao("tabuleiros/teste_20.txt") == -1);
    REQUIRE(Verifica_solucao("tabuleiros/teste_21.txt") == -1);
    REQUIRE(Verifica_solucao("tabuleiros/teste_22.txt") == -1);
    REQUIRE(Verifica_solucao("tabuleiros/teste_23.txt") == -1);
    REQUIRE(Verifica_solucao("tabuleiros/teste_24.txt") == -1);
}
