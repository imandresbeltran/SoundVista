#pragma once

#include <vector>
#include "Cancion.h"
#include <string>

class CD
{
public:
	std::string name;
	std::vector<Cancion> songs;

	CD(const std::string& n) :  name(n){}

	void addSong(const Cancion& cancion) {
		songs.push_back(cancion);
	}

	std::vector<std::string> getSongNames() const {
		std::vector<std::string> songNames;

		for (const auto& song : songs) {
			songNames.push_back(song.name);
		}

		return songNames;
	}
};

