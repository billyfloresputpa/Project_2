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

enum class Opciones { Agregar=1, Remover, Mostrar, Buscar, Mover,Boss};


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
    cout<<"5. Mover Objeto\n";
    cout<<"6. Agregar Boss\n\n";
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
        tierra.adicionarObjeto(new Objeto("Obstaculo", '@', x, y,"Obstaculo"));
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
    TipoEntero cont1 = 0,cont2=0,x,y;
    TipoCaracter color;
    TipoString nombre = input<TipoString>("Ingrese Nombre del Robot a mover");
    for (auto &item: tierra.objetos) {
        if (nombre == item->getNombre()) {
            do {
                cont2=0;
                x = input<TipoEntero>("Ingrese nueva posicion X : ");
                y = input<TipoEntero>("Ingrese nueva posicion Y : ");
                for(auto &item2: tierra.objetos) {
                    if (item2->getPosY() == y && item2->getPosX() == x){
                        cont2++;
                    cout << endl << "Ha seleccionado una pocision ocupada" << endl;
                } }

            }while(cont2!=0);
            item->setPosX(x);
            item->setPosY(y);

            cont1 ++;
            break;
        }


    }
    if(cont1==0)
    {
        cout<<"Ese robot no existe";
    }
}



void Menu::ingresaBoss()
{
    TipoEntero x,y,xn,yn,cont=0,cont2=0;
    TipoString nombre;
    TipoCaracter color;
    x = input<TipoEntero>("Ingrese posición X (Esquina superior Izquierda) de Robot Boss : ");
    y = input<TipoEntero>("Ingrese posición Y (Esquina superior Izquierda) de Robot Boss : ");
    xn = input<TipoEntero>("Ingrese el tamaño horizontal del Robot Boss: ");
    yn = input<TipoEntero>("Ingrese el tamaño vertical del Robot Boss");

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


    for(TipoEntero f=y;f<y+yn-1;f++)
    {
        for(TipoEntero c=x;c<x+xn;c++)
        {
            for(auto& item:tierra.objetos)
            {
                if(item->getPosY()==f&&item->getPosX()==c) {
                    cont2++;
                    break;
                }
            }if(cont2!=0)
                break;
        }if(cont2!=0)
            break;
    }if (cont2!=0){
        cout<<endl<<"Ya existe un robot en esa area"<<endl;
    }
    if(cont2==0)
    {

        for(TipoEntero f=y;f<y+yn;f++)
        {
            for(TipoEntero c=x;c<x+xn;c++)
            {
                if((f==x)&&(c==y)){
                    tierra.adicionarObjeto(new Objeto(nombre, color, x, y,"Boss"));
                    continue;}
                tierra.adicionarObjeto(new Objeto(nombre, color, c, f,"BossTile"));

            }
        }
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
      case Opciones::Boss:
            ingresaBoss();
            break;

    }
}
