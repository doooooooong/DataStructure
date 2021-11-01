#include <iostream>
#include <stack>
#include <string>

using namespace std;

void printStack (stack <string> s) {
    stack <string> t;

    while (!s.empty()) {
        cout << s.top() << ' ';
        t.push(s.top());
        s.pop();
    }

    while (!t.empty()) {
        s.push(t.top());
        t.pop();
    }
}

void printStack_fromBottom (stack <string> s) {
    stack <string> t;

    while (!s.empty()) {
        t.push(s.top());
        s.pop();
    }

    while (!t.empty()) {
        cout << t.top() << ' ';
        s.push(t.top());
        t.pop();
    }
}



int main() {
    // int list[] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8 };
    string list[] = { "to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack <string> s;
    for (auto item : list) {
        if (item != "-") s.push(item);
        else {
            cout << s.top() << ' ';
            s.pop();
        }
    }

    cout << "\nsize: " << s.size(); 
    cout << "\ntop: " << s.top();
    cout << "\nstack T: "; printStack(s);
    cout << "\nstack B: "; printStack_fromBottom(s);

    return 0;
}