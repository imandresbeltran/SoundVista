#pragma once
#include <string>

class Cancion
{
public:
	std::string name;
	std::string artist;
	std::string duration;

	Cancion(std::string Name, std::string Artist, std::string Duration);

	bool operator == (const Cancion& other) const;
};

