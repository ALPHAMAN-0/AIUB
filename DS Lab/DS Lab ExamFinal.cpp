
//#include "/Users/siam/Desktop/C++/.vscode/stdc++.h"
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define endl '\n'
#define mii map<ll, ll>
#define msi map<string, ll>
#define mis map<ll, string>
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repr(i, a, b) for (ll i = b - 1; i >= a; i--)
#define trav(a, x) for (auto &a : x)
#define pii pair<ll, ll>
#define vi vector<ll>
#define vii vector<pair<ll, ll>>
#define vs vector<string>
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define sz(x) (ll) x.size()
#define hell 1000000007
#define lbnd lower_bound
#define ubnd upper_bound
#define DEBUG cerr << "/n>>>I'm Here<<</n" << endl;

#define display(x)               \
    trav(a, x) cout << a << " "; \
    cout << endl;
#define what_is(x) cerr << #x << " is " << x << endl;

#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

#define white 0
#define gray 1
#define black 2

#define PI 3.141592653589793
#define MAX_N 200005

using namespace std;


int Size = 0;
class LabExamCSS{
    private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };
    int STACK[10000];
    int Top = -1;
    int Size = 0;

    Node* head;
    Node* tail;
    public:
    LabExamCSS() : head(nullptr), tail(nullptr) {}

    void insert(int val){
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        Size++;
    }
    void DeletePossition(int poss){
        if (!head) {
            return;
        }
        Node* current = head;
        int count = 0;
        while (current && count < poss) {
            current = current->next;
            count++;
        }
        if (current) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next; 
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev; 
            }
            delete current;
            Size--;
        }

    }
    void InsertAtPosstion(int value,int pos){
        Node* newNode = new Node(value);
        Node* current = head;
        int count = 0;
        if (pos == 0) {
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
            if (!tail) {
                tail = newNode;
            }
            return;
        }
        while (current && count < pos - 1) {
            current = current->next;
            count++;
        }
        if (current) {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) {
                current->next->prev = newNode;
            } else {
                tail = newNode; // Update tail if inserting at the end
            }
            current->next = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        Size++;
    }
    void Display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }


    void TransferToStackEvenNumbers(){
        Node* current = head;
        while (current) {
            if(current->data % 2 == 0){
                STACK[++Top] = current->data;
            }
            current = current->next;
        }
    }
    void pop(){
        if (Top >= 0) {
            Top--;
            cout << "Popped element: " << STACK[Top + 1] << endl;
        } else {
            cout << "Stack is empty!" << endl;
        }
    }
    void push(int value){
        if(Top < 9999){
            STACK[++Top] = value;
        }else{
            cout << "Stack overflow!" << endl;
        }
    }
    void DisplayStack(){
        for (int i = 0; i <=Top ; i++) {
            cout << STACK[i] << " ";
        }
        cout << endl;
    }

    void SumALLElement(){
        int sum = 0;
        for(int i = 0; i <= Top; i++) {
            sum += STACK[i];
        }
        cout << "Sum of all elements in the stack: " << sum << endl;
    }
    void DeleteLastElement() {
        if (!head) {
            return; // List is empty
        }
        
        if (head == tail) {
            // Only one element in the list
            delete head;
            head = tail = nullptr;
            Size--;
            return;
        }
        
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        Size--;
    }

};


int main()
{
  //  freopen("/Users/siam/Desktop/C++/Test File C++/Input.txt", "r", stdin);
   // freopen("/Users/siam/Desktop/C++/Test File C++/Output.txt", "w", stdout);
    //auto start = chrono::high_resolution_clock::now();
    LabExamCSS LIST1;
    LIST1.insert(5);
    LIST1.insert(12);
    LIST1.insert(19);
    LIST1.insert(26);
    LIST1.insert(33);
    
    cout<<"Display the list"<<endl;
    LIST1.Display();
    cout<<"delete last element"<<endl;
    LIST1.DeleteLastElement(); // Using our new method
    LIST1.Display();
    cout<<"Insert at first Possition"<<endl;
    LIST1.InsertAtPosstion(20, 0);
    LIST1.Display();
    cout<<"Delete the element at possition 4"<<endl;
    LIST1.DeletePossition(4-1);
    LIST1.Display();

    cout<<"Transfer even numbers to stack"<<endl;
    LIST1.TransferToStackEvenNumbers();
    LIST1.DisplayStack();
    cout<<"Pop the top element from stack"<<endl;
    LIST1.pop();
    cout<<"Push 42 to stack"<<endl;
    LIST1.push(42);
    cout<<"Display stack after push"<<endl;
    LIST1.DisplayStack();
    LIST1.SumALLElement();

    return 0;
}

