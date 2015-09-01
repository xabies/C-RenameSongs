#include <cstdlib>
#include <iostream>
#include <dirent.h>
#include <list>
#include "Herramientas.h"
#include <taglib/fileref.h>
#include <cstdio>




using namespace std;

char* string2array(string str);

/*
 * Clase principal del programa
 */
int main(int argc, char** argv) {

    cout << "Mp3Xabi\n\n";


    char *directorio = "/home/xabi/Música";

    cout << "Listando directorio: " << directorio << "\n\n\n";



    list<std::string> listaCanciones;
    list<std::string>::iterator iterador;


    listaCanciones = Herramientas::listarCanciones(directorio);

    for (iterador = listaCanciones.begin(); iterador != listaCanciones.end(); ++iterador) {
        string str = *iterador;


        std::vector<char> buffer(str.length() + 1, '\0');
        std::copy(str.begin(), str.end(), buffer.begin());
        char* fichero = &buffer[0];



        //cout << fichero << "\n";


        TagLib::FileRef f(fichero);

        TagLib::String artist = f.tag()->artist();
        cout << "Artista: " << artist << "\n";

        TagLib::String album = f.tag()->album();
        cout << "Album: " << album << "\n";


        TagLib::String titulo = f.tag()->title();
        cout << "Titulo: " << titulo << "\n\n";

        
        string nombreFinal = directorio + string("/") + artist.toCString(true) + string(" - ") + titulo.toCString(true) + string(".mp3");
        cout << ">>>>>>>>>" << nombreFinal << "\n\n";
        
        rename(fichero,nombreFinal.c_str());

    }


    




    return 0;
}



