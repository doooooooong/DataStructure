#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
struct Stack {
    vector <T> item;
};

template <typename T>
using stack = Stack<T> *;

template <typename T>
stack<T> newStack() {
    return new Stack<T>;
}

template <typename T>
void free (stack<T> s) { delete s; }

template <typename T>
int size (stack<T> s) { return s->item.size(); }

template <typename T>
bool empty (stack<T> s) { return s->item.empty(); }

template <typename T>
T top (stack<T> s) { return s->item.back(); }

template <typename T>
void pop (stack<T> s) { s->item.pop_back(); }

template <typename T>
void push (stack<T> s, T item) { s->item.push_back(item); }

template <typename T>
void printStack (stack<T> s) {
    stack<T> t = newStack<T>();

    while (!empty(s)) {
        cout << top(s) << ' ';
        push(t, top(s));
        pop(s);
    }

    while (!empty(t)) {
        push(s, top(t));
        pop(t);
    }

    free(t);
}

template <typename T>
void printStack_fromBottom (stack<T> s) {
    stack<T> t = newStack<T>();

    while (!empty(s)) {
        push(t, top(s));
        pop(s);
    }

    while (!empty(t)) {
        cout << top(t) << ' ';
        push(s, top(t));
        pop(t);
    }

    free(t);
}

int main() {
    // int list[] = { 1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 8 };
    string list[] = { "to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};

    stack <string> s = newStack <string>();
    for (auto item : list) {
        if (item != "-") {
            push(s, item);
        }
        else {
            cout << top(s) << ' ';
            pop(s);
        }
    }

    cout << "\nsize: " << size(s);
    cout << "\ntop: " << top(s);
    cout << "\nstack T: "; printStack(s);
    cout << "\nstack B: "; printStack_fromBottom(s);

    return 0;
}