#include <iostream>
using namespace std;
class Node
{
public:
    int item;
    int pno = 0;
    Node *next;
};
class PriorityQueue
{
private:
    Node *start;

public:
    PriorityQueue();
    void insertPrior(int, int, int = 1);
    int heighestNO();
    int heighestPrioItem();
    void deletePrior();
    ~PriorityQueue();
    bool isEmpty();
};
// fuction definition
void PriorityQueue::deletePrior()
{
    if (start = NULL)
    {
        cout << endl
             << "Empty!";
        return;
    }
    Node *temp = start;
    start = start->next;
    delete temp;
}
bool PriorityQueue::isEmpty()
{
    if (start == NULL)
        return 1;
    return 0;
}
PriorityQueue::~PriorityQueue()
{
    while (start)
        deletePrior();
}
int PriorityQueue::heighestNO()
{
    if (start == NULL)
    {
        cout << endl
             << "empty!";
        return -1; // error
    }
    return start->pno;
}
int PriorityQueue::heighestPrioItem()
{
    if (start == NULL)
    {
        cout << endl
             << "empty!";
        return -1; // error
    }
    return start->item;
}
void PriorityQueue::insertPrior(int data, int pnr, int max)
{
    if (max == 1)
    {
        // max
        Node *nn = new Node;
        nn->item = data;
        nn->pno = pnr;
        nn->next = NULL;
        if (start == NULL)
        {
            start = nn;
            nn->next = NULL;
        }
        else
        {

            // left insert
            if (nn->pno > start->pno)
            {
                nn->next = start;
                start = nn;
            }
            // right insert
            else
            {
                Node *temp = start, *prev = NULL;
                while (temp)
                {
                    prev = temp;
                    temp = temp->next;
                    if (nn->pno > temp->pno)
                    {
                        nn->next = temp;
                        prev->next = nn;
                        return;
                    }
                }
                nn->next = temp;
                prev->next = nn;
            }
        }
    }
    else
    { // min

        Node *nn = new Node;
        nn->item = data;
        nn->pno = pnr;
        nn->next = NULL;
        if (start == NULL)
        {
            start = nn;
            nn->next = NULL;
        }
        else
        {

            // left insert
            if (nn->pno < start->pno)
            {
                nn->next = start;
                start = nn;
            }
            // right insert
            else
            {
                Node *temp = start, *prev = NULL;
                while (temp)
                {
                    prev = temp;
                    temp = temp->next;
                    if (nn->pno < temp->pno)
                    {
                        nn->next = temp;
                        prev->next = nn;
                        return;
                    }
                }
                nn->next = temp;
                prev->next = nn;
            }
        }
    }
}
PriorityQueue::PriorityQueue()
{
    start = NULL;
}