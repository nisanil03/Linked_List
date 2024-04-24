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
// Insertion at head case
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // Empty Linked list case
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Step - 1
    Node *newNode = new Node(data);
    // Step - 2
    newNode->next = head;
    // Step - 3
    head = newNode;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    { // Step - 3 Stop when we reach NULL
        // Step - 1 Print
        cout << temp->data << " ";
        // Step - 2 Move temp to next
        temp = temp->next;
    }
}
// Recursive approach
Node *reverse(Node *&prev, Node *&curr)
{
    // base case
    if (curr == NULL)
    {
        // LL reverse ho chuki hai
        return prev;
    }
    // 1 case hum solve karnege or baki recursion dhak lega;
    Node *forwerd = curr->next;
    // change the link
    curr->next = prev;
    // recursive cell
    return reverse(curr, forwerd);
}
Node *reverseusingLoop(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
Node* reverseusingrecursion(Node *prev, Node *curr)
{
    // base case: recursion
    if (curr == NULL)
    {
        return prev;
    }
    // 1 case solved karna hai
    Node *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
    // resursion dhak lega
   return  reverseusingrecursion(curr, prev);
}
int main()
{
    Node *head = new Node(10);
    Node *tail = head;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    print(head);
    cout << endl;

    Node *prev = NULL;
    Node *curr = head;
    // head = reverse(prev, curr);
    
    head = reverseusingLoop(head);
    cout << "Printing reverse list " << endl;
    //head = reverseusingrecursion(prev, curr);
    cout << endl;
    print(head);
    cout << endl;

    return 0;
}