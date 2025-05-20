#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int Value)
    {
        data = Value;
        next = NULL;
        prev = NULL;
    }
};

struct Node *head = NULL;
struct Node *tail = NULL;

void InsertIntoLast(int Value)
{
    Node *newNode = new Node(Value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void Display()
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void ReverseDisplay()
{
    Node *current = tail;
    if (tail == NULL)
    {
        cout << "List is empty, nothing to display." << endl;
        return;
    }
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}
void ConvertToSingleList()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *nextNode = current->next;
        current->prev = NULL; // Remove the previous link
        current = nextNode;
    }
    tail = NULL; // Clear the tail as well
}
int main()
{
    // Insert value into last of the dobbly Linked List
    InsertIntoLast(10);
    InsertIntoLast(20);
    InsertIntoLast(30);
    InsertIntoLast(40);

    cout << "Display of Dobbly Linked List: ";
    Display();
    cout << endl;
    cout << "Reverse Display of Dobbly Linked List: ";
    ReverseDisplay();
    cout << endl;

    ConvertToSingleList();
    cout << "Display of Single Linked List after conversion: ";
    Display();
    cout << endl;
    cout << "Reverse Display of Single Linked List after conversion: ";
    ReverseDisplay();
    cout << endl;

    return 0;
}
