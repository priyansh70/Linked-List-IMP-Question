#include <iostream>
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
Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *mergeTwoSortedList(Node *first, Node *second)
{
    if (first == NULL)
    {
        return second;
    }

    if (second == NULL)
    {
        return first;
    }

    Node *ansHead = NULL;
    Node *ansTail = NULL;
    while (first != NULL && second != NULL)
    {
        if (first->data <= second->data)
        {
            insertAtTail(ansHead, ansTail, first->data);
            first = first->next;
        }
        else
        {
            insertAtTail(ansHead, ansTail, second->data);
            second = second->next;
        }
    }

    while (first != NULL)
    {
        insertAtTail(ansHead, ansTail, first->data);
        first = first->next;
    }

    while (second != NULL)
    {
        insertAtTail(ansHead, ansTail, second->data);
        second = second->next;
    }
    return ansHead;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Find Mid Node
    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    // merge Lists
    return mergeTwoSortedList(left, right);
}
int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;

    insertAtTail(head1, tail1, 3);
    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 9);
    insertAtTail(head1, tail1, 7);
    insertAtTail(head1, tail1, 5);
    cout << "Linked List : ";
    printLinkedList(head1);

    Node *sortHead = mergeSort(head1);

    cout<<"Sorted Linked List : ";
    printLinkedList(sortHead);
    return 0;
}
