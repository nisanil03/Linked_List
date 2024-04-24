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
        if (pos >= len)
        {
            insertatTail(head, tail, data);
            return;
        }
        //insertion in middle;
        // step 1  find prev and curr
        int i = 1; 
        Node* prevNode = head;
        while(i < pos - 1){
            prevNode = prevNode->next;
            i++;
        }
        Node* curr = prevNode -> next;
        // step 2 creat  node 
        Node* newNode = new Node(data);
        //step 3
        prevNode -> next = newNode;
        //step 4
        newNode -> prev = prevNode;
        //step 5 find next
        curr -> prev = newNode;
        //step 6
        newNode -> next = curr;
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

    insertatHead(head, tail, 101);

    cout << endl;
    print(head);

    cout << endl;

    insertatTail(head, tail, 501);

    cout << endl;
    print(head);

    cout << endl;

    insertatPosition(head, tail, 501, 1);

    cout << endl;
    print(head);


    return 0;
}