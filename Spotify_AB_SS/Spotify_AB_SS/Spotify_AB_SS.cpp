
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
#pragma region Menu interfaz
	menu:
	int opcion;
	cout << "-----------------------------------SPOTIFY-------------------------------------\nPorfavor Seleccione una opcion"<< endl; 
	cout << "\t1. Cargar respaldo de archivos" << endl;
	cout << "\t2. Reproducir Canciones" << endl;
	cout << "SELECCIONE UNA OPCION:" << endl; cin >> opcion;	

	switch (opcion)
	{
	case 1: cout<<"Haz seleccionado Cargar respaldo de archivos\n";
		break;
	case 2: cout << "Haz seleccionado Reproducir Canciones\n";
		break;
	default:cout << "Opci�n no v�lida, vuelte a intentar. Presione cualquier tecla para continuar" << endl;
		cin.get();
		system("cls");//esto Limpiar� la consola
		goto menu;//Llevara devuelta al usuario al principio del menu
		break;
	}
#pragma endregion

    
}

