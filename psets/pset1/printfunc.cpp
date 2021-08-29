#include <iostream>

void printfunc (int n, char *names[]) {
    for (int i = 0; i < n; i++) {
        std:: cout << "Hello " << names[i] << "!" << std::endl;
    }
}