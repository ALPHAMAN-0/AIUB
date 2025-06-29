
#include<bits/stdc++.h>
using namespace std; 
class DubleLinkedList{
    private: 
    struct Node{
        int data;
        Node *next;
        Node* prev;
        Node(int val){
            data = val;
            next = nullptr;
            prev = nullptr;
        }
    };
    Node* head = NULL;
    Node* tail = NULL;
    
    public:

    void insert(int val){
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void DeleteAnyPossition(int poss){
        Node* temp = head;
        if (poss < 0) {
            cout << "Invalid position" << endl;
            return;
        }
        for (int i = 0; i < poss && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; 
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; 
        }
        delete temp;
    }
    void DisplayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void DisplayBackward() {
        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};
class QUEUE{
    private:
    struct QueueNode{
        int StudentID;
        int CourseID;
        QueueNode(int val1 = 0, int val2 = 0){
            StudentID = val1;
            CourseID = val2;
        }
    };
    public:
    int front = -1;
    int rear = -1;
    const int MAX_SIZE = 1000;
    QueueNode arr[1000]; 
    

    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }
    
    void enqueue(int studentId, int courseId) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        
        if (isEmpty()) {
            front = 0;
        }
        
        rear = (rear + 1) % MAX_SIZE;
        
        arr[rear] = QueueNode(studentId, courseId);
        
        cout << "Enqueued: Student ID " << studentId << ", Course ID " << courseId << endl;
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        int studentId = arr[front].StudentID;
        int courseId = arr[front].CourseID;
        
        if (front == rear) {
            front = rear = -1;
        } else {
          
            front = (front + 1) % MAX_SIZE;
        }
        
        cout << "Dequeued: Student ID " << studentId << ", Course ID " << courseId << endl;
    }
    
    void getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << "Front element: Student ID " << arr[front].StudentID 
             << ", Course ID " << arr[front].CourseID << endl;
    }
    
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << "Queue elements:" << endl;
        
        int i = front;
        do {
            cout << "Student ID: " << arr[i].StudentID 
                 << ", Course ID: " << arr[i].CourseID << endl;
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
    }
};
class BST2{
    private:
    struct Node{
        int data;
        Node *left;
        Node *right;
        Node(int val){
            data = val;
            left = right =NULL;
        }
    };
    Node* Root = NULL;
    public:
    void insert(int val){
        Node* newNode = new Node(val);
        if (Root == NULL) {
            Root = newNode;
        }
        else {
            Node* current = Root;
            Node* parent = NULL;
            while (current != NULL) {
                parent = current;
                if (val < current->data) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if (val < parent->data) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }
    }
    void inorderTraversal(Node* node) {
        if (node == NULL) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
    void inorder() {
        inorderTraversal(Root);
        cout << endl;
    }
    void PreorderTraversal(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        PreorderTraversal(node->left);
        PreorderTraversal(node->right);
    }
    void Preorder() {
        PreorderTraversal(Root);
        cout << endl;
    }
    void PostorderTraversal(Node* node) {
        if (node == NULL) return;
        PostorderTraversal(node->left);
        PostorderTraversal(node->right);
        cout << node->data << " ";
    }
    void Postorder() {
        PostorderTraversal(Root);
        cout << endl;
    }
}; 
int main()
{

 
    DubleLinkedList Students;
    cout<<"Insert Values"<<endl;
    Students.insert(11);
    Students.insert(22);
    Students.insert(33);
    cout<<"Display Forward"<<endl;
    Students.DisplayForward();
    cout<<"Display Backward"<<endl;
    Students.DisplayBackward();

    cout<<"Delete Any Position 1"<<endl;
    Students.DeleteAnyPossition(1);
    Students.DisplayForward();

    QUEUE courseRegistration;
    
    courseRegistration.enqueue(11, 101);
    courseRegistration.enqueue(22, 102);
    courseRegistration.enqueue(33, 103);
    
    courseRegistration.displayQueue();
    
    courseRegistration.dequeue();
    
    courseRegistration.getFront();
    
    courseRegistration.displayQueue();
    BST2 BinarySearchTree;
    BinarySearchTree.insert(10);
    BinarySearchTree.insert(5);
    BinarySearchTree.insert(15);
    BinarySearchTree.insert(3);
    BinarySearchTree.insert(7);
    BinarySearchTree.insert(12);
    BinarySearchTree.insert(18);

    cout<<endl;
    cout<<"Binary Search Tree Traversals:"<<endl;
    cout << "Inorder Traversal: ";
    BinarySearchTree.inorder();
    cout << "Preorder Traversal: ";
    BinarySearchTree.Preorder();
    cout << "Postorder Traversal: ";
    BinarySearchTree.Postorder();

    return 0;
}

