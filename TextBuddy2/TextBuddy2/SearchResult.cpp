#include "SearchResult.h"


SearchResult::SearchResult()
{
}


SearchResult::~SearchResult(){
}

void SearchResult::add(std::string line){
	lines.push_back(line);
}

void SearchResult::display(){
	for(unsigned int i = 0; i < lines.size(); i++){
		printMessage(lines[i]);
	}
}

std::vector<std::string> SearchResult::getAll(){
	return lines;
}
