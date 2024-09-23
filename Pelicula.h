// Javier Yahir Juarez Arroyo
// A00838452
using namespace std;
#include <iostream>
#include "Video.h"

// Definicion de la clase Pelicula que hereda de la clase Video
class Pelicula : public Video
{
public:
    // Constructor por defecto
    Pelicula();

    // Constructor con parametros
    Pelicula(int, int, string, string, int);

    // Metodo para calcular el promedio de calificaciones
    void calcularPromedio();

    // Metodo para desplegar informacion de la pelicula (sobrescribe el metodo en Video)
    void desplegar() override;

    // Metodo para desplegar peliculas con una calificacion especifica
    void desplegarCal(int);
};
