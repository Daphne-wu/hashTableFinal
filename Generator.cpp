#include "Generator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <vector>


Generator::Generator() {
	ReadFirstName();
	ReadLastName();
}
//reads the first name file txt
void Generator::ReadFirstName() {
  	string line;
	int numOfLines = 30;

	ifstream File("firstNames.txt");
	while(getline(File, line))
	{
	  ++numOfLines;
	  firstNames.push_back(line);
	}

	File.close();
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
  string line;
	int numOfLines = 30;

	//get first name at random number
	ifstream File("lastNames.txt");
	while(getline(File, line))
	{
	  ++numOfLines;
	  lastNames.push_back(line);
	}
	File.close();
}

int Generator::hashFunc(string name, int hashsize) {
	int key = 0;
	int size = name.size();
	for (int i = 0; i < size; i = i + 4) {
		key = key + (int)(name.size() + i);
	}

	key = key % hashsize;
	return key;
}
