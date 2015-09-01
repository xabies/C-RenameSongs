/* 
 * File:   Herramientas.cpp
 * Author: xabi
 * 
 * Created on 24 de junio de 2013, 19:46
 */

#include "Herramientas.h"

using namespace std;

Herramientas::Herramientas() {
}

Herramientas::Herramientas(const Herramientas& orig) {
}

Herramientas::~Herramientas() {
}

list<std::string> Herramientas::listarCanciones(char* directorio) {
    list<std::string> listaCanciones;


    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(directorio)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            string aux = ent->d_name;
            if (aux.find(".mp3") != string::npos) {
                string ss = string(directorio) + string("/") + aux;
                listaCanciones.push_back(ss);
            }
        }
        closedir(dir);
    }

    return listaCanciones;
}


