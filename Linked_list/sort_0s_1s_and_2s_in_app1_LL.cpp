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
//approach 1 forsolve 
void SortzeroOnetwo(Node *head)
{
    // step 1-> find count of zeros ,ones and twos
    int zero = 0;
    int one = 0;
    int two = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero++;
        }

        else if (temp->data == 1)
        {
            one++;
        }

        else if (temp->data == 2)
        {
            two++;
        }

        temp = temp->next;
    }
    // step 2; fill 0, 1 and 2s in original LL;
    temp = head;

    // fill 0s
    while (zero--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    // fill 1s
    while (one--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    // fill 2s
    while (two--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}
int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *thied = new Node(2);
    Node *forth = new Node(0);
    Node *fiveth = new Node(0);
    Node *sixth = new Node(0);

    head->next = second;
    second->next = thied;
    thied->next = forth;
    forth->next = fiveth;
    fiveth->next = sixth;
    sixth->next = NULL;

    cout << "Input LL" << endl;
    print(head);

    SortzeroOnetwo(head);
    print(head);
    return 0;
}