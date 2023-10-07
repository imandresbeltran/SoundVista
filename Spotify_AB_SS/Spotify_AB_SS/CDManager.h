#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "CD.h"

class CDManager
{
public:

	CDManager();

	void cargarRespaldos(const std::string& rutaCarpeta);
	void agregarCancion();
	void verColaReproduccion();
	void reproduccionActual();
	void reproducirSiguiente();
	void ordenarCola();

private:
	std::vector<CD> listaCDs;
	std::vector<Cancion> colaReproduccion;

	Cancion cancionEnReproduccion;
};

