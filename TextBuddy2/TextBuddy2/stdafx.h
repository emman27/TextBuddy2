// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>



// TODO: reference additional headers your program requires here

enum Commands{
	ADD = 1,
	DELETE = 2,
	CLEAR = 3,
	DISPLAY = 4,
	SEARCH = 5,
	SORT = 6,
	EXIT = 7
};

static const std::string MESSAGE_WELCOME = "Welcome to TextBuddy 2!";
static const std::string MESSAGE_ERROR = "There has been an error: ";

static const int EXPECTED_ARG_NUMBER = 2;
static const int POSITION_FILENAME = 1;
static const int MIN_STR_LEN = 4;
static const std::string TXT_EXTENSION = ".txt";

static const std::string USER_COMMAND_ADD = "add";
static const std::string USER_COMMAND_DELETE = "delete";
static const std::string USER_COMMAND_CLEAR = "clear";
static const std::string USER_COMMAND_DISPLAY = "display";
static const std::string USER_COMMAND_SEARCH = "search";
static const std::string USER_COMMAND_SORT = "sort";
static const std::string USER_COMMAND_EXIT = "exit";

bool isFileSpecified(int n);
std::string getFileName();
bool isLegit(std::string filename);

std::string prompt(std::string msg);
void printMessage(std::string msg);
void printErrorMessage(std::string msg);

std::string confirmFile(int i, char* argv[]);

std::map<std::string, Commands> setupMap();

bool isInString(std::string string, std::string substring);


