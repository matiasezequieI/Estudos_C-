/*
6- Listar as rotas de rede do servidor usando o comando ‘route -n’. Deverá mostrar como resultado na tela somente os seguintes campos: Destino, Mascara e Interface.
Dica: leia sobre o find e string::npos e substr e popen.
*/
#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{

    const int MAX_BUFFER = 2048;
    char buffer[MAX_BUFFER];
    int count = 0;
    string destino, mascara, interface;
    int destinationFind = 0;
    int mascaraFind = 0;
    int interfaceFind = 0;

    string arq;
    string command = "route -n";

    FILE* stream = popen(command.c_str(), "r");

    if (stream)
    {
        while (!feof(stream))
        {
            if (fgets(buffer, 99, stream) != NULL)
            {
                arq = buffer;
                count++;

                if (count == 2)
                {

                    destinationFind = arq.find("Destination");
                    mascaraFind = arq.find("Genmask");
                    interfaceFind = arq.find("Iface");
                    destino = arq.substr(destinationFind, 14);
                    mascara = arq.substr(mascaraFind, 13);
                    interface = arq.substr(interfaceFind, 5);
                    cout << destino << " " << mascara << " " << interface << endl;
                }
                else if (count == 3)
                {
                    destino = arq.substr(destinationFind, 14);
                    mascara = arq.substr(mascaraFind, 13);
                    interface = arq.substr(interfaceFind, 6);
                    cout << destino << " " << mascara << " " << interface << endl;
                }
                else if (count == 4)
                {
                    destino = arq.substr(destinationFind, 14);
                    mascara = arq.substr(mascaraFind, 13);
                    interface = arq.substr(interfaceFind, 6);
                    cout << destino << " " << mascara << " " << interface << endl;
                }
                else if (count == 5)
                {
                    destino = arq.substr(destinationFind, 14);
                    mascara = arq.substr(mascaraFind, 13);
                    interface = arq.substr(interfaceFind, 6);
                    cout << destino << " " << mascara << " " << interface << endl;
                }
                else if (count == 6)
                {
                    destino = arq.substr(destinationFind, 14);
                    mascara = arq.substr(mascaraFind, 13);
                    interface = arq.substr(interfaceFind, 6);
                    cout << destino << " " << mascara << " " << interface << endl;
                }
            }
        }

        pclose(stream);
    }

    return 0;
}