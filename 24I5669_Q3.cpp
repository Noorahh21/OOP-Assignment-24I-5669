

#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    int BookID;
    string Title;
    string Author;
    Node* prev;
    Node* next;

    Node(int id, string t, string a) {
        BookID = id;
        Title = t;
        Author = a;
        prev = NULL;
        next = NULL;
    }
};


class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    
    void addAtBeginning(int id, string title, string author) {
        Node* newNode = new Node(id, title, author);
        if (head == NULL) {
            head = tail = newNode;
        }
		 else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }


    void addAtEnd(int id, string title, string author) {
        Node* newNode = new Node(id, title, author);
        
        if (tail == NULL) {
            head = tail = newNode;
        }
		 else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }


    void addAtPosition(int pos, int id, string title, string author) {
        if (pos <= 1 || head == NULL) {
        	
            addAtBeginning(id, title, author);
            
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp->next != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL) {
            addAtEnd(id, title, author);
            return;
        }

        Node* newNode = new Node(id, title, author);
        newNode->next = temp->next;
        
        newNode->prev = temp;
        
        temp->next->prev = newNode;
        
        temp->next = newNode;
    }

   

    void deleteByID(int id) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->BookID != id) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Book ID " << id << " not found.\n";
            return;
        }

        
        if (temp == head) {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL; 
        }
       
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = NULL;
        }
       
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Book ID " << id << " deleted.\n";
    }

   
    void displayForward() {
        if (head == NULL) {
            cout << "Library is empty.\n";
            return;
        }

        cout << "\nBooks in Order:\n";
        Node* temp = head;
        while (temp != NULL) {
            cout << "ID: " << temp->BookID
                 << ", Title: " << temp->Title
                 << ", Author: " << temp->Author << endl;
            temp = temp->next;
        }
    }

   
    void displayBackward() {
        if (tail == NULL) {
            cout << "Library is empty.\n";
            return;
        }

        cout << "\nBooks in Reverse Order:\n";
        Node* temp = tail;
        while (temp != NULL) {
            cout << "ID: " << temp->BookID
                 << ", Title: " << temp->Title
                 << ", Author: " << temp->Author << endl;
            temp = temp->prev;
        }
    }
};

int main() {
    DoublyLinkedList library;

    
    library.addAtBeginning(101, "Three cups of tea", "David");
    library.addAtEnd(102, "1984", "George");
    library.addAtEnd(103, "Pakistan :A hard country", "ali");
    library.addAtPosition(2, 104, "Harry Potter", "J.K.");

    
    library.displayForward();
    library.displayBackward();


    cout << "\nDeleting book with ID 103\n";
    library.deleteByID(103);


    library.displayForward();
    library.displayBackward();

    return 0;
}


