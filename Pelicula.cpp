// Javier Yahir Jurez Arroyo
// A00838452
#include "Pelicula.h"
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

// Constructor por defecto de la clase Pelicula
Pelicula::Pelicula() : Video()
{
    tipoVideo = 1; // Asigna el valor 1 a tipoVideo para indicar que es una pelicula
}

// Constructor con parametros de la clase Pelicula
Pelicula::Pelicula(int _id, int _duracion, string _titulo, string _genero, int _calificacion) : Video(_id, _duracion, _titulo, _genero, _calificacion)
{
    tipoVideo = 1; // Asigna el valor 1 a tipoVideo para indicar que es una pelicula
}

// Metodo para calcular el promedio de calificaciones de las peliculas
void Pelicula::calcularPromedio()
{
    ifstream file("../database.json"); // Abre el archivo JSON
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl; // Error si el archivo no se puede abrir
        return;
    }

    json database;
    file >> database; // Lee el archivo JSON
    file.close();

    if (!database.contains("videos") || !database["videos"].is_array())
    {
        cerr << "Formato de JSON incorrecto" << endl; // Error si el formato del JSON es incorrecto
        return;
    }

    int sumaCalificaciones = 0;
    int cuentaVideos = 0;

    // Recorre los videos de el archivo JSON
    for (const auto &video : database["videos"])
    {
        if (video.contains("tipoVideo") && video["tipoVideo"].is_number() && video["tipoVideo"] == 1)
        {
            if (video.contains("calificacion") && video["calificacion"].is_number())
            {
                int cal = video["calificacion"];
                sumaCalificaciones += cal; // Suma las calificaciones
                ++cuentaVideos;            // Incrementa el contador de videos
            }
        }
    }

    if (cuentaVideos == 0)
    {
        cout << "No hay videos con tipoVideo 1 y calificaciones" << endl; // Mensaje si no hay videos con tipoVideo 1
        return;
    }

    double promedio = static_cast<double>(sumaCalificaciones) / cuentaVideos;                           // Calcula el promedio
    cout << "El promedio de las calificaciones de los videos con tipoVideo 1 es: " << promedio << endl; // Muestra el promedio
}

// Metodo para desplegar la informacion de las peliculas
void Pelicula::desplegar()
{
    ifstream file("../database.json"); // Abre el archivo JSON
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl; // Error si el archivo no se puede abrir
        return;
    }

    json database;
    file >> database; // Lee el archivo JSON
    file.close();

    if (!database.contains("videos") || !database["videos"].is_array())
    {
        cerr << "Formato de JSON incorrecto" << endl; // Error si el formato del JSON es incorrecto
        return;
    }

    bool peliculasEncontradas = false;

    // Recorre los videos en el archivo JSON
    for (const auto &video : database["videos"])
    {
        if (video.contains("tipoVideo") && video["tipoVideo"].is_number() && video["tipoVideo"] == 1)
        {
            cout << "Titulo: " << video["titulo"] << endl;
            cout << "Duracion: " << video["duracion"] << " minutos" << endl;
            cout << "Genero: " << video["genero"] << endl;
            cout << "Calificacion: " << (video.contains("calificacion") ? to_string(video["calificacion"]) : "N/A") << endl;
            cout << "-----------------------" << endl;
            peliculasEncontradas = true; // Indica que se encontraron peliculas
        }
    }

    if (!peliculasEncontradas)
    {
        cout << "No se encontraron peliculas" << endl; // Mensaje si no se encuentran peliculas
    }
}

// Metodo para desplegar peliculas por calificacion especifica
void Pelicula::desplegarCal(int calificacionDeseada)
{
    ifstream file("../database.json"); // Abre el archivo JSON
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl; // Error si el archivo no se puede abrir
        return;
    }

    json database;
    file >> database; // Lee el archivo JSON
    file.close();

    if (!database.contains("videos") || !database["videos"].is_array())
    {
        cerr << "Formato de JSON incorrecto" << endl; // Error si el formato del JSON es incorrecto
        return;
    }

    bool peliculasEncontradas = false;

    // Recorre los videos en el archivo json
    for (const auto &video : database["videos"])
    {
        if (video.contains("tipoVideo") && video["tipoVideo"].is_number() && video["tipoVideo"] == 1 &&
            video.contains("calificacion") && video["calificacion"].is_number() && video["calificacion"] == calificacionDeseada)
        {
            cout << "Titulo: " << video["titulo"] << endl;
            cout << "Duracion: " << video["duracion"] << " minutos" << endl;
            cout << "Genero: " << video["genero"] << endl;
            cout << "-----------------------" << endl;
            peliculasEncontradas = true; // Indica que se encontraron peliculas con la calificacion deseada
        }
    }

    if (!peliculasEncontradas)
    {
        cout << "No se encontraron peliculas con calificacion " << calificacionDeseada << " y tipoVideo igual a 1" << endl; // Mensaje si no se encuentran peliculas con la calificacion deseada
    }
}
