// Javier Yahir Juarez Arroyo
// A008384852
using namespace std;
#include <iostream>
#include "Video.h"
#include "Serie.h"
#include "Pelicula.h"
#include "Episodio.h"

// Funcion para mostrar el menu de opciones
void mostrarMenu()
{
    cout << "-------------------" << endl;
    cout << "1. Agregar Pelicula" << endl;
    cout << "2. Agregar Serie" << endl;
    cout << "3. Agregar Episodio a Serie" << endl;
    cout << "4. Calcular Promedio de Peliculas" << endl;
    cout << "5. Calcular Promedio de Series" << endl;
    cout << "6. Calcular Promedio de Episodios de Serie" << endl;
    cout << "7. Desplegar Peliculas" << endl;
    cout << "8. Desplegar Series" << endl;
    cout << "9. Desplegar Episodios de Serie" << endl;
    cout << "10. Desplegar Peliculas por Calificacion" << endl;
    cout << "11. Desplegar Series por Calificacion" << endl;
    cout << "12. Desplegar Episodios por Calificacion y Titulo de Serie" << endl;
    cout << "13. Sumar la duracion de La Segunda Temporada de Breaking Bad" << endl;
    cout << "14. Salir" << endl;
    cout << "-------------------" << endl;
    cout << "Seleccione una opcion: ";
}

int main()
{
    int opcion;
    Pelicula pelicula; // Objeto Pelicula
    Serie serie;       // Objeto Serie
    Episodio episodio; // Objeto Episodio
    int id, duracion, calificacion, temporada;
    string titulo, genero, serieTitulo, serieP;

    // Ejemplos de episodios de Breaking Bad
    Episodio episodio1 = Episodio(50, 2, "Comedia", "Capitulo 1: El poder", "Breaking Bad", 3, 25);
    Episodio episodio2 = Episodio(60, 2, "Comedia", "Capitulo 2: Los Videojuegos", "Breaking Bad", 4, 30);
    Episodio resultado;
    char mostrarMenuRespuesta;

    // Bucle infinito para mostrar el menu hasta que el usuario decida salir
    while (true)
    {
        cout << "Desea ver el menu? (s/n): ";
        cin >> mostrarMenuRespuesta;

        if (mostrarMenuRespuesta == 's' || mostrarMenuRespuesta == 'S')
        {
            mostrarMenu();
        }

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // Agregar una nueva pelicula
            cout << "Ingrese ID de la pelicula: ";
            cin >> id;
            cout << "Ingrese duracion de la pelicula (minutos): ";
            cin >> duracion;
            cout << "Ingrese titulo de la pelicula: ";
            cin.ignore();
            getline(cin, titulo);
            cout << "Ingrese genero de la pelicula: ";
            getline(cin, genero);
            cout << "Ingrese calificacion de la pelicula: ";
            cin >> calificacion;
            pelicula = Pelicula(id, duracion, titulo, genero, calificacion);
            pelicula.guardar();
            break;

        case 2:
            // Agregar una nueva serie
            cout << "Ingrese ID de la serie: ";
            cin >> id;
            cout << "Ingrese duracion de la serie (minutos): ";
            cin >> duracion;
            cout << "Ingrese titulo de la serie: ";
            cin.ignore();
            getline(cin, titulo);
            cout << "Ingrese genero de la serie: ";
            getline(cin, genero);
            cout << "Ingrese calificacion de la serie: ";
            cin >> calificacion;
            serie = Serie(id, duracion, titulo, genero, calificacion);
            serie.guardar();
            break;

        case 3:
            // Agregar un nuevo episodio a una serie
            cout << "Ingrese ID del episodio: ";
            cin >> id;
            cout << "Ingrese la temporada del episodio: ";
            cin >> temporada;
            cout << "Ingrese duracion del episodio (minutos): ";
            cin >> duracion;
            cout << "Ingrese titulo del episodio: ";
            cin.ignore();
            getline(cin, titulo);
            cout << "Ingrese genero del episodio: ";
            getline(cin, genero);
            cout << "Ingrese la serie del episodio: ";
            getline(cin, serieP);
            cout << "Ingrese calificacion del episodio: ";
            cin >> calificacion;
            episodio = Episodio(id, temporada, genero, titulo, serieP, calificacion, duracion);
            serie.agregarEpisodio(episodio);
            break;

        case 4:
            // Calcular el promedio de calificacion de las peliculas
            pelicula.calcularPromedio();
            break;

        case 5:
            // Calcular el promedio de calificacion de las series
            serie.calcularPromedio();
            break;

        case 6:
            // Calcular el promedio de calificacion de los episodios de una serie
            cout << "Ingrese el nombre de la Serie: ";
            cin.ignore();
            getline(cin, serieP);
            serie.calcularPromedioSerie(serieP);
            break;

        case 7:
            // Desplegar todas las peliculas
            pelicula.desplegar();
            break;

        case 8:
            // Desplegar todas las series
            serie.desplegar();
            break;

        case 9:
            // Desplegar todos los episodios de una serie especifica
            cout << "Ingrese el nombre de la Serie: ";
            cin.ignore();
            getline(cin, serieP);
            serie.desplegarEpisodios(serieP);
            break;

        case 10:
            // Desplegar películas por calificacion
            cout << "Ingrese calificacion deseada: ";
            cin >> calificacion;
            pelicula.desplegarCal(calificacion);
            break;

        case 11:
            // Desplegar series por calificacion
            cout << "Ingrese calificacion deseada: ";
            cin >> calificacion;
            serie.desplegarCal(calificacion);
            break;

        case 12:
            // Desplegar episodios por calificacion y titulo de la serie
            cout << "Ingrese calificacion deseada: ";
            cin >> calificacion;
            cout << "Ingrese titulo de la serie: ";
            cin.ignore();
            getline(cin, serieTitulo);
            serie.desplegarEpisodiosCalPorTitulo(calificacion, serieTitulo);
            break;

        case 13:
            // Sumar la duracion de dos episodios de la segunda temporada de Breaking Bad
            resultado = episodio1 + episodio2;
            cout << resultado.getDuracion() << endl;
            break;

        case 14:
            // Salir del programa
            cout << "Saliendo del programa." << endl;
            return 0;
            break;

        default:
            // Opción no valida
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    }

    return 0;
}
