#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node *&head, int val) // doubt
{
    node *n = new node(val);

    // if (head == NULL)
    // {
    //     head = n;
    //     return;
    // }

    n->next = head;
    head = n;
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteion(node *&head, int key)
{
    if (head == NULL)
    {
        return;
    }

    if (head->data == key)
    {
        node *todelete = head;
        head = head->next;
        delete todelete;
        return;
    }

    node *temp = head;
    while (temp->next->data != key)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

node *reverseLL(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

node *reverseRecursiveLL(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newhead = reverseRecursiveLL(head->next); // Doubt
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

void display(node *head) // doubt
{
    node *temp = head;
    while (temp != NULL) // doubt
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "Null";
    cout << endl;
}

int main()
{
    node *head = NULL; // doubt
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);

    // insertAtHead(head, 6);
    display(head);
    // deleteion(head, 3);
    // deleteion(head, 1);
    // node *newhead = reverseLL(head);
    node *newhead = reverseRecursiveLL(head);
    int k = 2;

    // display(head);
    display(newhead);

    // cout << search(head, 3);
    return 0;
}