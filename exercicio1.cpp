/*
1- Crie o arquivo ‘exercicio.txt’ dentro do diretório ‘/tmp/’ com o seguinte conteúdo:
Dica: leia sobre o fstream.
*/


#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    fstream myfile;
    myfile.open("C://Users/Matias Ezequiel/Desktop/Coding Stuff/Output C++/exercicio.txt", ios::out);
    myfile << "Teste1\n"
           << "Nome\n"
           << "Teste11\n"
           << "Frase_teste\n"
           << "Teste2\n"
           << "O_Teste_22\n"
           << "XXavg12\n"
           << "54ggg|_aa\n"
           << "Teste13\n"
           << "Xicara\n"
           << "Desenvolvedor\n"
           << "Teste15\n"
           << "Software\n"
           << "Bicicleta\n"
           << "Teste100\n";
    myfile.close();
    return 0;
}
