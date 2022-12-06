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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node *n = new node(val);

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void display(node *head)
{
    node *temp = head;

    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp->next != head);
    // cout << temp->data;
    cout << "Head" << endl;
}
int main()
{
    node *head = NULL;

    insertAtHead(head, 0);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);

    insertAtHead(head, 4);
    insertAtHead(head, 5);

    display(head);

    return 0;
}
