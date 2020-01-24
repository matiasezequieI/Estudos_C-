#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <dirent.h>
#include <errno.h>

using namespace std;

int main(int argc, char *argv[])
{
    char *local = argv[1];
    cout << "diretorio: " << local << " ";

    DIR *dir = opendir(local);

    if (dir)
    {
        cout << "existe\n";
        closedir(dir);
    }
    else if (ENOENT == errno)
    {
        cout << "nao existe\n";
    }
    else
    {
        cout << "nao existe\n";
    }

    return 0;
}
