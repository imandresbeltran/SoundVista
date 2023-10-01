#include "Cancion.h"

Cancion::Cancion(std::string Name, std::string Artist, std::string Duration)
	: name(Name), artist(Artist), duration(Duration) {}

bool Cancion::operator==(const Cancion& other) const {
	return name == other.name && artist == other.artist && duration == other.duration;
}
