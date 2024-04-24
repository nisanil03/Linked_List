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
};

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
int main()
{
    // Creation of Nodes of Linked list
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fiveth = new Node(5);

    // Connecting them
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fiveth;

    cout << "Printing the Linked list " << endl;
    //printing linked list
    print(first);

    return 0;
}