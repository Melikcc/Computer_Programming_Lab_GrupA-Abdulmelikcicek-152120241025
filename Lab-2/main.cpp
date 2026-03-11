#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* head = NULL;

void appendWord(string word) {
    Node* newNode = new Node;
    newNode->data = word;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}
void undoLast() {
    if (head == NULL) {
        cout << "Nothing to undo.\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}
void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {

    string input;

    while (true) {
        cout << "Enter word: ";
        cin >> input;

        if (input == "EXIT") {
            break;
        }

        if (input == "UNDO") {
            undoLast();
        } else {
            appendWord(input);
        }

        display();
    }

    return 0;
}
