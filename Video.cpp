// Javier Yahir Juarez Arroyo
// A00939452
using namespace std;
#include "Video.h"
#include <iostream>
#include <fstream>

#include "json.hpp"

using json = nlohmann::json;

// Implementacion del constructor por defecto
Video::Video()
{
    id = 0;
    duracion = 70;
    titulo = "El Circulo Rojo";
    genero = "Comedia";
    calificacion = 4;
    tipoVideo = 0;
}

// Implementacion del constructor con parametros
Video::Video(int _id, int _duracion, string _titulo, string _genero, int _calificacion)
{
    id = _id;
    duracion = _duracion;
    titulo = _titulo;
    genero = _genero;
    calificacion = _calificacion;
    tipoVideo = 0;
}

// Metodo para guardar la informacion del video en un archivo JSON
void Video::guardar()
{
    ifstream file("../database.json");
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return;
    }

    json database;
    file >> database;
    file.close();

    // Crear un objeto JSON para el nuevo video
    json nuevoVideo = {
        {"id", id},
        {"titulo", titulo},
        {"duracion", duracion},
        {"genero", genero},
        {"calificacion", calificacion},
        {"tipoVideo", tipoVideo}};

    // Agregar el nuevo video a la base de datos
    database["videos"].push_back(nuevoVideo);

    ofstream outFile("../database.json");
    if (!outFile.is_open())
    {
        cerr << "No se pudo abrir el archivo para escritura" << endl;
        return;
    }
    outFile << database.dump(4); // Escribir la base de datos actualizada en el archivo
    outFile.close();

    cout << "Nuevo video agregado al archivo JSON." << endl;
}

// Metodo para calcular el promedio de calificaciones de los videos
void Video::calcularPromedio()
{
    ifstream file("../database.json");
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return;
    }

    json database;
    file >> database;
    file.close();

    if (!database.contains("videos") || !database["videos"].is_array())
    {
        cerr << "Formato de JSON incorrecto" << endl;
        return;
    }

    int sumaCalificaciones = 0;
    int cuentaVideos = 0;

    for (const auto &video : database["videos"])
    {
        if (video.contains("calificacion") && video["calificacion"].is_number())
        {
            int calificacion = video["calificacion"];
            sumaCalificaciones += calificacion;
            ++cuentaVideos;
        }
    }

    if (cuentaVideos == 0)
    {
        cout << "No hay videos con calificaciones" << endl;
        return;
    }

    double promedio = static_cast<double>(sumaCalificaciones) / cuentaVideos;
    cout << "El promedio de las calificaciones es: " << promedio << endl;
}

// Metodo para desplegar la informacion de todos los videos
void Video::desplegar()
{
    ifstream file("../database.json");
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return;
    }

    json database;
    file >> database;
    file.close();

    if (!database.contains("videos") || !database["videos"].is_array())
    {
        cerr << "Formato de JSON incorrecto" << endl;
        return;
    }

    // Imprimir la informacion de los videos
    for (const auto &video : database["videos"])
    {
        cout << "Titulo: " << video["titulo"] << endl;
        cout << "Duracion: " << video["duracion"] << " minutos" << endl;
        cout << "Genero: " << video["genero"] << endl;
        cout << "-----------------------" << endl;
    }
}

// Metodo para desplegar la informacion de los videos con una calificacion especifica
void Video::desplegarCal(int calificacionDeseada)
{
    ifstream file("../database.json");
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return;
    }

    json database;
    file >> database;
    file.close();

    if (!database.contains("videos") || !database["videos"].is_array())
    {
        cerr << "Formato de JSON incorrecto" << endl;
        return;
    }

    // Bandera para verificar si se encontraron videos con la calificacion deseada
    bool videosEncontrados = false;

    // Imprimir la informacion de los videos con la calificacion deseada
    for (const auto &video : database["videos"])
    {
        if (video.contains("calificacion") && video["calificacion"].is_number() &&
            video["calificacion"] == calificacionDeseada)
        {
            cout << "Titulo: " << video["titulo"] << endl;
            cout << "Duracion: " << video["duracion"] << " minutos" << endl;
            cout << "Genero: " << video["genero"] << endl;
            cout << "Calificacion: " << video["calificacion"] << endl;
            cout << "-----------------------" << endl;
            videosEncontrados = true;
        }
    }

    // Mostrar mensaje si no se encontraron videos con la calificacion deseada
    if (!videosEncontrados)
    {
        cout << "No se encontraron videos con calificacion " << calificacionDeseada << endl;
    }
}
