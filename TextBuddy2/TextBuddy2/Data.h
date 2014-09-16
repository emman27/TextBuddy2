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

	void add(std::string line);
	std::string get(int lineNum);
	void del(unsigned int lineNum);
	void clear();
	void display();
	void search(std::string toFind);
	void sort();
};

