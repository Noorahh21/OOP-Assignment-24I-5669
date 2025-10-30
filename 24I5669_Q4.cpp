#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int customerID;
    string customerName;
    int tickets;
    Node* next;

    Node(int id, string name, int t) {
        customerID = id;
        customerName = name;
        tickets = t;
        next = NULL;
    }
};

class TicketQueue {
private:
    Node* front;
    Node* rear;

public:
    TicketQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int id, string name, int tickets) {
        Node* newNode = new Node(id, name, tickets);
        
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Customer " << name << " added to the queue.\n";
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty!\n";
            
            return;
        }
        Node* temp = front;
        cout << "Serving customer: " << front->customerName << " (" << front->tickets << " tickets)\n";
        front = front->next;
        delete temp;
        if (!front)
            rear = NULL;
    }

    void display() {
        if (!front) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "\nCurrent Queue:\n";
        Node* temp = front;
        while (temp) {
            cout << "Customer ID: " << temp->customerID
                 << ", Name: " << temp->customerName
                 << ", Tickets: " << temp->tickets << endl;
            temp = temp->next;
        }
    }
};

int main() {
    TicketQueue q;
    q.enqueue(1, "Saria", 2);
    q.enqueue(2, "Sara", 4);
    q.enqueue(3, "Aleena", 1);
    q.display();

    cout << "\nServing Customers\n";
    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}

