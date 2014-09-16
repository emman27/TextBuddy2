// stdafx.cpp : source file that includes just the standard includes
// TextBuddy2.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file




std::string confirmFile(int i, char* argv[]){
	std::string fileName = "";
	if(isFileSpecified(i)){
		return argv[POSITION_FILENAME];
	}
	while(!isFileSpecified(i)){
		fileName = getFileName();
		if(isLegit(fileName)){
			i = EXPECTED_ARG_NUMBER;
			return fileName;
		}
		else{
			printErrorMessage("Filename invalid");
		}
	}
	return "";
}

bool isFileSpecified(int n){
	return n == EXPECTED_ARG_NUMBER;
}

std::string getFileName(){
	return promptMultipleWords("Please enter a filename");
}

std::string prompt(std::string msg){
	std::string s;
	std::cout << msg << ": ";
	std::cin >> s;
	return s;
}

std::string promptMultipleWords(std::string msg){
	std::string s;
	std::cout << msg << ": ";
	getline(std::cin, s);
	return s;
}


void printMessage(std::string msg){
	std::cout << msg << std::endl;
}

void printErrorMessage(std::string msg){
	std::cout << MESSAGE_ERROR << msg << std::endl;
}

bool isLegit(std::string fileName){
	unsigned int len = fileName.length();
	if(!fileName.empty() && len>MIN_STR_LEN){
		return fileName.substr(len-MIN_STR_LEN, len) == TXT_EXTENSION;
	}
	else{
		return false;
	}
}

std::map<std::string, Commands> setupMap(){
	std::map<std::string, Commands> commandMap;
	commandMap[USER_COMMAND_ADD] = ADD;
	commandMap[USER_COMMAND_DELETE] = DELETE;
	commandMap[USER_COMMAND_CLEAR] = CLEAR;
	commandMap[USER_COMMAND_DISPLAY] = DISPLAY;
	commandMap[USER_COMMAND_SEARCH] = SEARCH;
	commandMap[USER_COMMAND_SORT] = SORT;
	commandMap[USER_COMMAND_EXIT] = EXIT;
	return commandMap;
};

bool isInString(std::string string, std::string substring){
	return string.find(substring) != string.npos;
}