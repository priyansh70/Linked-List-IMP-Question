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
    temp->next= head;
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
        insertAtHead(head,tail, data);
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
        insertAtTail(head,tail, data);
        return;
    }

    Node *insertedNode = new Node(data);
    // temp->next = insertedNode;
    insertedNode->next = temp->next;
    temp->next = insertedNode;
}
void printLinkedList(Node *head)
{
    if(head == NULL){
        cout<<"Linked List is Empty"<<endl;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void removeDuplicates(Node* &head)
{
    if(head == NULL || head -> next == NULL)
    {
        return;
    }

    Node* current = head;
    while(current && current -> next){
        if(current -> data == current -> next -> data)
        {
            Node* temp = current -> next;
            current -> next = temp -> next;
            temp -> next = NULL;
            delete temp;
        }
        else{
            current = current -> next;
        }
    }
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head,tail,10);
    insertAtTail(head,tail,15);
    insertAtTail(head,tail,15);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,25);

    cout<<"Original Linked List : ";
    printLinkedList(head);
    cout<<endl;

    cout<<"Remove Duplicates From Sorted Linked List"<<endl;
    removeDuplicates(head);
    printLinkedList(head);
    return 0;
}
