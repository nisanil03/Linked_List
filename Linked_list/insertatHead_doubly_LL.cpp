#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    { // constuter
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    { // paremeter consturter
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "Node with value :" << this->data << " Delete "  << endl;
    }
};
void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getlength(Node *head)
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
void insertatHead(Node *&head, Node *&tail, int data)
{
    // create a new node with the given data and make next of it as the current head
    // LL is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is Non empty
        //  step 1: create a new node with the given data
        Node *newNode = new Node(data);
        // step2;
        newNode->next = head;
        // step3;
        head->prev = newNode;
        // step 4;
        head = newNode;
    }
}
void insertatTail(Node *&head, Node *&tail, int data)
{

    if (head == NULL)
    {
        // LL is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is not empty
        // step 1 ; creat a node
        Node *newNode = new Node(data);
        // step 2
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void insertatPosition(Node *&head, Node *&tail, int data, int pos)
{
    // empty LL
    if (head == NULL)
    {
        // LL is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is non empty
        if (pos == 1)
        {
            insertatHead(head, tail, data);
            return;
        }
        int len = getlength(head);
        if (pos > len)
        {
            insertatTail(head, tail, data);
            return;
        }
        // insertion in middle;
        //  step 1  find prev and curr
        int i = 1;
        Node *prevNode = head;
        while (i < pos - 1)
        {
            prevNode = prevNode->next;
            i++;
        }
        Node *curr = prevNode->next;
        // step 2 creat  node
        Node *newNode = new Node(data);
        // step3
        newNode->prev = prevNode;
        prevNode->next = newNode;
        newNode->next = curr;
        curr->prev = newNode;
    }
}
void deleteFromPos(Node *&head, Node *&tail, int pos)
{
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    if (head->next == NULL)
    {
        // Single node
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    int len = getlength(head);
    if (pos > len)
    { // delete as tail;
        cout << "Please enter the valid position" << endl;
        return;
    }
    if (pos == 1)
    {
        // want to delete first node
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    if (pos == len)
    {
        // delete last node;
        Node *temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }
    // delete from middle of Linked list ;
    // step1- find left, curr, right
    int i = 1;
    Node *left = head;
    while (i < pos - 1)
    {
        left = left->next;
        i++;
    }
    Node *curr = left->next;
    Node *right = curr->next;
    // step 2
    left->next = right;
    // step 3
    right->prev = left;
    // step 4
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}
int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *head = first;
    Node *tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    // print(first);
    // cout << endl;

    insertatHead(head, tail, 101);

    // cout << endl;
    // print(head);

    // cout << endl;

    insertatTail(head, tail, 501);

    // cout << endl;
    // print(head);

    // cout << endl;

    insertatPosition(head, tail, 401, 6);

    cout << endl;
    print(head);
    cout << endl;

    deleteFromPos(head, tail, 1);

    cout<<endl;
    print(head);
    cout<<endl;

    return 0;
}