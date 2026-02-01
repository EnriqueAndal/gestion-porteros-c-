#include "Portero.h"

// Function prototypes

// 1.- Functions that allow us to initialize and work with the data
int cantidadPorteros();
void cargarDatos(Portero _Porteros[], int _tamaño);

// 2.- Functions that execute each option shown in the menu
void mostrarInfo(Portero _Porteros[], int _tamaño);
void buscarPortero(Portero _Porteros[], int _tamaño);
void registrarPartido(Portero _Porteros[], int _tamaño);

// 3.- Function that displays the menu and calls the corresponding functions
void mostrarOpciones(Portero _Porteros[], int _tamaño);



/* main()
 The main() function only defines the maximum size of the array, but its main purpose
 is to call the functions that handle the program execution.
 It is useful because it allows us to treat the Porteros array and its length as
 "global" variables within the program flow.
*/
int main(){
    Portero Porteros[10];
    
    int len = cantidadPorteros();
    cargarDatos(Porteros, len);
    
    mostrarOpciones(Porteros, len);
    
    return 0;
}



/* cantidadPorteros()
 In order to keep main() limited to calling functions, we created this function
 to return the number of goalkeepers the user wants to store.
 This is where we restrict the input so the user cannot enter more than 10
 goalkeepers and cannot provide negative values.
*/
int cantidadPorteros(){
    int _len = 0;
    
    cout << "Ingresa la cantidad de porteros que quieres llenar: ";
    cin >> _len;
    cin.ignore();
    cout << endl;
    
    while (_len < 1 || _len > 10)
    {
        cout << "Has ingresado una cantidad inválida, debe ser mayor a 0 y 10: ";
        cin >> _len;
        cin.ignore();
        cout << endl;
    }
    
    return _len;
}



/* cargarDatos()
 A loop that runs as many times as the number of goalkeepers the user wants to create.
 It asks for each goalkeeper's name, number of matches played, and number of saves,
 and uses the class setter methods to store the data.
*/
void cargarDatos(Portero _Porteros[10], int _tamaño){
    for (int N = 0; N < _tamaño; N++)
    {
        string nombre_ing;
        int cantidadPartidos_ing;
        int cantidadAtajadas_ing;
        
        // Solicitar y verificar nombre válido
        cout << "Ingresa el nombre de tu portero: ";
        getline(cin, nombre_ing);
        
        while (nombre_ing.length() < 1)
        {
            cout << "Dudo que tu jugador tenga menos de una letra en su nombre. Intenta de nuevo: ";
            getline(cin, nombre_ing);
        }
        
        _Porteros[N].setNombre(nombre_ing);
                
        // Solicitar y verificar cantidad de partidos válidos
        cout << "Ingresa la cantidad de partidos jugados: ";
        cin >> cantidadPartidos_ing;
        
        while (cantidadPartidos_ing < 0)
        {
            cout << "Ingresaste una cantidad de partidos negativa. Intenta de nuevo: ";
            cin >> cantidadPartidos_ing;

        }
        
        _Porteros[N].setCantidadPartidos(cantidadPartidos_ing);
        
        // Solicitar y verificar cantidad de atajadas validas
        cout << "Ingresa la cantidad de atajadas: ";
        cin >> cantidadAtajadas_ing;
        
        while (cantidadAtajadas_ing < 0){
            cout << "Ingresaste una cantidad de atajadas negativa. Intenta de nuevo: ";
            cin >> cantidadAtajadas_ing;
        }
        
        _Porteros[N].setCantidadAtajadas(cantidadAtajadas_ing);
                
        cout << endl;
    }
}



/* mostrarInfo()
 Le pedimos al usuario que nos diga un mínimo de partidos a considerar para mostrar aquellos porteros
 que tengan más que eso. Ya que nos lo dice, desplegamos la información básica de los que cumplan la condición.
*/
void mostrarInfo(Portero _Porteros[], int _tamaño){
    int minimo = 0;
    
    cout << "¿Cuál es el mínimo de partidos que debe haber jugado tu portero para mostrar su información? ";
    cin >> minimo;
    
    while (minimo < 0)
    {
        cout << "Ningun portero ha jugado partidos negativos, intenta de nuevo: ";
        cin >> minimo;
        cin.ignore();
    }
    
    cout << endl;
    
    bool encontrado = false;
    
    for (int N = 0; N < _tamaño; N++)
    {

        if (_Porteros[N].getCantidadPartidos() > minimo)
        {
            cout << "Nombre del portero: " << _Porteros[N].getNombre() << endl;
            cout << "Cantidad de partidos: " << _Porteros[N].getCantidadPartidos() << endl;
            cout << "Cantidad de atajadas: " << _Porteros[N].getCantidadAtajadas() << endl;
             
            encontrado = true;
        }
    }
    if (encontrado != true)
    {
        cout << "Ningún jugador cumple con los requerimientos solicitados.\n";
    }
}



