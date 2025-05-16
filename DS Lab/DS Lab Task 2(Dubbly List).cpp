#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int Value) {
        data = Value;
        next = NULL;
        prev = NULL;
    }
};
struct Node* head = NULL;
struct Node* tail = NULL;

void InsertIntoLast(int Value) {
    Node* newNode = new Node(Value);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void InsertIntoFirst(int value){
    Node* newNode = new Node(value);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

}
void DeleteFromFirst(){
    if(head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if(head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL; 
    }
    delete temp;
}
void DeleteFromLast(){
    if(tail == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    if(tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL; 
    }
    delete temp;
}
void Display(){
    Node* current = head;
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void ReverseDisplay() {
    Node* current = tail;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

int main(){
    //Insert value into last of the dobbly Linked List
    InsertIntoLast(10);
    InsertIntoLast(20);
    InsertIntoLast(30);
    InsertIntoLast(40);
    
    //Display the list
    cout<< "list after inserting into last: ";
    Display();
    cout<<endl;

    //insert value into first of the dobbly Linked List
    InsertIntoFirst(5);
    InsertIntoFirst(2);
    InsertIntoFirst(1);
    
    cout<< "list after inserting into first: ";
    Display();
    cout<<endl;
    
    cout << "list after deleting from first: ";
    DeleteFromFirst();
    Display();
    cout << endl;

    cout<< "list after deleting from last: ";
    DeleteFromLast();
    Display();
    cout << endl;

    cout << "Reverse display of the list: ";
    ReverseDisplay();
    cout << endl;
    cout << "Display of the list: ";
    Display();
    cout << endl;

    return 0;
}
