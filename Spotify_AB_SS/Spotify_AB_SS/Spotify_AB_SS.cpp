#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <windows.h>
#include <limits>
#include <vector>
#include <string>
#include <algorithm>
#include <string>

//#include "CDManager.h"

using namespace std;

class Cancion {
	string name;
	string artist;
	string duration;
};

class CD {
public:
	string nameCD;
	vector<Cancion> songs;
};
class MP3
{
	vector<CD>CDs;
	vector<Cancion>Cola;
	Cancion* reproduciendo = nullptr;

public:
	MP3(){}
	void cargandoRespaldos() {
		
		cout << "Porfavor ingrese la ruta de la carpeta de respaldos:" << endl;
		string direccion;
		cin.ignore();
		getline(cin, direccion);
		/*vector<string>archivos = listarArchivos(direccion);
		if (archivos.empty()) {
			cout << "No se encontró ningun archivo en la ruta brindada.\n" << endl;
			return;
		}*/

		/*for (const auto& archivo : archivos)
		{
			cout << "Procesando CD..." << archivo << endl;
			CD cd = cargarCDs(direccion + "/" + archivo);
			if (!cd.nameCD.empty())
			{
				CDs.push_back(cd); cout << "Archivo: " << cd.nameCD << ", encontrado." << endl;
				Sleep(2000);
			}
			else {
				cout << "¡¡¡Archivo cargado incorrectamente!!!: " << archivo << endl;
			}
		}*/


		/*CD cargarCDs(const string & ruta_de_archivo) {
			ifstream archivo(ruta_de_archivo);
			if (!archivo.is_open())
			{
				throw runtime_error("El archivo solicitado no pudo abrirse: " + ruta_de_archivo)
			}
			CD cd;
			cd.nameCD = filesystem::path(ruta_de_archivo).filename().replace_extension().string();
			string linea;
			while (getline(archivo,linea))
			{
				stringstream ss(linea);
				string nombre, artista, duracion;
				getline(ss, nombre, '|');
				getline(ss, nombre, '|');
				getline(ss, nombre, '|');

				Cancion song;
				song.name = name;
				song.artist=artist;

				cd.songs.push_back(songs);
			}
			archivo.close();
			return cd;
		}*/
		

		/*vector<string>listarArchivos(const string& direccion); {
			vector<string>archivos;
			for (const auto& entry : filesystem::directory_iterator(direccion))
			{
				if (entry.is_regular_file() && entry.path().extension() == ".txt") {
					archivos.push_back(entry.path().filename().string());
				}
			}
			return archivos;
		}*/		
	}

};



void reproductor_Canciones() {
	
	menu2:
	int opcion;
	std::cout << "\t1. Agregar Cancion." << std::endl;
	std::cout << "\t2. Ver Cola de Reproduccion" << std::endl;
	std::cout << "\t3. Ordenar" << std::endl;
	std::cout << "\t4. Reproduccion Actual" << std::endl;
	std::cout << "\t5. Reproducir Siguiente" << std::endl;
	std::cout << "\t6. Volver al menu principal" << std::endl;
	std::cout << "Elige una opcion:" << std::endl; std::cin >> opcion;
	switch (opcion)
	{
	case 1:std::cout << "Haz seleccionado agregar Canción." << std::endl;	
		
		// Pausar y esperar que el usuario presione enter para continuar
		/*std::cout << "\nPresione ENTER para continuar...";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();*/
		system("cls");
		break;
	case 2:std::cout << "Haz seleccionado Ver Cola de Reproduccion." << std::endl;
		system("cls");
		break;
	case 3:std::cout << "Ordenar." << std::endl;
		system("cls");
		break;
	case 4:std::cout << "Haz seleccionado Reproduccion Actual." << std::endl;
		system("cls");
		break;
	case 5:std::cout << "Haz seleccionado Reproducir Siguiente." << std::endl;
		system("cls");
		break;
	case 6:std::cout << "Haz seleccionado Volver al menu principal." << std::endl;
		system("cls");
		return;
	default:std::cout << "Opcion no valida, vuelte a intentar." << std::endl;
		std::cin.get();
		Sleep(1500);
		system("cls");
		goto menu2;		
	}
}

int main()
{
	MP3 reproductor;
#pragma region Menu interfaz
	menu:
	int opcion;
	std::cout << "-----------------------------------SPOTIFY-------------------------------------\nPorfavor Seleccione una opcion"<< std::endl;
	std::cout << "\t1. Cargar respaldo de archivos" << std::endl;
	std::cout << "\t2. Reproducir Canciones" << std::endl;
	std::cout << "\t3. Salir del programa" << std::endl;
	std::cout << "SELECCIONE UNA OPCION:" << std::endl; 
	
	while (!(std::cin >> opcion)) {
		/*std::cout << "Por favor, ingrese un número válido: ";
		std::cin.clear(); // Limpia el estado de error de cin
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora caracteres inválidos en el búfer*/
	}

	switch (opcion)
	{
	case 1: std::cout<<"Haz seleccionado Cargar respaldo de archivos\n";
		Sleep(2000);
		system("cls");//esto Limpiara la consola
		reproductor.cargandoRespaldos();
		break;

	case 2: std::cout << "Haz seleccionado Reproducir Canciones\n";
		Sleep(2000);
		system("cls");//esto Limpiara la consola
		reproductor_Canciones();
		
		goto menu;
		

	case 3: std::cout<<"Haz elegido salir del programa, adios." << std::endl;
		return 0;

	default:std::cout << "Opcion no valida, vuelte a intentar." << std::endl;
		std::cin.get();
		Sleep(1500);
		system("cls");//esto Limpiara la consola
		goto menu;//Llevara devuelta al usuario al principio del menu
		
	}
#pragma endregion
/*
	CDManager collection;

	std::string folderPath;
	std::cout << "Por favor, introduce la ruta a la carpeta con los respaldos: ";
	std::getline(std::cin, folderPath);

	collection.loadBackups(folderPath);
	*/
	
	

	return 0;


	
    

}

