#include <iostream>
#include<map>
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

void insertion(Node *&tail, int element, int data)
{
    // if Linked List is Empty
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        temp->next = temp;
        tail = temp;
    }

    else
    {

        Node *current = tail->next;

        while (current->data != element)
        {
            current = current->next;
        }

        if (current->data == element)
        {
            Node *temp = new Node(data);
            temp->next = current->next;
            current->next = temp;
        }
    }
}

void printCLL(Node* tail){
    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

Node* beginNodeOfLoop(Node* head)
{
    if(head == NULL || head -> next == NULL){
        return NULL;
    }

    Node* fast = head;
    Node* slow = head;

    while (fast&&fast->next)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
        if(slow == fast)
        {
            slow = head;
            while(fast != slow)
            {
                fast = fast -> next;
                slow = slow -> next;
            }
            return slow;
        }
    }
    return NULL;    
}

int main()
{
    Node *tail = NULL;
    
    insertion(tail, 4, 10);
    printCLL(tail);
    
    insertion(tail, 10, 4);
    printCLL(tail);
    
    insertion(tail, 4, 12);
    printCLL(tail);
    
    insertion(tail, 10, 64);
    printCLL(tail);
    
    insertion(tail, 64, 1);
    printCLL(tail);
    
    insertion(tail, 12, 48);
    printCLL(tail);

    // tail = tail -> next -> next -> next;

    Node* beginNode = beginNodeOfLoop(tail);
    cout<<"Start Node of Loop is "<<beginNode->data<<endl;
    return 0;
}
