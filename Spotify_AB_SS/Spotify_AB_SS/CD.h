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

	Song(const string& Name, const string& Artist, const string& Duration) {}
};


class CD
{
public:
	string name;
	vector<Song> songs;

	CD(const string& Name){}

};

