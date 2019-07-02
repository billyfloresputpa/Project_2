//
// Created by ruben on 6/10/19.
//

#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include"Tierra.h"

using namespace std;

enum class Opciones { Agregar=1, Remover, Mostrar, Buscar, Mover};


void limpiar() {
    cout << "\033[2J\033[0;0H";
}

void esperar() {
    char w;
    do {
         w = input<TipoCaracter>("Presione C y Enter para continuar...");
    }while (toupper(w) != 'C');
}

void Menu::imprimirMenu() {
    limpiar();
    cout << "MENU\n";
    cout << string(4, '-') << "\n\n";
    cout << "1. Agregar un nuevo objeto\n";
    cout << "2. Remover objeto\n";
    cout << "3. Dibujar Mapa\n";
    cout<< "4. Buscar Robot\n";
    cout<<" 5. Mover Objeto\n\n";
    cout << "0. Para Salir\n\n";
}


void Menu::agregarObjeto() {
    TipoEntero cont,x,y;
    TipoString nombre;
    TipoCaracter color;
    do{
        cont=0;
        nombre = input<TipoString>("Ingrese Nombre : ");
        for(auto &item : tierra.objetos)
        {
            cont+=item->getNombre()==nombre;
        }
    }while(cont!=0);

    do{
        cont=0;
        color  = input<TipoCaracter>("Ingrese color (Un caracter): ");
        for(auto &item : tierra.objetos)
        {
            cont+=item->getColor()== color;
        }
    }while(cont!=0);

    do{
        cont=0;
        x = input<TipoEntero>("Ingrese posicion X : ");


        while (x < 0 || x >= tierra.getAncho()) {
            cout << "Posicion X Incorrecta, los limites son: 0, "
                 << tierra.getAncho() - 1 << "\n";
            x = input<TipoEntero>("Ingrese posicion X : ");
        }

        y = input<TipoEntero>("Ingrese posicion Y : ");
        while (y < 0 || y >= tierra.getAncho()) {
            cout  << "Posicion Y Incorrecta, los limites son: 0, "
                  << tierra.getAltura() - 1 << "\n";
            y = input<TipoEntero>("Ingrese posicion Y : ");
        }
        for(auto &item : tierra.objetos)
        {
            cont+=item->getPosX()==x && item->getPosY()==y;
        }
    }while(cont!=0);

    tierra.adicionarObjeto(new Objeto(nombre, color, x, y));
}

void Menu::removerObjeto() {
    auto nombre = input<TipoString>("Ingrese Nombre: ");

    Objeto* obj = tierra.removerObjeto(nombre);
    if (obj == nullptr) {
        cout << "Objeto No existe\n";
    }
    else {
        delete obj;
        cout << "Objeto: " << nombre << " ha sido removido\n";
    }
    esperar();
}

void Menu::dibujarMapa() {
    limpiar();
    tierra.actualizarTierra();
    tierra.dibujarTierra();
    cout << '\n';
    tierra.imprimirObjetos();
    cout << '\n';
    esperar();
}

void Menu::ejecutar() {
    generaobstaculos(numobstaculos);
    do {
        imprimirMenu();
        cin >> opcion;
        seleccionarOpcion();
    } while (opcion != 0);
    cout << "Fin del programa...\n";
}

void Menu::generaobstaculos (int numobstaculos)
{
    TipoEntero x,y,cont;
    srand(time(nullptr));
    for (TipoEntero i=0; i<numobstaculos;i++)
    {
        do{
            cont=0;
            x = rand() % (ANCHO);
            y = rand() % (ALTURA);
            for(auto &item : tierra.objetos)
            {
                cont+=item->getPosX()==x && item->getPosY()==y;
            }
        }while(cont!=0);
        tierra.adicionarObjeto(new Objeto("Obstaculo", '@', x, y));
    }
}

void Menu::buscarObjeto()
{
    TipoEntero cont=0;
    TipoString nombre=input<TipoString>("Ingrese Nombre del Robot a Buscar");
    for(auto & item: tierra.objetos)
    {
        if(nombre==item->getNombre())
        {
            cont+=1;
            cout<<nombre<<" encontrado con posición "<<item->getPosX()<<" en X y "<<item->getPosY()<<" en Y"<<endl;
            break;
        }
    }
    if(cont==0)
        cout<<"No existe ningún robot con el nombre "<<nombre<<endl;
}

void Menu::moverobjeto() {
    TipoEntero cont = 0,x,y;
    TipoCaracter color;
    TipoString nombre = input<TipoString>("Ingrese Nombre del Robot a mover");
    for (auto &item: tierra.objetos) {
        if (nombre == item->getNombre()) {
            cont = 1;
            break;
        }

    }
    if (cont==1)
    {
            x = input<TipoEntero>("Ingrese nueva posicion X : ");

            y = input<TipoEntero>("Ingrese nueva posicion Y : ");
        for(auto &item : tierra.objetos) {
            cont += item->getPosX() == x && item->getPosY() == y;
        }

    tierra.adicionarObjeto(new Objeto(nombre, color, x, y));
    }
}


void Menu::seleccionarOpcion() {
    limpiar();
    switch(Opciones(opcion)) {
      case Opciones::Agregar:  // Agregar Objeto
            agregarObjeto();
            break;
      case Opciones::Remover:  // Remover Objeto
            removerObjeto();
            break;
      case  Opciones::Mostrar: // Dibujando Tierra
            dibujarMapa();
            break;
      case Opciones::Buscar: //Buscando Objeto
            buscarObjeto();
            break;
      case Opciones::Mover: //Mover Objeto
            moverobjeto();
            break;
    }
}

