// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
#include <iostream>
#include <vector>
#include <string>

void printfunc(int n, char *names[]) {
	for (int i = 1; i < n; i++)
		std::cout << "Hello " << names[i] << "!" << std::endl;
}

void printfunc(std::vector<std::string> names) {
	for (int i = 0; i < names.size(); i++)
		std::cout << "Hello " << names[i] << "!" << std::endl;
}
