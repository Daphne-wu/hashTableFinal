#pragma once
#include <iostream>
#include <string>
using namespace std;


//create student struct
struct Student {
	char* first = new char();
	char* last = new char();
	int id;
	float gpa;
	Student* next;
	// functions of student
	void setFirst(char* first);
	void setLast(char* last);
};


//have a student list
//when you need to increase the size of hashtable:
// 1. Allocate new array. How many members? studnum * 2
// 2. Delete old array.
// 3. this->studnum *= 2
// 4. this->arr = new array