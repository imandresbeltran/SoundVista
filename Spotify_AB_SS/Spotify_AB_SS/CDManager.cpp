#include "CDManager.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

using namespace std;

CDManager::CDManager() {}

void CDManager::cargarRespaldos(const string& rutaCarpeta) {
	listaCDs.clear();

    if (!fs::exists(rutaCarpeta) || !fs::is_directory(rutaCarpeta)) {
        cout << "La carpeta especificada no existe o no es una carpeta válida." << endl;
        return;
    }
    cout << "Ruta de carpeta cargada: " << rutaCarpeta << endl;

    for (const auto& entry : fs::directory_iterator(rutaCarpeta)) {
        if (entry.is_regular_file()) {
            const string archivo = entry.path().string();

            if (fs::path(archivo).extension() == ".txt") { //Verificar que el archivo tenga la extensión .txt
                ifstream archivoCD(archivo);

                if (archivoCD.is_open()) {
                    string nombreCD = fs::path(archivo).stem().string(); //Obtener el nombre del archivo sin extensión
                    CD nuevoCD(nombreCD);

                    string linea;
                    int lineasLeidas = 0;

                    while (getline(archivoCD, linea)) {
                        //Procesar cada línea del archivo
                        istringstream ss(linea);
                        string nombre, artista, duracion;

                        if (getline(ss, nombre, '|') && getline(ss, artista, '|') && getline(ss, duracion, '|')) {
                            //Verificar si la línea tiene el formato correcto

                            Cancion cancion(nombre, artista, duracion);
                            nuevoCD.addSong(cancion);
                            lineasLeidas++;
                        }
                        else {
                            cout << "Error en el archivo '" << archivo << "': Formato de línea incorrecto en la línea " << (lineasLeidas + 1) << endl;
                        }
                    }

                    //Verificar si se leyeron canciones del CD
                    if (lineasLeidas > 0) {
                        listaCDs.push_back(nuevoCD);
                        cout << "Se cargó el CD '" << nombreCD << "' con " << lineasLeidas << " canciones." << endl;
                    }
                    else {
                        cout << "El archivo '" << archivo << "' no contiene canciones válidas." << endl;
                    }

                    archivoCD.close();
                }
                else {
                    cout << "No se pudo abrir el archivo '" << archivo << "'." << endl;
                }
            }
        }
    }
}
void CDManager::agregarCancion() {
    //Verificar si hay CDs cargados
    if (listaCDs.empty()) {
        cout << "No hay CDs cargados. Cargue CDs ants de agregar canciones." << endl;
        return;
    }

    //Mostrar la lista de CDs disponibles
    cout << "Lista de CDs disponibles:" << endl;
    for (size_t i = 0; i < listaCDs.size(); i++) cout << i + 1 << ". " << listaCDs[i].name << endl;

    int seleccionCD;
    cout << "Seleccione un CD (ingrese el número): ";
    cin >> seleccionCD;

    //Verificar si la selección de CD es válida
    if (seleccionCD < 1 || seleccionCD > static_cast<int>(listaCDs.size())) {
        cout << "Selección de CD no válida." << endl;
        return;
    }

    //Mostrar la lista de canciones del CD seleccionado
    const CD& cdSeleccionado = listaCDs[seleccionCD - 1];
    cout << "Canciones del CD '" << cdSeleccionado.name << " :" << endl;
    const vector<Cancion>& cancionesCD = cdSeleccionado.songs;
    for(size_t i = 0; i < cancionesCD.size(); i++) cout << i + 1 << ". " << cancionesCD[i].name << " - " << cancionesCD[i].artist << " - " << cancionesCD[i].duration << endl;

    int seleccionCancion;
    cout << "Seleccione una canción (ingrese el número): ";
    cin >> seleccionCancion;

    //Verificar si la seleccion de la canción es válida
    if (seleccionCancion < 1 || seleccionCancion > static_cast<int>(cancionesCD.size())) {
        cout << "Selección de canción no válida." << endl;
        return;
    }

    //Agregar la canción seleccionada a la cola de reproducción
    const Cancion& cancionSeleccionada = cancionesCD[seleccionCancion - 1];
    colaReproduccion.push_back(cancionSeleccionada);

    cout << "Cancion '" << cancionSeleccionada.name << "' agregada a la cola de reproducción." << endl;
}

