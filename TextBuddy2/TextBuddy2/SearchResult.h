#pragma once

#include "stdafx.h"

class SearchResult{
private:
	std::vector<std::string> lines;

public:
	SearchResult();
	~SearchResult();
	void add(std::string line);
	void display();
	std::vector<std::string> getAll();
};

