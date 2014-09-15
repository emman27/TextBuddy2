// TextBuddy2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

static const std::string MESSAGE_WELCOME = "Welcome to TextBuddy 2!";
static const std::string MESSAGE_ERROR = "TextBuddy does not understand the command ";

static const int EXPECTED_ARG_NUMBER = 2;
static const int POSITION_FILENAME = 1;

bool isFileSpecified(int n);
std::string getFileName();

int main(int argc, char* argv[])
{
	std::string fileName;
	std::vector<std::string> data;

	while(!isFileSpecified){
	
	return 0;
}

bool isFileSpecified(int n){
	return n == EXPECTED_ARG_NUMBER;
}

std::string getFileName(){

}