#include <iostream>
#include <string>
using namespace std;


class Feature {
public:
    string Name;

    Feature() {             
        Name = "";
    }

    Feature(string n) {    
        Name = n;
    }

    virtual void analyze() {   
        cout << "Generic Feature: " << Name << endl;
    }
};


class LandFeature : public Feature {
public:
    LandFeature(string n) {  
        Name = n;
    }

    void analyze() override {
        cout << "Land Feature Detected: " << Name << endl;
    }
};

class WaterFeature : public Feature {
public:
    WaterFeature(string n) {
        Name = n;
    }

    void analyze() override {
        cout << "Water Feature Detected: " << Name << endl;
    }
};


class Node {
public:
    int FeatureID;
    Feature* feature;
    Node* next;

    Node(int id, Feature* f) {
        FeatureID = id;
        feature = f;
        next = NULL;
    }
};


class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

   
    void insertAtEnd(int id, Feature* f) {
        Node* newNode = new Node(id, f);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

  
    void deleteByID(int id) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->FeatureID == id) {
            head = head->next;
            cout << "Feature ID " << id << " deleted."<<endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->FeatureID != id)
            temp = temp->next;

        if (temp->next != NULL) {
            temp->next = temp->next->next;
            cout << "Feature ID " << id << " deleted.\n";
        } else {
            cout << "Feature ID " << id << " not found.\n";
        }
    }


    void displayAll() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << "[ID: " << temp->FeatureID << "] ";
            temp->feature->analyze();
            temp = temp->next;
        }
    }

 
    void reverseList() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }
};


int main() {
    SinglyLinkedList list;

    list.insertAtEnd(1, new LandFeature("Forest"));
    list.insertAtEnd(2, new WaterFeature("Ocean"));
    list.insertAtEnd(3, new LandFeature("Mountain"));

    cout << "Original List"<<endl;
    list.displayAll();

    cout << "\nDeleting Feature ID 3\n";
    list.deleteByID(3);
    list.displayAll();

    cout << "\nReversing List\n";
    list.reverseList();
    list.displayAll();

    return 0;
}

