#include "CDManager.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>


void CDManager::loadBackups(std::string folderPath) {
	for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
		std::ifstream inFile(entry.path());

		if (!inFile) {
			std::cout << "Error al abrir el archivo: " << entry.path() << std::endl;
			continue;
		}

		CD cd(entry.path().filename().string());
		std::string line;

		while (std::getline(inFile, line)) {
			std::istringstream ss(line);
			std::string name, artist, duration;

			if (!std::getline(ss, name, '|') || !std::getline(ss, artist, '|') || !std::getline(ss, duration, '|')) {
				std::cout << "Formato de línea incorrecto en el archivo: " << entry.path() << std::endl;
				break;
			}

			//cd.addSong(Cancion(name, artist, duration));

			if (!cd.songs.empty()) cds.push_back(cd);
			else std::cout << "Error: archivo vacío: " << entry.path() << std::endl;
		}
	}
}