/* buscarPortero()
 The user enters the name of one of the previously created goalkeepers.
 The function iterates through the array and compares each name with the input.
 Once the goalkeeper is found, it displays their basic information and uses
 the calculaPromedioAtajadas() method (declared and implemented in the .h and .cpp files)
 to compute the average number of saves per match.
*/
void buscarPortero(Portero _Porteros[], int _tamaño){
    string nombreObjetivo = "";
    
    cout << "¿De qué portero gustas ver su información a detalle? ";
    getline(cin, nombreObjetivo);
    
    while (nombreObjetivo.length() < 1)
    {
        cout << "Otra vez con jugadores con pocas letras? Intenta de nuevo: ";
        getline(cin, nombreObjetivo);
    }
    
    cout << endl;
        
    bool encontrado = false;

    for (int N = 0; N < _tamaño; N++)
    {
        if (_Porteros[N].getNombre() == nombreObjetivo)
        {
            cout << "Nombre del portero: " << _Porteros[N].getNombre() << endl;
            cout << "Cantidad de partidos jugados: " << _Porteros[N].getCantidadPartidos() << endl;
            cout << "Cantidad de atajadas hechas: " <<  _Porteros[N].getCantidadAtajadas() << endl;
            cout << "Promedio de atajadas por partido: " << _Porteros[N].calculaPromedioAtajadas() << endl;
            
            encontrado = true;
        }
    }
    if (encontrado != true)
    {
        cout << "El nombre ingresado no coincide con ninguno dentro del arreglo.\n";
    }
}



/* registrarPartido()
 The user is asked to select a goalkeeper for whom a new match will be registered.
 In order for the registraPartido() method to work, the number of saves made in that match
 is requested as an argument.
 The goalkeeper's information is then updated using class methods and the changes
 are displayed using getter methods.
*/
void registrarPartido(Portero _Porteros[], int _tamaño){
    string nombreObjetivo = "";
    int nuevasAtajadas = 0;
    
    // Verificar que el nombre ingresado sea válido
    cout << "¿Qué portero acaba de jugar otro partido? ";
    getline(cin, nombreObjetivo);
    
    while (nombreObjetivo.length() < 1)
    {
        cout << "Otra vez con jugadores con pocas letras? Intenta de nuevo: ";
        getline(cin, nombreObjetivo);
    }
    
    // verificar que las atajadas ingresadas sean válidas
    cout << "¿Cuántas atajadas hizo ahora? ";
    cin >> nuevasAtajadas;
    
    while (nuevasAtajadas < 0){
        cout << "Ingresaste una cantidad de atajadas negativa. Intenta de nuevo: ";
        cin >> nuevasAtajadas;
    }
    
    cout << endl;
    
    bool encontrado = false;
    
    for (int N = 0; N < _tamaño; N++){
        if (_Porteros[N].getNombre() == nombreObjetivo){
            
            _Porteros[N].registraPartido(nuevasAtajadas);
            
            cout << "Tu portero ahora ha jugado " << _Porteros[N].getCantidadPartidos() << " partidos" << endl;
            cout << "Y su cantidad de atajadas ahora es de " << _Porteros[N].getCantidadAtajadas() << endl;
            cout << endl;
            
            encontrado = true;
        }
    }
    if (encontrado != true)
    {
        cout << "Lo sentimos, pero el portero que ingresaste no se encuentra en el arreglo.\n";
    }
}



/* mostrarOpciones()
 Once the user has created the array of goalkeepers, this function displays a menu
 that allows them to choose what action to perform on the data.
 Depending on the selected option, one of the available functions is called.
 If an invalid option is entered, an error message is shown and the menu is
 displayed again until the user decides to exit the program.
*/
void mostrarOpciones(Portero _Porteros[], int _tamaño){
    int opcion = 0;
    
    do{
        cout << "====== Menú de opciones ======\n";
        cout << "--- 1.- Mostrar Porteros con más de X partidos\n";
        cout << "--- 2.- Mostrar datos del portero\n";
        cout << "--- 3.- Registrar partido\n";
        cout << "--- 4.- Salir del programa\n";
        
        cout << endl;
        
        cout << "Ingresa la opción que quieres ver: ";
        cin >> opcion;
        cin.ignore();
        cout << endl;

        switch (opcion){
            case 1:
                mostrarInfo(_Porteros, _tamaño);
                break;
            case 2:
                buscarPortero(_Porteros, _tamaño);
                break;
            case 3:
                registrarPartido(_Porteros, _tamaño);
                break;
            case 4:
                cout << "Has cerrado el programa. Vuelve pronto! " << endl;
                break;
            default:
                cout << "La opción ingresada no esta en el rango de opciones, intenta de nuevo.\n";
        }
        cout << endl;
    } while (opcion != 4);
}
