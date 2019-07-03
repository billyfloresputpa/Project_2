//
// Created by ruben on 6/10/19.
//

#include "Objeto.h"

Objeto::Objeto(): color{}, posX{}, posY{}  {}

Objeto::Objeto(const TipoString& nombre, TipoCaracter color,
               TipoEntero posX, TipoEntero posY):
                                                 nombre{nombre}, color{color},
                                                 posX{posX}, posY{posY} {}
Objeto::Objeto(const TipoString& nombre, TipoCaracter color,
               TipoEntero posX, TipoEntero posY,TipoString state):
        nombre{nombre}, color{color},
        posX{posX}, posY{posY},state{state} {}

Objeto::~Objeto() {}

void Objeto::setNombre(const TipoString& nombre) { this->nombre = nombre; }
void Objeto::moverse(TipoEntero x, TipoEntero y) {} //--  por implementar

TipoString   Objeto::getNombre() { return nombre; }
TipoEntero   Objeto::getPosX()   { return posX; }
TipoEntero   Objeto::getPosY()   { return posY; }
TipoCaracter Objeto::getColor()  { return color; }
TipoEntero Objeto::getTamanoX()  {return tamanox;}
TipoEntero Objeto::getTamanoY()  {return tamanoy;}
TipoString Objeto::getState()    {return state;}
Boss::Boss(const TipoString& nombre, TipoCaracter color,
               TipoEntero posX, TipoEntero posY,TipoEntero tamanox_,TipoEntero tamanoy_):Objeto(nombre, color,posX,posY){
    tamanox=tamanox_;
    tamanoy=tamanoy_;
};

TipoString Objeto::mostrarPosicion() {
    return "X = " + to_string(posX) + " Y = " + to_string(posY);
