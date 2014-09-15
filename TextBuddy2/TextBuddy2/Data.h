#pragma once

#include <fstream>
#include "stdafx.h"

class Data{

private:
	std::vector<std::string> lines;
	std::string fileName;

public:
	Data(std::string fileTitle);
	~Data(void);
	
	void readFile();
	void saveFile();
	
	void add(std::string line);
	std::string get(int lineNum);
	void del(int lineNum);
	void clear();
	void display();

	std::string search(std::string toFind);
	void sort();
};

