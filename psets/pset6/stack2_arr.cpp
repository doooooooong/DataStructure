#include <iostream>
#include <string>

using namespace std;


struct Stack {
    string *item;
    int N;
    int capacity;
};

using stack = Stack *;

stack newStack(int capacity) {
    stack s = new Stack;
    s->item = new string[capacity];
    s->N = 0;
    s->capacity = capacity;

    return s;
}

void free (stack s) {
    delete[] s->item;
    delete s;
}

int size (stack s) { return s->N; }
bool empty (stack s) { return s->N == 0; }

string top (stack s) { return s->item[s->N - 1]; }

void pop (stack s) { s->N--; }
void push (stack s, string item) { s->item[s->N++] = item; }

void printStack (stack s) {
    stack t = newStack(20);

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

void printStack_fromBottom (stack s) {
    stack t = newStack(20);

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

    stack s = newStack(20);
    for (auto item : list) {
        if (item != "-") {
            push(s, item);
            cout << "push " << item << endl;
        }
        else {
            cout << "pop " << top(s) << endl;
            pop(s);
        }

        cout << "current stack: "; printStack(s);
        cout << endl;
    }

    cout << "\nsize: " << size(s); 
    cout << "\ntop: " << top(s);
    cout << "\nstack T: "; printStack(s);
    cout << "\nstack B: "; printStack_fromBottom(s);

    return 0;
}