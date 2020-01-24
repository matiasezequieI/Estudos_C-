/*
9- Abrir o arquivo ‘/tmp/resultado.txt’ e mostrar na tela o resultado (se possível em formato JSON).
*/

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream f("/tmp/resultado.txt");

    if (f.is_open())
        std::cout << f.rdbuf();
}