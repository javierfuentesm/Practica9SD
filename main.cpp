#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

using namespace std;
char buffer[BUFSIZ];

int main(int argc, char *argv[]) {
    int destino;
    string linea;
/*    if (argc != 2) {
        cout << "Forma de uso: " << argv[0] << " nombre_del_archivo\n";
        exit(0);
    }*/
    string n = "";
    srand(time(NULL));
    int nPalabras = 26*26*26*100;
    for (int i = 0; i < nPalabras; i++) {
        n.push_back(rand() % 26 + 65);
        n.push_back(rand() % 26 + 65);
        n.push_back(rand() % 26 + 65);
        n.push_back(32);
    }
cout << n;
    strcpy(buffer, n.c_str());
//Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
    if ((destino = open("Prueba 3", O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1) {
        perror(argv[1]);
        exit(-1);
    }
    write(destino, buffer, strlen(buffer));
    fsync(destino);
    close(destino);
}
