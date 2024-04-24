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
Node *findMiddle(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
    }
    if (head ->next == NULL)
    {
        // only 1 node in LL;
        return head;
    }
    // LL have > 1 node
    Node* slow = head;
    Node* fast = head;// n/2 + 1 will be the answer
    // Node* fast = head->next;  // If we want n/2 as the answer
    // slow and fast are valid

    while (slow != NULL && fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {                     // check if fast becomes null
            fast = fast->next; // if not null, then simply move 1 step more and hence in total 2 steps
            slow = slow->next; // move 1 step
            
        }
    }
    return slow;// return slow which will be the middle node
}
int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;

    print(head);

    cout<<"Middle Node is: "<<findMiddle(head)->data <<endl;
    return 0;
}