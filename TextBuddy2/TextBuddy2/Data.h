#pragma once

#include <fstream>
#include "stdafx.h"
#include "SearchResult.h"
#include <algorithm>
#include <sstream>

class Data{

protected:
	std::vector<std::string> lines;
	std::string fileName;

public:
	Data();
	Data(std::string fileTitle);
	~Data(void);
	
	void readFile();
	void saveFile();
	
	std::string getFileName();
	std::string get(int lineNum);
	int getSize();
	std::vector<std::string> getAll();

	void add(std::string line);
	void del(unsigned int lineNum);
	void clear();
	void display();
	SearchResult search(std::string toFind);
	void sort();
};

