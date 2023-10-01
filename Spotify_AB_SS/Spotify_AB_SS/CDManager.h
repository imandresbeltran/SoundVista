#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "CD.h"

class CDManager
{
public:
	std::vector<CD> cds;

	void loadBackups(std::string folderPath);
};

