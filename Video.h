#ifndef VIDEO_H
#define VIDEO_H

using namespace std;
#include <iostream>

// Declaracion de la clase base Video
class Video
{
protected:
    // Atributos protegidos de la clase Video
    int id;
    int duracion;
    string titulo;
    string genero;
    int calificacion;
    int tipoVideo;

public:
    // Constructor por defecto
    Video();
    // Constructor con parametros
    Video(int, int, string, string, int);
    // Metodo virtual puro para calcular el promedio de calificaciones (debe ser implementado por clases derivadas)
    virtual void calcularPromedio() = 0;
    // Metodo virtual para desplegar informacion del video (puede ser sobrescrito por clases derivadas)
    virtual void desplegar();
    // Metodo virtual para desplegar videos con una calificacion especifica (puede ser sobrescrito por clases derivadas)
    virtual void desplegarCal(int);
    // Metodo para guardar informacion del video
    void guardar();
};

#endif
