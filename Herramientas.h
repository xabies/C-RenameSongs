/* 
 * File:   Herramientas.h
 * Author: xabi
 *
 * Created on 24 de junio de 2013, 19:46
 */

#ifndef HERRAMIENTAS_H
#define	HERRAMIENTAS_H


#include <iostream>
#include <dirent.h>
#include <list>
#include <cstdlib>

using namespace std;

class Herramientas {
public:
    Herramientas();
    Herramientas(const Herramientas& orig);
    virtual ~Herramientas();
    static list<std::string> listarCanciones(char *directorio);
private:

};

#endif	/* HERRAMIENTAS_H */

