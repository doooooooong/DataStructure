// 4. a logic error


#include <iostream>
using namespace std;


// 1. adding two line
#if 1
int main() {
    int a;
    int *pi;
    pi = &a;
    *pi = 17;
    cout << "i = " << *pi << endl;
    return 0;
}

// 2. using new and delete
#else

int main() {
    int *pi;
    pi = new int;
    *pi = 17;
    cout << "i = " << *pi << endl;
    delete pi; 
    return 0;
}


#endif

