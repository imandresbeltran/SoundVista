
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <sstream>
#include "CDManager.h"

int main()
{
#pragma region Menu interfaz
	menu:
	int opcion;
	std::cout << "-----------------------------------SPOTIFY-------------------------------------\nPorfavor Seleccione una opcion"<< std::endl;
	std::cout << "\t1. Cargar respaldo de archivos" << std::endl;
	std::cout << "\t2. Reproducir Canciones" << std::endl;
	std::cout << "SELECCIONE UNA OPCION:" << std::endl; 
	std::cin >> opcion;

	switch (opcion)
	{
	case 1: std::cout<<"Haz seleccionado Cargar respaldo de archivos\n";
		break;
	case 2: std::cout << "Haz seleccionado Reproducir Canciones\n";
		break;
	default:std::cout << "Opcion no valida, vuelte a intentar. Presione cualquier tecla para continuar" << std::endl;
		std::cin.get();
		system("cls");//esto Limpiar� la consola
		goto menu;//Llevara devuelta al usuario al principio del menu
		break;
	}
#pragma endregion

#pragma region agregarCD
	CDManager collection;

	std::string folderPath;
	std::cout << "Por favor, introduce la ruta a la carpeta con los respaldos: ";
	std::getline(std::cin, folderPath);

	collection.loadBackups(folderPath);

	return 0;
    
}

