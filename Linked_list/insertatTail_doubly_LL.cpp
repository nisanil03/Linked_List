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
void insertatTail(Node* &head, Node* &tail, int data)
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
int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    print(first);
    cout << endl;

    insertatTail(first, third, 501);

    cout << endl;
    print(first);

    return 0;
}