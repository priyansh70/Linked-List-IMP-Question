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

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // If Node is Empty
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    // If Node is Empty
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }

    Node *temp = new Node(data);
    tail -> next = temp;
    tail = temp;    
}

void insertAtPosition(Node* &head,Node* &tail,int position,int data)
{
    if(position == 1){
        insertAtHead(head,tail,data);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < position - 1){
        temp = temp -> next;
    }

    if(temp -> next == NULL){
        insertAtTail(head,tail,data);
        return;
    }

    Node* insertNode = new Node(data);
    insertNode -> next = temp -> next;
    temp -> next = insertNode;
}

void printLL(Node* &head,Node* &tail)
{
    if(head == NULL){
        cout<<"Linked List is Empty"<<endl;
        return;
    }

    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp -> next;
    }    
    cout<<endl;
    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;
}

Node* solve(Node* head){
    // Base Condition
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node* newHead = solve(head->next);
    head->next ->next = head;
    head->next =  NULL;
    return newHead;
    
}

Node* reverseLinkedList(Node* head){
    return solve(head);
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,5);
    insertAtTail(head,tail,15);
    insertAtPosition(head,tail,2,10);
    insertAtHead(head,tail,2);
    insertAtTail(head,tail,120);
    insertAtPosition(head,tail,2,100);

    cout<<"Linked List : ";
    printLL(head,tail);
    Node* reverseHead = reverseLinkedList(head);
    cout<<"Reverse Linked List : ";
    printLL(reverseHead,head);
    return 0;
}
