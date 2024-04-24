#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void removeDuplicates(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return;
    }
    if (head->next == NULL)
    {
        cout << "single node in LL" << endl;
        return;
    }
    // > 1 node in LL
    Node *curr = head;

    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {
            // equl
            Node *temp = curr->next;
            curr->next = curr->next->next;
            // delete node;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            // not equal
            curr = curr->next;
        }
    }
}
int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *thied = new Node(20);
    Node *forth = new Node(30);
    Node *fiveth = new Node(40);
    Node *sixth = new Node(40);

    head->next = second;
    second->next = thied;
    thied->next = forth;
    forth->next = fiveth;
    fiveth->next = sixth;
    sixth->next = NULL;
    cout << "Input LL" << endl;

    print(head);

    removeDuplicates(head);
    cout << "Output LL" << endl;
    print(head);
    return 0;
}