/*
8- Com base nas informações do arquivo ‘/etc/passwd’, pegar o código do grupo de cada usuário e busca-lo no arquivo ‘/etc/group’. O resultado deve ser escrito no arquivo ‘/tmp/resultado.txt’ no formato ‘usuario -> codigo -> grupo’.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

struct Pessoa
{
    string nome;
    string codgrupo;
    string nomeGrupo;
};

int main()
{

    typedef std::map<string, string> Grupo; // chave , <Pessoa>  - associa<Pessoa> a string nomeUser;
    map<string, string>::iterator itmap;

    string temp;
    Pessoa user[200];
    int posicaoUser = 0;
    int posicaoGrupo = 0;
    int posicaoidGrupo = 0;
    int posicaoMap = 0;
    string nomeUser;
    Grupo grupo;

    // funcao setar USER NO Struct
    std::ifstream arq("/home/ton/teste/passwd2");
    if (arq.is_open())
    {
        while (getline(arq, nomeUser))
        {
            temp = "";
            for (int i = 0; i < nomeUser.size(); i++)
            {
                if (nomeUser[i] != ':')
                {
                    temp = temp + nomeUser[i];
                }
                else
                {
                    break;
                }
            }
            user[posicaoUser].nome = temp;
            posicaoUser++;
        }
    }
    else
    {
        cout << "Não encontrado!";
    }
    arq.close();

    // FUNÇÂO seta IDGrupo e NomeGrupo no Struct
    const int MAX_BUFFER = 2048;
    char buffer[MAX_BUFFER];
    string temp2;
    int tempFind;
    string tempString;

    string command = "cut -d: -f 1 /home/teste/group2";
    FILE *stream = popen(command.c_str(), "r");

    string command2 = "cut -d: -f 3 /home/teste/group2";
    FILE *stream2 = popen(command2.c_str(), "r");

    while (!feof(stream) && !feof(stream2))
    {

        if (fgets(buffer, MAX_BUFFER, stream) != NULL)
        {
            string arq = buffer;
            user[posicaoGrupo].nomeGrupo = arq;
            posicaoGrupo++;
        }

        if (fgets(buffer, MAX_BUFFER, stream2) != NULL)
        {
            string arq = buffer;
            user[posicaoidGrupo].codgrupo = arq;
            posicaoidGrupo++;
        }
    }
    pclose(stream);
    pclose(stream2);

    // Adiciona dados no MAP
    for (int i = 0; i < posicaoidGrupo; i++)
    {
        grupo.insert(pair<string, string>(user[i].codgrupo, user[i].nomeGrupo));
        posicaoMap++;
    }

    //Find no Map pelo IDgroup
    for (int i = 0; i < posicaoMap; i++)
    {

        string tempMap = user[i].codgrupo;

        itmap = grupo.find(tempMap);
        if (itmap == grupo.end())
        {
            cout << "Falha ao encontrar" << endl;
        }
        else
        {
            std::ofstream result;
            result.open("/tmp/resultado.txt", std::ios::app);
            result << "Usuario: " << user[i].nome << " -> "
                   << "IDGrupo: " << user[i].codgrupo << " -> "
                   << "Nome Grupo:  " << user[i].nomeGrupo << endl;
            result.close();
        }
    }
    return 0;
}