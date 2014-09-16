#include "Data.h"

Data::Data(){
}

Data::Data(std::string fileTitle){
	fileName = fileTitle;
	readFile();
}

Data::~Data(void){
}

void Data::readFile(){
	std::string line;
	std::fstream file;
	file.open(fileName.c_str(), std::ios_base::in);
	while(getline(file, line)){
		lines.push_back(line);
	}
	file.close();
}

void Data::saveFile(){
	std::fstream file;
	file.open(fileName.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
	for(unsigned int i = 0; i < lines.size(); i++){
		file << lines[i] << std::endl;
	}
	file.close();
}

std::string Data::getFileName(){
	return fileName;
}

void Data::add(std::string line){
	lines.push_back(line);
	printMessage("Added to " + fileName +": " + line);
}

void Data::del(unsigned int lineNum){
	if(lineNum > lines.size() || lineNum <= 0){
		printErrorMessage("Invalid input");
	}
	else{
		printMessage("Removed from " + fileName +": " + lines[lineNum]);
		lines.erase(lines.begin() + lineNum - 1);
	}
}

void Data::clear(){
	printMessage("All content deleted from " + fileName);
	lines.clear();
}

void Data::display(){
	for(unsigned int i = 0; i < lines.size(); i++){
		std::cout << i+1 << ". " << lines[i] << std::endl;
	}
}

void Data::search(std::string toFind){
	SearchResult searchResults;
	for(unsigned int i = 0; i < lines.size(); i++){
		if(isInString(lines[i], toFind)){
			std::string line = i + ". " + lines[i];
			searchResults.add(line);
		}
	}
	printMessage("Search results: ");
	searchResults.display();
}

void Data::sort(){

}
