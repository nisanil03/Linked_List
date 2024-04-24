// Most iMportant question 
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

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int getlength(Node *&head)
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

Node *reverseKNodes(Node *&head, int k)
{
    // Empty Linked List case
    if (head == NULL)
    {
        cout<<"LL is empty"<<endl;
        return head;
    }
    // Invalid case
    int len = getlength(head);
    if (k > len)
    {
        return head;
    }
    // Step - 1 => Reverse first k nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    int count = 0;
    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    // Step - 2 => Recursion
    if (forward != NULL)
    {                                           // We still have nodes left to reverse
        head->next = reverseKNodes(forward, k); // Connection step
    }
    // Return head
    return prev;
}
int main()
{
    Node *head = new Node(10);
    Node *first = new Node(20);
    Node *second = new Node(30);
    Node *third = new Node(40);
    Node *fourth = new Node(50);
    Node *fifth = new Node(60);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    print(head);
    Node *newHead = reverseKNodes(head, 5);
    cout << endl;
    print(newHead);

    return 0;
}
