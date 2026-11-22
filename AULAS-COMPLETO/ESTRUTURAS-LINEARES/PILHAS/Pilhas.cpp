#include <iostream>
#include <string>

using namespace std;

struct No {
    char data;
    No* next;

    No(char value, No* p = nullptr) : data(value), next(p) {}
};

struct Stack {
    No* top = nullptr;
    int size = 0;
};


// Push
void push(Stack& stack, char value) {
    stack.top = new No(value, stack.top);
    stack.size++;
}

// Pop
bool pop(Stack& stack, char& value) {
    if (!stack.top)
        return false;

    No* temp = stack.top;
    value = temp->data;

    stack.top = temp->next;
    delete temp;

    stack.size--;
    return true;
}

// Peek
void peek(const Stack& stack) {
    if (!stack.top) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top: " << stack.top->data << endl;
}

// isEmpty
bool isEmpty(const Stack& stack) {
    return stack.top == nullptr;
}

// getSize
int getSize(const Stack& stack) {
    return stack.size;
}

// Reverse word
void reverseWord(string word) {
    Stack stack;

    for (char c : word)
        push(stack, c);

    cout << "Reversed: ";

    char c;
    while (pop(stack, c))
        cout << c;

    cout << "\n";
}

void clear(Stack& stack) {
    char temp;
    while (pop(stack, temp));
}

int main() {
    Stack stack;

    push(stack, 'A');
    push(stack, 'B');

    char c;
    pop(stack, c);

    push(stack, 'C');

    peek(stack);
    cout << "Size: " << getSize(stack) << "\n";
    cout << "Empty? " << isEmpty(stack) << "\n";

    pop(stack, c);
    cout << "Removed: " << c << "\n";

    reverseWord("HELLO");

    clear(stack);

    return 0;
}