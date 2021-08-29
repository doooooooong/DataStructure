// On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// 서명: ___강동인_______ 학번: ____21500002___


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void printfunc(int n, char *names[]);

int main(int argc, char **argv) {
    string str;

    if (argc > 1) printfunc(argc, argv);
      
    else {
        while (1) {
            cout << "Enter your name: ";
            getline(cin, str);

            if (str.length()) cout << "Hello " << str << "!\n";
            else break;

            if (cin.eof()) break;
        }
    }

    cout << "Hello World!\n";

    return 0;
}