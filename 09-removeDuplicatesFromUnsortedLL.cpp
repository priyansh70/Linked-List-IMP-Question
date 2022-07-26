// Using Map
// Time Complexity - O(n)
// Time Complexity - O(n)

#include <iostream>
#include<unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
        return;
    }
    // create Node
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
        return;
    }
    // Create temp node
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtMiddle(Node *&head, Node *&tail, int position, int data)
{
    // insert at begin
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // insert at end
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *insertedNode = new Node(data);
    // temp->next = insertedNode;
    insertedNode->next = temp->next;
    temp->next = insertedNode;
}
void printLinkedList(Node *head)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void removeDuplicates(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

   unordered_map<int,int> seen;
   
   Node* current = head;
   Node* prev = NULL;

   while (current != NULL)
   {
        if(seen[current -> data])
        {
            prev -> next = current -> next;
            delete current;
        }
        else{
            seen[current -> data] = 1;
            prev = current;
        }
        current = prev -> next;
   }   
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 15);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 15);
    insertAtTail(head, tail, 25);
    insertAtTail(head, tail, 20);

    cout << "Original Linked List : ";
    printLinkedList(head);

    cout << "Remove Duplicates From Unsorted Linked List" << endl;
    removeDuplicates(head);
    printLinkedList(head);
    return 0;
}
