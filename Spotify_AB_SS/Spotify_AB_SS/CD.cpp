#include "CD.h"
#include <algorithm>
#include <iostream>

CD::CD(std::string Name) : name(Name) {}

void CD::addSong(Cancion c) {
	if (std::find(songs.begin(), songs.end(), c) != songs.end()) std::cout << "Error: canción duplicada en el CD: " << name << std::endl;
	else songs.push_back(c);

}