#pragma once

#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Song {
public:
	string name;
	string artist;
	string duration;

	Song(const string& Name, const string& Artist, const string& Duration) : name(Name), artist(Artist), duration(Duration) {}
};


class CD
{
public:
	string name;
	vector<Song> songs;

	CD(const string& Name) : name(Name) {}

	void addSong(const Song& song) {
		songs.push_back(song);
	}

	vector<string> getSongNames() const {
		vector<string> songNames;

		for (const auto& song : songs) songNames.push_back(song.name);

		return songNames;
	}
};

