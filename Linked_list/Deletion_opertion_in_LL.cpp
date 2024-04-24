#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() // create the construstor;
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // wrtie a destructor to  delete a node
    ~Node()
    {
        cout << "Node with value :" << this->data << "delete" << endl;
    }
};

// I want to insert a node right at the head of Linked List;
void InsertatHead(Node *&head, Node *&tail, int data)
{
    // check LL are empty or not ;
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // step 1;
    Node *newNode = new Node(data);
    // sted2;
    newNode->next = head;
    // step3
    head = newNode;
}

// I want to insert a node  right at the head of LINKED LIST;

void InsertatTail(Node *&head, Node *&tail, int data)
{
    // check LL are empty or not ;
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // step 1;// create the node
    Node *newNode = new Node(data);

    // step 2;// tail ka next ko new node k equal karna hai
    tail->next = newNode;

    // step 3;// tail ko newnode k equal karna hai
    tail = newNode;
}

void InsertatPossition(Node *&head, Node *&tail, int position, int data)
{
    // check LL are empty or not ;
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    if (position == 0)
    {
        InsertatHead(head, tail, data);
        return;
    }

    int len = findlength(head);

    if (position >= len)
    {
        InsertatTail(head, tail, data);
        return;
    }
    // step 1 find out the possition ;
    int i = 1;
    Node *prev = head;

    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    // step 2 create a node;
    Node *newNode = new Node(data);

    // step 3 newnode k nest ko current pe lagana hai
    newNode->next = curr;

    // step 4 privouse k next ko new node k next pe jaga deya;
    prev->next = newNode;
}
void deleteNode(int position, Node *&head, Node *&tail)
{
    // delete the first Node

    if (head == NULL)
    {
        cout << "cannot delete, LL is empty ";
        return;
    }
    // deleteing  first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete (temp);
        return;
    }
    int len = findlength(head);
}

// delete the last node;
if (position == len)
{

    // find prev
    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }

    // step 2;
    prev->next = NULL;

    // step3;
    Node *temp = tail;

    // step 4
    tail = prev;

    // step 5;
    delete (temp);
    return;
}
// Delete middele node
// step 1
int i = 1;
Node *prev = head;
while (i < position - 1)
{
    prev = prev->next;
    i++;
}
Node *curr = prev->next;
// step2
prev->next = curr->next;

// step3
curr->next = NULL;
// step4
delete curr;
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        // Step - 3 Stop when we reach NULL
        // Step - 1 Print
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int findlength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
int main()
{
    Node *head = NULL; // new Node(10);  NULL;
    Node *tail = NULL; // head;
    InsertatHead(head, tail, 20);
    InsertatHead(head, tail, 30);
    InsertatHead(head, tail, 40);
    InsertatHead(head, tail, 50);
    InsertatHead(head, tail, 60);
    InsertatHead(head, tail, 70);
    InsertatTail(head, tail, 33);

    // print(head);
    // cout << endl;
    //  cout << "head : " << head->data << endl;
    //  cout << "tail : " << tail->data << endl;

    // InsertatPossition(head, tail, 101, 4);

    // cout << "printing after insert at position call : " << endl;
    // print(head);
    // cout << endl;
    // cout << "head : " << head->data << endl;
    // cout << "tail : " << tail->data << endl;

    deleteNode(7, head, tail);
    cout << endl;
    print(head);
    cout << endl;
    return 0;
}