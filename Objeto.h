//
// Created by ruben on 6/10/19.
//

#ifndef AGREGACION_OBJETO_H
#define AGREGACION_OBJETO_H


#include <iostream>
#include "Tipos.h"

using namespace std;

class Objeto {
private:
    string        nombre;
    TipoCaracter  color;
    TipoEntero    posX;
    TipoEntero    posY;
    TipoString    state="Robot"; //Posibles Estados: Robot,Boss,BossTile,Obstaculo
    TipoEntero    tamanox;
    TipoEntero    tamanoy;
public:
    Objeto();
    Objeto(const TipoString& nombre, TipoCaracter color,
           TipoEntero posX, TipoEntero posY);
    Objeto(const TipoString& nombre, TipoCaracter color,
           TipoEntero posX, TipoEntero posY,TipoString state);
    virtual ~Objeto();
    void setNombre(const TipoString& nombre);
    string     getNombre();
    TipoEntero getPosX();
    TipoEntero getPosY();
    void setPosX(int PosX_){posX=PosX_;};
    void setPosY(int PosY_){posY=PosY_;};
    char getColor();
    void moverse(TipoEntero x, TipoEntero y);
    string mostrarPosicion();
    void setState(string estado){state=estado;};
    TipoString getState();
    TipoEntero getTamanoX();
    TipoEntero getTamanoY();
    };
class Boss:private Objeto {

    TipoEntero tamanox;
    TipoEntero tamanoy;
public:
    Boss (const TipoString& nombre, TipoCaracter color,
          TipoEntero posX, TipoEntero posY,TipoEntero tamanox,TipoEntero tamanoy);
    void setTamanoX(TipoEntero nx){tamanox=nx;};
    void setTamanoY(TipoEntero ny){tamanoy=ny;};
};

#endif //AGREGACION_OBJETO_H
