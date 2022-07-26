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
    if(tail == NULL)
    {
        cout<<"Linked List is Empty"<<endl;
        return;
    }
    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

bool isCircular(Node* head)
{
    if(head == NULL)
    {
        return true;
    }

    Node* temp = head -> next;
    while (temp != NULL && head != temp)    
    {
        temp = temp -> next;
    }
    if(temp == NULL)    
    {
        return false;
    }
    if(temp == head)
    {
        return true;
    }
}

int main()
{
    Node *tail = NULL;
    
    insertion(tail, 4, 10);
    printCLL(tail);
    
    // insertion(tail, 10, 4);
    // printCLL(tail);
    
    // insertion(tail, 4, 12);
    // printCLL(tail);
    
    // insertion(tail, 10, 64);
    // printCLL(tail);
    
    // insertion(tail, 64, 1);
    // printCLL(tail);
    
    // insertion(tail, 12, 48);
    // printCLL(tail);

    if(isCircular(tail)){
        cout<<"Linked List Is Circular"<<endl;
    }
    else{
        cout<<"Linked List Is Not Circular"<<endl;
    }
    return 0;
}
