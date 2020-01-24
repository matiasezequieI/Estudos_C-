/*
2- Copie o conteúdo do arquivo '/tmp/exercicio.txt' do exercício anterior, com exceção das linhas que começarem com 'Teste' para o arquivo /home/novo.txt.
Dica: leia sobre o find e string::npos.
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{

    string line, line2;
    string temp = "O_Teste_22";
    string str2 = "Teste";

    ifstream myfile("C://Users/Matias Ezequiel/Desktop/Coding Stuff/Output C++/exercicio.txt"); 

    if (myfile.is_open())
    {
        while (!myfile.eof()) 
        {
            getline(myfile, line);
            //line2 += line;

            if (line.find(str2) == string::npos && line != "\0" && line.find(temp) == string::npos)
            {
                //line2 = line;
                cout << line << endl;

                ofstream newfile;
                newfile.open("C://Users/Matias Ezequiel/Desktop/Coding Stuff/Output C++/novo.txt", ofstream::app);
                newfile << line << "\n";
                newfile.close();
            }
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";

    return 0;
}