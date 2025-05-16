#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int Value){
        data = Value;
        next = NULL;
    }
};

struct Node* head = NULL;

void Insert(int Value){
    Node* newNode = new Node(Value);
    if(head == NULL){
        head = newNode;
    }else{
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void Display(){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void main(){
    Insert(10);
    Insert(20);
    Insert(30);
    Insert(40);

    Display();

}
