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

    if (!fs::exists(rutaCarpeta) || !fs::is_directory(rutaCarpeta
    )) {
        cout << "La carpeta especificada no existe o no es una carpeta válida." << endl;
        return;
    }
    cout << "Ruta de carpeta cargada: " << rutaCarpeta << endl;

    for (const auto& entry : fs::directory_iterator(rutaCarpeta)) {
        if (entry.is_regular_file()) {
            const string archivo = entry.path().string();

            if (fs::path(archivo).extension() == ".txt") {
                ifstream archivo;
            }
        }
    }
}
void CDManager::agregarCancion() {
    // Implementar la función para agregar una canción a la cola de reproducción
}

void CDManager::verColaReproduccion() {
    // Implementar la función para ver la cola de reproducción
}

void CDManager::reproduccionActual() {
    // Implementar la función para mostrar la reproducción actual
}

void CDManager::reproducirSiguiente() {
    // Implementar la función para reproducir la siguiente canción
}

void CDManager::ordenarCola() {
    // Implementar la función para ordenar la cola de reproducción
}