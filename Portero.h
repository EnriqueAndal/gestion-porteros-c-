#include <iostream>
#include <string>
using namespace std;

class Portero{
private:
    string nombre;
    int cantidadPartidos;
    int cantidadAtajadas;
    
public:
    // Default constructor
    Portero();
    
    // Constructor with parameters
    Portero(string, int, int);
    
    // Destructor
    ~Portero();
    
    // Getter methods
    string getNombre();
    
    int getCantidadPartidos();
    
    int getCantidadAtajadas();
    
    // Setter methods
    void setNombre(string);
    void setCantidadPartidos(int);
    void setCantidadAtajadas(int);
    
    // Additional methods
    double calculaPromedioAtajadas();
    void registraPartido(int);
};
