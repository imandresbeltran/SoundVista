#pragma once
#include <string>

class Cancion
{
public:
	std::string name;
	std::string artist;
	std::string duration;

	Cancion() = default; //Agregamos un constructor predeterminado

	Cancion(std::string Name, std::string Artist, std::string Duration)
		: name(Name), artist(Artist), duration(Duration) {}
};

