/*
3- Testar se um determinado arquivo existe, passando o nome do arquivo por parâmetro em linha de comando, informar na saída do programa ‘Arquivo xxx existe’ ou ‘Arquivo xxx não existe’.
Dica: leia sobre argc e argv.
*/

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    char *local = argv[1];
    cout << "arquivo: " << local << " ";

    cout << local;

    FILE *find = fopen(local, "r");

    if (!find)
    {
        printf("existe");
    }
    else
    {
        printf("nao existe");
    }
    return 0;
}