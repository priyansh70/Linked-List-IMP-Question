// Approach1 - TC - O(n) |  SC - O(n)
#include <iostream>
#include <vector>
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

void printLinkedList(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}
Node *sort012(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }

    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    Node *p1 = zeroHead;
    Node *p2 = oneHead;
    Node *p3 = twoHead;

    while (head != NULL)
    {
        if (head->data == 0)
        {
            p1->next = head;
            p1 = p1->next;
        }
        else if (head->data == 1)
        {
            p2->next = head;
            p2 = p2->next;
        }
        else
        {
            p3->next = head;
            p3 = p3->next;
        }
        head = head->next;
    }

    p3->next = NULL;
    p2->next = twoHead->next;
    p1->next = oneHead->next;

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    printLinkedList(head);
    Node *ansHead = sort012(head);
    printLinkedList(ansHead);
    return 0;
}
