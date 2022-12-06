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

void insertAtTail(node *&head, int val)
{

    if (head == NULL)
    {
        // head = n;
        insertAtHead(head, val);
        return;
    }

    node *n = new node(val);

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
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

void deleteByNodeValue(node *&head, int key)
{
    if (head == NULL)
    {
        cout << "Empty LL";
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
    while (temp->next->data != key && temp->next != NULL)
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

void insertAfter(node *&head, int key, int val)
{
    node *n = new node(val);
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp = temp->next;
    }
}

void insertInBetween(node *&head, int index, int val)
{
    node *n = new node(val);
    node *temp = head;
    int i = 1;
    while (i != index - 1)
    {
        // if (temp->data == key)
        // {
        // n->next = temp->next;
        // temp->next = n;
        // return;
        // }
        temp = temp->next;
        i++;
    }
    n->next = temp->next;
    temp->next = n;
}

void deleteHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    // free(todelete);
    delete todelete;
}

void deleteTail(node *&head)
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    node *todelete = temp->next;
    temp->next = NULL;
    delete todelete;
    // return head;
}

void deleteInBetween(node *&head, int index)
{

    int i = 1;
    node *temp = head;
    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int main()
{
    node *head = NULL; // doubt
    insertAtTail(head, 1);
    // insertAtTail(head, 2);
    // insertAtTail(head, 3);
    // insertAtTail(head, 4);
    // insertAtTail(head, 5);
    // insertAtTail(head, 6);
    // insertAtTail(head, 7);

    // insertAtHead(head, 6);
    display(head);
    // deleteHead(head);
    // deleteTail(head);
    // deleteInBetween(head, 5);
    // display(newhead);
    // insertInBetween(head, 5, 80);
    // insertAfter(head, 80, 90);
    deleteByNodeValue(head, 1);
    display(head);
    // deleteion(head, 1);
    // node *newhead = reverseLL(head);
    // node *newhead = reverseRecursiveLL(head);
    // int k = 2;

    // display(head);
    // display(newhead);

    // cout << search(head, 3);
    return 0;
}

void menu()
{
    cout << "----------------*****************--------------------------------------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Insert an element  at the beginning" << endl;
    cout << "2.Insert an element at the end" << endl;
    // cout << "3.Insert an element at i th  position" << endl;
    // cout << "4.Delete  an element from the beginning" << endl;
    // cout << "5.Delete an element from the end" << endl;
    cout << "6.Delete an element from  i th  position" << endl;
    cout << "7.Search for an element : pointer to the element is returned" << endl;
    // cout << "8.Concatenate two singly linked lists , also overload +" << endl;
    cout << "9.Reverse" << endl;
    cout << "--------------------****************-------------------------------------" << endl;
    cout << "Enter your choice :" << endl;
}

// int main()
// {
//     node *head = NULL;
//     node *newhead;
//     int ch;
//     int x;
//     int i;
//     int y;
//     do
//     {
//         menu();
//         cin >> ch;
//         switch (ch)
//         {
//         case 0:
//             cout << "Exiting :)...." << endl;
//             break;

//         case 1:
//             cout << "Enter the element :";
//             cin >> x;
//             insertAtHead(head, x);
//             display(head);
//             break;

//         case 2:
//             cout << "Enter the element :";
//             cin >> x;
//             insertAtTail(head, x);
//             display(head);
//             break;

//             // case 3:
//             //     cout << "Enter the element :";
//             //     cin >> x;
//             //     cout << "Enter the poistion to be inserted at :";
//             //     cin >> i;
//             //     l1.add_at_loc(i, x);
//             //     l1.display();
//             //     break;

//             // case 4:
//             //     l1.del_from_head();
//             //     l1.display();
//             //     break;

//             // case 5:
//             //     l1.del_from_tail();
//             //     l1.display();
//             //     break;

//         case 6:
//             cout << "Enter the data to be deleted from :";
//             cin >> i;
//             deleteion(head, i);
//             display(head);
//             break;

//         case 7:
//             cout << "Enter the data to be searched : ";
//             cin >> y;
//             if (search(head, y))
//             {
//                 cout << "found" << endl;
//                 break;
//             }
//             cout << "not found" << endl;
//             break;

//         case 9:
//             newhead = reverseLL(head);
//             display(newhead);
//             break;

//         default:
//             cout << "Invalid choice" << endl;
//             break;
//         }

//     } while (ch != 0);
//     return 0;
// }