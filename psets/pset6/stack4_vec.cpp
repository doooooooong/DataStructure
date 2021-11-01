#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Stack {
    vector <string> item;
};

using stack = Stack *;

stack newStack() {
    stack s = new Stack;
    return s;
}

void free (stack s) { delete s; }

int size (stack s) { return s->item.size(); }
bool empty (stack s) { return s->item.empty(); }

string top (stack s) { return s->item.back(); }

void pop (stack s) { s->item.pop_back(); }
void push (stack s, string item) { s->item.push_back(item); }

void printStack (stack s) {
    stack t = newStack();

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
    stack t = newStack();

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

    stack s = newStack();
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