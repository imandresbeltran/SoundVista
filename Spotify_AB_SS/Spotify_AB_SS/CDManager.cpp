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
    cout << "Ruta de carpeta cargada: " << rutaCarpeta << endl;
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