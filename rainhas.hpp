#ifndef RAINHAS_HPP_
#define RAINHAS_HPP_

#include <string>

/**
*verifica_solucao retorna 1 caso seja uma solução para o problema,
0 caso não seja uma solução para o problema,
-1 caso a entradsa não seja válida
filename vai corresponder ao arquivo .txt que tem os tabuleiros
*/
int Verifica_solucao(const std::string& filename);

#endif  // RAINHAS_HPP_
