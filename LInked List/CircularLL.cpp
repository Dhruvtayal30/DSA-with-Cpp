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

void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        cout << "Empty LL";
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    node *todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
}

void deleteANodeByValue(node *&head, int key)
{
    if (head == NULL)
    {
        cout << "Empty LL";
        return;
    }

    if (head->data == key)
    {
        // node *temp = head;
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    while (temp->next->data != key) //  && temp->next != head)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void display(node *head)
{
    node *temp = head;

    // while (temp->next != head)
    // {
    //     cout << temp->data << "->";
    //     temp = temp->next;
    // }

    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    // cout << temp->data << "->";
    cout << "Head" << endl;
}

int main()
{
    node *head = NULL;

    // insertAtHead(head, 0);
    insertAtHead(head, 0);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);

    insertAtHead(head, 4);
    insertAtHead(head, 5);
    display(head);

    // deleteANodeByValue(head, 0);
    // display(head);
    // deleteANodeByValue(head, 1);
    // display(head);
    // deleteANodeByValue(head, 2);
    // display(head);
    // deleteANodeByValue(head, 3);
    // display(head);
    // deleteANodeByValue(head, 4);
    // display(head);
    // deleteANodeByValue(head, 5);
    // // deleteAtHead(head);
    // display(head);

    return 0;
}
