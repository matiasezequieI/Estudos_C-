/*
5- Abrir um arquivo e imprimir o conteúdo dele na tela. Passar por parâmetro em linha de comando o nome do arquivo e o número de linhas que deseja imprimir.
Dica: leia sobre cout.
*/

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    string text;
    char *arq = argv[1];
    char *n = argv[2];

    int num = atoi(n);

    ifstream myfile(arq);

    for (int i = 0; i < num; i++)
    {
        getline(myfile, text);
        cout << text << endl;
    }

    return 0;
}


