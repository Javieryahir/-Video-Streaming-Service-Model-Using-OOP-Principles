// Javier Yahir Juarez Arroyo
// A00838452

#ifndef EPISODIO_H
#define EPISODIO_H

using namespace std;
#include <iostream>

class Episodio
{
    // seccion private que permite obtener los atributos solo en la clase
private:
    int id;
    int temporada;
    string titulo;
    string serie;
    string genero;
    int calificacion;
    int tipoVideo;
    int duracion;
    // seccion public permite obtener los metodos en cualquier parte
public:
    // Constructor por defecto
    Episodio();

    // Constructor con parametros
    Episodio(int, int, string, string, string, int, int);

    // Metodos para obtener atributos
    int getId();
    int getTemporada();
    string getTitulo();
    string getGenero();
    string getSerie();
    int getCalificacion();
    int getDuracion();
    int getTipoVideo();

    // Metodos para establecer atributos
    void setSerie(string);
    void setGenero(string);

    // Sobrecarga del operador + para sumar la duracion de dos episodios
    Episodio operator+(const Episodio &e) const
    {
        Episodio resultado;
        resultado.duracion = this->duracion + e.duracion; // Suma las duraciones de los episodios
        return resultado;                                 // Retorna un nuevo objeto Episodio con la duracion sumada
    }
};

#endif
