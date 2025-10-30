#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char val) {
        data = val;
        next = NULL;
    }
};

class LinkedListStack {
private:
    Node* top;
public:
    LinkedListStack() {
        top = NULL;
    }

    void push(char val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!top) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    char peek() {
        if (!top) return '\0';
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

class ArrayStack {
private:
    char* arr;
    int top;
    int capacity;
public:
    ArrayStack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }

    void push(char val) {
        if (top == capacity - 1) return;
        arr[++top] = val;
    }

    void pop() {
        if (top == -1) return;
        top--;
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

void ChangeLocationIterative(char arr[], int b1, int b2) {
    LinkedListStack s;
    for (int i = b1; i <= b2; i++) {
        s.push(arr[i]);
    }
    for (int i = b1; i <= b2; i++) {
        arr[i] = s.peek();
        s.pop();
    }
}

void PrintPatternIterative(int n) {
    ArrayStack s(n * n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            s.push('1');
        }
        while (!s.isEmpty()) {
            cout << s.peek() << " ";
            s.pop();
        }
        cout << endl;
    }
}

int main() {
   

    char arr[8] = {'C','O','M','P','U','T','E','R'};
    cout << "Original Array: ";
    for (int i = 0; i < 8; i++) cout << arr[i] << " ";
    cout << endl;

    ChangeLocationIterative(arr, 2, 6);
    cout << "After ChangeLocation (Iterative): ";
    for (int i = 0; i < 8; i++) cout << arr[i] << " ";
    cout << endl << endl;

    int n = 4;
    cout << "Pattern for n = " << n << " (Iterative):" << endl;
    PrintPatternIterative(n);

  
    return 0;
}


