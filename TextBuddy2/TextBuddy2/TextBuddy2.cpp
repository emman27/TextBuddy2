// TextBuddy2.cpp : Defines the entry point for the console application.
//

#include "Data.h"

void engageUser(Data &textFile);
void executeUserCommand(Commands command, Data &textFile);

int main(int argc, char* argv[]){
	std::string fileName = confirmFile(argc, argv);
	printMessage(MESSAGE_WELCOME);
	Data textFile(fileName);
	engageUser(textFile);
	return 0;
}

void engageUser(Data &textFile){
	std::map<std::string, Commands> commandMap = setupMap();
	std::string command = "";
	while(command!=USER_COMMAND_EXIT){
		command = prompt("command");
		executeUserCommand(commandMap[command], textFile);
	}
}

void executeUserCommand(Commands command, Data &textFile){
	std::string line;
	unsigned int lineNum;
	switch(command){
		case ADD :
			std::cin.ignore(); //need to get rid of weird characters from input
			getline(std::cin, line); //then read the rest of the things that were meant to be added
			textFile.add(line);
			break;

		case DELETE :
			std::cin >> lineNum;
			textFile.del(lineNum);
			break;

		case CLEAR :
			textFile.clear();
			break;

		case DISPLAY :
			textFile.display();
			break;

		case SEARCH :
			std::cin.ignore();
			getline(std::cin, line);
			textFile.search(line);
			break;

		case SORT:
			textFile.sort();
			break;

		case EXIT:
			NULL; // no need to take action
			break;

		default :
			getline(std::cin, line); // clears the extra line leftover from the wrong command
			printErrorMessage("Command not recognised");
	}
	textFile.saveFile();
}