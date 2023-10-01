#pragma once

#include <vector>
#include "Cancion.h"

class CD
{
public:
	std::string name;
	std::vector<Cancion> songs;

	CD(std::string Name);
	void addSong(Cancion c);
};

