#pragma once
#include <unordered_map>
#include <vector>
#include "student.h"

using namespace std;
class Generator
{
public:
	Generator();
	// holder for id number
	int idHolder;
	// vector that holds the first and last names of students from file
	vector<char*> firstNames;
	vector<char*> lastNames;
	// generates the first and last name vectors
	void ReadFirstName();
	void ReadLastName();
	// generates a random student with the first and last name vectors wile increasing the ID, genorating a random GPA
	Student* GetRandomStudent(vector<int> &vect);
	// checks the id to makesure it doesnt repeat
	bool checkID(int id, vector<int> vect);
	//hashes the first name of studnet
	int hashFunc(char* name, int hashsize);
};
