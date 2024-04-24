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
Node *Sort2(Node *&head)
{
    if (head == NULL){
        cout<<"LL is empty "<<endl;
        return NULL;
    }
    if(head -> next == NULL){
        // single node in LL 
        return head;
    }
    // create Dummy Nodes;
    Node *ZeroHead = new Node(-1);
    Node *Zerotail = ZeroHead;

    Node *OneHead = new Node(-1);
    Node *Onetail = OneHead;

    Node *TwoHead = new Node(-1);
    Node *Twotail = TwoHead;

    // travers the original LL
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            // take out zero wail node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the zero node in zeroHead LL
            Zerotail->next = temp;
            Zerotail = temp;
        }
        else if (curr->data == 1)
        {
            // take out one wail node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the one node in zeroHead LL
            Onetail->next = temp;
            Onetail = temp;
        }
        else if (curr->data == 2)
        {
            // take out two wail node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // append the two node in zeroHead LL
            Twotail->next = temp;
            Twotail = temp;
        }
    }
    // ab yaha pr zero , onr and two teeno LL ready hai

    // join karna hai
    // remove dummy node;

    // modify one wail LL
    Node *temp = OneHead;
    OneHead = OneHead->next;
    temp->next = NULL;
    delete temp;

    // modify teo wail list ;
    temp = TwoHead;
    TwoHead = TwoHead->next;
    temp->next = NULL;
    delete temp;

    // join list
    if (OneHead != NULL)
    {
        // one wail list is non empty
        Zerotail->next = OneHead;
        if (TwoHead != NULL)
            Onetail->next = TwoHead;
    }
    else
    {
        // one wail list empty hai
        if (TwoHead != NULL)
            Zerotail->next = TwoHead;
    }

    // remove zerohead dummy node
    temp = ZeroHead;
    ZeroHead = ZeroHead->next;
    temp->next = NULL;
    delete temp;

    // return head of the modified LL
    return ZeroHead;
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

    cout << "printing the sorted list " << endl;
    Node* temp = NULL;
    head = Sort2(head);
    //cout<<" came our of sort function "<< endl;
    print(head);

    return 0;
}