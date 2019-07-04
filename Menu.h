//
// Created by ruben on 6/10/19.
//

#ifndef AGREGACION_MENU_H
#define AGREGACION_MENU_H


#include "Tierra.h"
#include "Tipos.h"

const TipoEntero numobstaculos = 10;
template <typename T>
T input(string label) {
  T value;
  cout << label;
  cin >> value;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  return value;
}

/*
//--- Esta seria la funcion para leer un string,
//--- esta funcion si se quiere generalizar para colocar un label
//--- y leer cualquier tipo de dato se tendria que convertir al template anterior

string&& input(string label) {
  string value;
  cout << label;
  cin >> value;
  return move(value);
}
 */


class Menu {
    TipoEntero opcion;
    Tierra tierra;
    void imprimirMenu();
    void seleccionarOpcion();
    void agregarObjeto();
    void removerObjeto();
    void dibujarMapa();
    void generaobstaculos(TipoEntero);
    void buscarObjeto();
    void moverobjeto();
    void ingresaBoss();
    void crecerObjeto();
public:
    Menu(): opcion{} {}
    void ejecutar();
};

#endif //AGREGACION_MENU_H

