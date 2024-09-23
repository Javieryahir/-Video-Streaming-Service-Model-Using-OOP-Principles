// Javier Yahir Juarez Arroyo
// A00838452
#include "Serie.h"
#include "Episodio.cpp"
#include <iostream>
#include <fstream>

#include "json.hpp"

using json = nlohmann::json;
// Metodo por default con atributos de Video
Serie::Serie() : Video()
{
    tipoVideo = 2;
}
// Metodo constructor por parametros, con atributos heredados de la clase Persona
Serie::Serie(int _id, int _duracion, string _titulo, string _genero, int _calificacion) : Video(_id, _duracion, _titulo, _genero, _calificacion)
{
    tipoVideo = 2;
}

// Calcula el promedio de las Series
void Serie::calcularPromedio()
{
    // Abre el archivo JSON
    ifstream file("../database.json");
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return;
    }

    // Lee el contenido del archivo JSON en un objeto JSON
    json database;
    file >> database;
    file.close();

    // Verifica si el archivo JSON tiene el formato esperado
    if (!database.contains("videos") || !database["videos"].is_array())
    {
        cerr << "Formato de JSON incorrecto" << endl;
        return;
    }

    // Variables para calcular el promedio
    int sumaCalificaciones = 0;
    int cuentaVideos = 0;

    // Recorre todos los videos en el archivo JSON
    for (const auto &video : database["videos"])
    {
        // Verifica si el video tiene tipoVideo igual a 2 (serie)
        if (video.contains("tipoVideo") && video["tipoVideo"].is_number() && video["tipoVideo"] == 2)
        {
            // Verifica si el video tiene una calificación válida
            if (video.contains("calificacion") && video["calificacion"].is_number())
            {
                // Obtiene la calificación del video y la suma
                int cal = video["calificacion"];
                sumaCalificaciones += cal;
                ++cuentaVideos;
            }
        }
    }

    // Verifica si se encontraron videos con calificaciones
    if (cuentaVideos == 0)
    {
        cout << "No hay videos con tipoVideo 1 y calificaciones" << endl;
        return;
    }

    // Calcula el promedio de las calificaciones
    double promedio = static_cast<double>(sumaCalificaciones) / cuentaVideos;
    cout << "El promedio de las calificaciones de los videos con tipoVideo 1 es: " << promedio << endl;
}

// desplegar los atributos de cada serie en la base de datos
void Serie::desplegar()
{
    // abrir el archivo JSON
    ifstream file("../database.json");
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return;
    }

    json database;
    file >> database;
    file.close();

    // si el JSON no contiene un apartado videos agregar formato de Json incorrecto
    if (!database.contains("videos") || !database["videos"].is_array())
    {
        cerr << "Formato de JSON incorrecto" << endl;
        return;
    }

    bool peliculasEncontradas = false;

    // Desplegar la información de los videos con tipoVideo igual a 1
    for (const auto &video : database["videos"])
    {
        // encontrar los elementos con tipoVideo igual a 2 e imprimir la informacion
        if (video.contains("tipoVideo") && video["tipoVideo"].is_number() && video["tipoVideo"] == 2)
        {
            cout << "Titulo: " << video["titulo"] << endl;
            cout << "Duracion: " << video["duracion"] << " minutos" << endl;
            cout << "Genero: " << video["genero"] << endl;
            cout << "Calificacion: " << (video.contains("calificacion") ? to_string(video["calificacion"]) : "N/A") << endl;
            cout << "-----------------------" << endl;
            peliculasEncontradas = true;
        }
    }
    // if no hay pelicular imprimir no se encontraron peliculas
    if (!peliculasEncontradas)
    {
        cout << "No se encontraron películas" << endl;
    }
}

// desplegar informacion con una calificacion especifica
void Serie::desplegarCal(int calificacion)
{
    // encontrar el archivo json
    ifstream file("../database.json");
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return;
    }

    json database;
    file >> database;
    file.close();

    // encontrar el valor videos
    if (!database.contains("videos") || !database["videos"].is_array())
    {
        cerr << "Formato de JSON incorrecto" << endl;
        return;
    }

    bool peliculasEncontradas = false;

    // Desplegar la información de los videos con tipoVideo igual a 1 y la calificación especificada
    for (const auto &video : database["videos"])
    {
        // identificar si la serie tiene la misma calificacion que la proporcionada
        if (video.contains("tipoVideo") && video["tipoVideo"].is_number() && video["tipoVideo"] == 2 &&
            video.contains("calificacion") && video["calificacion"].is_number() && video["calificacion"] == calificacion)
        {
            cout << "Titulo: " << video["titulo"] << endl;
            cout << "Duracion: " << video["duracion"] << " minutos" << endl;
            cout << "Genero: " << video["genero"] << endl;
            cout << "-----------------------" << endl;
            peliculasEncontradas = true;
        }
    }

    if (!peliculasEncontradas)
    {
        cout << "No se encontraron películas con calificación " << calificacion << " y tipoVideo igual a 1" << endl;
    }
}