void CDManager::verColaReproduccion() {
    if (colaReproduccion.empty()) cout << "La cola de reproducción está vacía" << endl;
    else {
        int opcion;
        cout << "Seleccione una opción:" << endl;
        cout << "1. Ver la cola de reproducción actual" << endl;
        cout << "2. Ver la cola de reproducción ordenada por nombre del artista" << endl;
        cout << "3. Ver la cola de reproducción ordenada por nombre de la canción" << endl;
        cout << "4. Ver la cola de reproducción ordenada por duración" << endl;
        cout << "Ingrese el número de la opción: ";
        cin >> opcion;

        vector<Cancion> colaMostrada = colaReproduccion;

        switch (opcion)
        {
        case 1:
            cout << "Cola de reproducción actual: " << endl;
            break;

        case 2:
            sort(colaMostrada.begin(), colaMostrada.end(), [](const Cancion& a, const Cancion& b) {
                return a.artist < b.artist;
                });
            cout << "Cola de reproducción ordenada por nombre del artista:" << endl;
            break;

        case 3:
            sort(colaMostrada.begin(), colaMostrada.end(), [](const Cancion& a, const Cancion& b) {
                return a.name < b.name;
                });
            cout << "Cola de reproducción ordenada por nombre de la canción:" << endl;
            break;

        case 4:
            sort(colaMostrada.begin(), colaMostrada.end(), [](const Cancion& a, const Cancion& b) {
                return a.duration < b.duration;
                });
            cout << "Cola de reproducción ordenada por duración:" << endl;
            break;

        default:
            cout << "Opcion no válida. " << endl;
                return;
        }

        for(const Cancion& cancion : colaMostrada) cout << cancion.name << " - " << cancion.artist << " - " << cancion.duration << endl;
    }
}

void CDManager::reproduccionActual() {
    if (!colaReproduccion.empty()) {
        const Cancion& cancionEnReproduccion = colaReproduccion.front();
        cout << "Reproduciendo:" << endl;
        cout << "Nombre: " << cancionEnReproduccion.name << endl;
        cout << "Artista: " << cancionEnReproduccion.artist << endl;
        cout << "Duración: " << cancionEnReproduccion.duration << endl;

        for (const CD& cd : listaCDs) {
            for (const Cancion& song : cd.songs) {
                if (song.name == cancionEnReproduccion.name && song.artist == cancionEnReproduccion.artist) {
                    cout << "CD: " << cd.name << endl;
                    break;
                }
            }
        }
    }
    else {
        cout << "Reproducción en Pausa. La cola de reproducción está vacía." << endl;
    }
}

void CDManager::reproducirSiguiente() {
    if (!colaReproduccion.empty()) {
        Cancion siguienteCancion = colaReproduccion.front();

        cout << "Reproducíedno siguiente canción: " << endl;
        cout << "Nombre: " << siguienteCancion.name << endl;
        cout << "Artista: " << siguienteCancion.artist << endl;
        cout << "Duración: " << siguienteCancion.duration << endl;

        colaReproduccion.push_back(siguienteCancion);
        colaReproduccion.erase(colaReproduccion.begin());
    } else cout << "La cola de reproducción está vacía. No hay canciones para reproducir." << endl;
}

void CDManager::ordenarCola() {
    if (!colaReproduccion.empty()) {
        int opcion;
        cout << "Seleccione una opción para ordenar la cola:" << endl;
        cout << "1. Ordenar por nombre del artista (ascendente)" << endl;
        cout << "2. Ordenar por nombre del artista (descendente)" << endl;
        cout << "3. Ordenar por nombre de la canción (ascendente)" << endl;
        cout << "4. Ordenar por nombre de la canción (descendente)" << endl;
        cout << "5. Ordenar por duración (ascendente)" << endl;
        cout << "6. Ordenar por duración (descendente)" << endl;
        cout << "Ingrese el número de la opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            sort(colaReproduccion.begin(), colaReproduccion.end(), [](const Cancion& a, const Cancion& b) {
                return a.artist < b.artist;
                });
            cout << "Cola de reproducción ordenada por nombre del artista (ascendente)." << endl;
            break;
        case 2:
            sort(colaReproduccion.begin(), colaReproduccion.end(), [](const Cancion& a, const Cancion& b) {
                return a.artist > b.artist;
                });
            cout << "Cola de reproducción ordenada por nombre del artista (descendente)." << endl;
            break;
        case 3:
            sort(colaReproduccion.begin(), colaReproduccion.end(), [](const Cancion& a, const Cancion& b) {
                return a.name < b.name;
                });
            cout << "Cola de reproducción ordenada por nombre de la canción (ascendente)." << endl;
            break;
        case 4:
            sort(colaReproduccion.begin(), colaReproduccion.end(), [](const Cancion& a, const Cancion& b) {
                return a.name > b.name;
                });
            cout << "Cola de reproducción ordenada por nombre de la canción (descendente)." << endl;
            break;
        case 5:
            sort(colaReproduccion.begin(), colaReproduccion.end(), [](const Cancion& a, const Cancion& b) {
                return a.duration < b.duration;
                });
            cout << "Cola de reproducción ordenada por duración (ascendente)." << endl;
            break;
        case 6:
            sort(colaReproduccion.begin(), colaReproduccion.end(), [](const Cancion& a, const Cancion& b) {
                return a.duration > b.duration;
                });
            cout << "Cola de reproducción ordenada por duración (descendente)." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
            return;
        }
    }
}