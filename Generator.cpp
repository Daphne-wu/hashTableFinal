#include "Generator.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

Generator::Generator() {
	ReadFirstName();
	ReadLastName();
}
//reads the first name file txt
void Generator::ReadFirstName() {
  FILE* pfile = NULL;
	char line[20];
	//read the file
	pfile = fopen("FirstNames.txt", "r");
//read through each line til; 20 characters
	while (fgets(line, 20, pfile)) {
		char* position = 0;
		//if its a new line, then position (last character) is null signalling end of cstring
		if ((position = strchr(line, '\n')) != NULL)
		{
			*position = '\0';
		}
		//allocate a new char for first name
		char* firstname = new char[strlen(line) + 1];
				//set memory
		memset(firstname, '\0', strlen(firstname));
		//copy line to naem
		strcpy(firstname, line);
		firstNames.push_back(firstname);
	}

}

//returns random student
Student* Generator::GetRandomStudent(vector<int> &vect){
  Student* student = new Student();
	int randomFirst = rand() % 30;
	int randomLast = rand() % 30;
  student->first = firstNames.at(randomFirst);
	student->last = lastNames.at(randomLast);
	idHolder = 0;
	while (checkID(idHolder, vect) == true) {
		idHolder++;
	}
	student->id = idHolder;
	vect.push_back(idHolder);
	student->gpa = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4.00));
	return student;
}
//verifys the id
bool Generator::checkID(int id, vector<int> vect) {
	for (vector<int>::iterator it = vect.begin(); it != vect.end(); ++it) {
		if (*it == id) {
			return true;
		}
	}
	return false;
}
//reads the first name file txt
void Generator::ReadLastName() {
  FILE* pfile = NULL;
	char line[20];
	pfile = fopen("LastNames.txt", "r");
//read through each line til; 20 characters
	while (fgets(line, 20, pfile)) {
		char* position = 0;
				//if its a new line, then position (last character) is null signalling end of cstring
		if ((position = strchr(line, '\n')) != NULL)
		{
			*position = '\0';
		}
		char* lastName = new char[strlen(line) + 1];
		//set memory
		memset(lastName, '\0', strlen(lastName));
		//copy line to last name
		strcpy(lastName, line);
		lastNames.push_back(lastName);
	}

}

int Generator::hashFunc(char* name, int hashsize) {
	int key = 0;
	int size = strlen(name);
	for (int i = 0; i < size; i = i + 4) {
		key = key + (int)(*name + i);
	}

	key = key % hashsize;
	return key;
}