// calcular el promedio de cada serie
void Serie::calcularPromedioSerie(string nombreSerie)
{
    // encontrar y abrir el archvo json
    ifstream file("../database.json");
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return;
    }

    json database;
    file >> database;
    file.close();

    // identificar la clave videos
    if (!database.contains("videos") || !database["videos"].is_array())
    {
        cerr << "Formato de JSON incorrecto" << endl;
        return;
    }

    int sumaCalificaciones = 0;
    int cuentaEpisodios = 0;

    for (const auto &video : database["videos"])
    {
        // identificar elementos con ciertas caracteristicas
        if (video.contains("tipoVideo") && video["tipoVideo"].is_number() && video["tipoVideo"] == 3 &&
            video.contains("serie") && video["titulo"] == nombreSerie &&
            video.contains("calificacion") && video["calificacion"].is_number())
        {
            int cal = video["calificacion"];
            sumaCalificaciones += cal;
            ++cuentaEpisodios;
        }
    }

    // No se identificaron episodios
    if (cuentaEpisodios == 0)
    {
        cout << "No se encontraron episodios de la serie " << titulo << " con tipoVideo igual a " << tipoVideo << endl;
        return;
    }

    double promedio = static_cast<double>(sumaCalificaciones) / cuentaEpisodios;
    cout << "El promedio de las calificaciones de los episodios de la serie " << titulo << " con tipoVideo " << tipoVideo << " es: " << promedio << endl;
}
// desplegar los episodios de una serie especifica
void Serie::desplegarEpisodios(string nombreSerie)
{
    // abrir el archivo JSON
    ifstream file("../database.json");
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return;
    }

    json database;
    file >> database;
    file.close();
    // si no se encuentra, depslegar un mensaje
    if (!database.contains("videos") || !database["videos"].is_array())
    {
        cerr << "Formato de JSON incorrecto" << endl;
        return;
    }

    bool episodiosEncontrados = false;

    for (const auto &video : database["videos"])
    {
        // idetificar las caracterisiticas especificas para desplegar la informacion
        if (video.contains("tipoVideo") && video["tipoVideo"].is_number() && video["tipoVideo"] == 3 &&
            video.contains("titulo") && video["titulo"] == nombreSerie)
        {
            cout << "Titulo del episodio: " << video["titulo"] << endl;
            cout << "Duracion: " << video["duracion"] << " minutos" << endl;
            cout << "Genero: " << video["genero"] << endl;
            cout << "ID: " << video["id"] << endl;
            cout << "Calificacion: " << video["calificacion"] << endl;
            cout << "Tipo de Video: " << video["tipoVideo"] << endl;
            cout << "-----------------------" << endl;
            episodiosEncontrados = true;
        }
    }

    if (!episodiosEncontrados)
    {
        cout << "No se encontraron episodios de la serie " << titulo << " con tipoVideo igual a " << tipoVideo << endl;
    }
}

void Serie::agregarEpisodio(Episodio _episodio)
{
    // abrir el archivo JSON
    ifstream file("../database.json");
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return;
    }

    json database;
    file >> database;
    file.close();

    // crear la estructura de un objeto JSON
    json nuevoVideo = {
        {"id", _episodio.getId()},
        {"titulo", _episodio.getTitulo()},
        {"duracion", _episodio.getDuracion()},
        {"genero", _episodio.getGenero()},
        {"serie", _episodio.getSerie()},
        {"temporada", _episodio.getTemporada()},
        {"calificacion", _episodio.getCalificacion()},
        {"tipoVideo", _episodio.getTipoVideo()}};

    // agregar ese elemento en video
    database["videos"].push_back(nuevoVideo);

    ofstream outFile("../database.json");
    if (!outFile.is_open())
    {
        cerr << "No se pudo abrir el archivo para escritura" << endl;
        return;
    }
    outFile << database.dump(4);
    outFile.close();

    cout << "Nuevo video agregado al archivo JSON." << endl;
}

// desplegar episodios por calificacion y titulo
void Serie::desplegarEpisodiosCalPorTitulo(int calificacionDeseada, string tituloDeseado)
{
    // abrir el archivo json
    ifstream file("../database.json");
    if (!file.is_open())
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return;
    }

    json database;
    file >> database;
    file.close();

    // identificar el elimento video
    if (!database.contains("videos") || !database["videos"].is_array())
    {
        cerr << "Formato de JSON incorrecto" << endl;
        return;
    }

    bool episodiosEncontrados = false;

    for (const auto &video : database["videos"])
    {
        // identificar las caracteristicas proporcionadas
        if (video.contains("tipoVideo") && video["tipoVideo"].is_number() && video["tipoVideo"] == 3 &&
            video.contains("serie") && video["serie"] == tituloDeseado &&
            video.contains("calificacion") && video["calificacion"].is_number() && video["calificacion"] == calificacionDeseada)
        {
            cout << "Titulo del episodio: " << video["titulo"] << endl;
            cout << "Duracion: " << video["duracion"] << " minutos" << endl;
            cout << "Genero: " << video["genero"] << endl;
            cout << "ID: " << video["id"] << endl;
            cout << "Calificacion: " << video["calificacion"] << endl;
            cout << "-----------------------" << endl;
            episodiosEncontrados = true;
        }
    }

    if (!episodiosEncontrados)
    {
        cout << "No se encontraron episodios de la serie " << tituloDeseado << " con calificacion " << calificacionDeseada << " y tipoVideo igual a " << tipoVideo << endl;
    }
}
