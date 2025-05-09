#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *head = NULL;

void insert(int x);
void display();
void deleteList();

int main() {
    int choice, x;
    do {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Delete List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> x;
                insert(x);
                break;
            case 2:
                display();
                break;
            case 3:
                deleteList();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while(choice != 4);

    return 0;
}

void insert(int x) {
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        node *temp2 = head;
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}

void display() {
    node *temp = head;
    if (head == NULL) {
        cout << "No data" << endl;
    } else {
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

void deleteList() {
    node *temp = head;
    while (temp != NULL) {
        node *next = temp->next;
        delete temp;
        temp = next;
    }
    head = NULL;
    cout << "Linked list deleted" << endl;
}
