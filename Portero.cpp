#include "Portero.h"

// Default constructor
Portero::Portero(){
    nombre = "";
    cantidadPartidos = 0;
    cantidadAtajadas = 0;
}

// Constructor with parameters
Portero::Portero(string _nombre, int _cantidadPartidos, int _cantidadAtajadas){
    nombre = _nombre;
    cantidadPartidos = _cantidadPartidos;
    cantidadAtajadas = _cantidadAtajadas;
}

// Empty destructor
Portero::~Portero(){
}

// Getter methods
string Portero::getNombre(){
    return nombre;
}

int Portero::getCantidadAtajadas(){
    return cantidadAtajadas;
}

int Portero::getCantidadPartidos(){
    return cantidadPartidos;
}

// Setter methods
void Portero::setNombre(string _nombre){
    nombre = _nombre;
}

void Portero::setCantidadPartidos(int _cantidadPartidos){
    cantidadPartidos = _cantidadPartidos;
}

void Portero::setCantidadAtajadas(int _cantidadAtajadas){
    cantidadAtajadas = _cantidadAtajadas;
}

// Additional methods

// Calculates the average number of saves per match
double Portero::calculaPromedioAtajadas(){
    if (cantidadPartidos == 0)
    {
        return 0;
    }
    
    double promedio = cantidadAtajadas / (cantidadPartidos * 1.0);
    return promedio;
}

/*
 Increases the number of matches played by one.
 Additionally, it receives the number of saves made in that match
 and adds them to the total number of saves.
*/
void Portero::registraPartido(int _cantidadAtajadas){
    cantidadPartidos++;
    cantidadAtajadas += _cantidadAtajadas;
}
