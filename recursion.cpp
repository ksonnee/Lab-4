#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int>& s, int item) {
    if (s.empty()) {
        s.push(item);
        return;
    }

    int temp = s.top();
    s.pop();
    insertAtBottom(s, item);

    s.push(temp);
}

void reverseStack(stack<int>& s) {
    if (!s.empty()) {
        int temp = s.top();
        s.pop();

        reverseStack(s);

        insertAtBottom(s, temp);
    }
}

void printStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }

    int temp = s.top();
    s.pop();
    cout << temp << " ";

    printStack(s);

    s.push(temp);
}

int main() {
    stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    cout << "Original Stack:" << endl;
    printStack(myStack);
    cout << endl;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    reverseStack(myStack);

    cout << "Reversed Stack:" << endl;
    printStack(myStack);
    cout << endl;

    return 0;
}
