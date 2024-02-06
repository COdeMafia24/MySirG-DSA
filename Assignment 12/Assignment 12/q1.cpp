#include <iostream>
using namespace std;
class Node
{
public:
    int item;
    Node *next;
    Node *prev;
};
class Deque
{
private:
    Node *front;
    Node *rear;

public:
    Deque();
    void insertAtFront(int);
    void insertAtRear(int);
    void deleteFront();
    void deleteRear();
    int getFront();
    int getRear();
    ~Deque();
    bool isEmpty();
};
// function definition
bool Deque::isEmpty(){
    if(front==NULL)
        return 1;
    return 0;
}
Deque::~Deque(){
    while(front){
        deleteFront();
    }
}
int Deque::getFront(){
    if(front==NULL)
        return -1;//error
    return front->item;
}
int Deque::getRear(){
    if(front==NULL)
        return -1;//error
    return rear->item;
}
void Deque::deleteRear()
{
    if (front == NULL)
    {
        cout << endl
             << "No element in the Deque!";
        return;
    }
    if (front == rear)
        front = rear = NULL;
    else
    {
        Node *temp;
        temp = rear;
        rear = rear->prev;
        delete temp;
    }
}
void Deque::deleteFront()
{
    if (front == NULL)
    {
        cout << endl
             << "No element in the Deque!";
        return;
    }
    if (front == rear)
        front = rear = NULL;
    else
    {
        Node *temp;
        temp = front;
        front = front->next;
        delete temp;
    }
}
void Deque::insertAtRear(int data)
{
    Node *nn = new Node();
    nn->item = data;
    // nn->next=nullptr;
    rear->next = nn;
    nn->prev = rear;
    rear = nn;
}
void Deque::insertAtFront(int data)
{
    Node *nn = new Node;
    nn->item = data;
    if (front == NULL)
        front = rear = nn;
    front->prev = nn;
    nn->next = front;
    front = nn;
}
Deque::Deque()
{
    front = NULL;
    rear = NULL;
}