// Javier Yahir Juarez Arroyo
// A00838452

using namespace std;
#include "Episodio.h"

// Constructor por defecto de la clase Episodio
Episodio::Episodio()
{
    id = 20;
    temporada = 2;
    genero = "Comedia";
    titulo = "Los Simpsons Capitulo 1";
    serie = "Los Simpsons";
    calificacion = 3;
    duracion = 30;
    tipoVideo = 3;
}

// Constructor con parametros de la clase Episodio
Episodio::Episodio(int _id, int _temporada, string _genero, string _titulo, string _serie, int _calificacion, int _duracion)
{
    id = _id;
    temporada = _temporada;
    genero = _genero;
    titulo = _titulo;
    serie = _serie;
    calificacion = _calificacion;
    duracion = _duracion;
    tipoVideo = 3;
}

// Metodo para obtener el ID del episodio
int Episodio::getId()
{
    return id;
}

// Metodo para obtener la temporada del episodio
int Episodio::getTemporada()
{
    return temporada;
}

// Metodo para obtener el título del episodio
string Episodio::getTitulo()
{
    return titulo;
}

// Metodo para obtener la calificacion del episodio
int Episodio::getCalificacion()
{
    return calificacion;
}

// Metodo para obtener la duracion del episodio
int Episodio::getDuracion()
{
    return duracion;
}

// Metodo para establecer la serie del episodio
void Episodio::setSerie(string _serie)
{
    serie = _serie;
}

// Metodo para establecer el genero del episodio
void Episodio::setGenero(string _genero)
{
    genero = _genero;
}

// Metodo para obtener el tipo de video del episodio
int Episodio::getTipoVideo()
{
    return tipoVideo;
}

// Metodo para obtener la serie del episodio
string Episodio::getSerie()
{
    return serie;
}

// Metodo para obtener el género del episodio
string Episodio::getGenero()
{
    return genero;
}
