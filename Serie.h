// Javier Yahir Juarez Arroyo
// A00838452
using namespace std;
#include <iostream>
#include <string>
#include "Episodio.h"
#include "Video.h"

// Declaracion de la clase Serie que hereda de la clase Video
class Serie : public Video
{
public:
    // Constructor por defecto
    Serie();
    // Constructor con parametros
    Serie(int, int, string, string, int);
    // Metodo para calcular el promedio de calificaciones de la serie
    void calcularPromedio();
    // Metodo para desplegar la informacion de la serie (sobrescribe el metodo de la clase base)
    void desplegar() override;
    // Metodo para desplegar series con una calificacion especifica
    void desplegarCal(int);
    // Metodo para calcular el promedio de calificaciones de los episodios de una serie especifica
    void calcularPromedioSerie(string);
    // Metodo para agregar un episodio a la serie
    void agregarEpisodio(Episodio);
    // Metodo para desplegar los episodios de una serie especifica
    void desplegarEpisodios(string);
    // Metodo para desplegar episodios de una serie especifica con una calificacion deseada
    void desplegarEpisodiosCalPorTitulo(int, string);
};
