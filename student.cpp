#include "hashTable.h"
#include <cstring>
#pragma warning(disable : 4996)

void Student::setFirst(char* first1) {
	first = new char[strlen(first1) + 1];
	strcpy(first, first1);
}

void Student::setLast(char* last1) {
	last = new char[strlen(last1) + 1];
	strcpy(last, last1);
}