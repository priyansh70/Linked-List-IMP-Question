#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

void printLinkedList(Node* &head)
{
    if(head == NULL)
    {
        cout<<"Linked List is Empty"<<endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

void insertAtTail(Node* &head,Node* &tail,int data)
{
    Node* temp = new Node(data);
    if(tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail -> next = temp;
    tail = temp;
}

Node* helper(Node* list1,Node* list2)
{
    // if list1 contain only single node 
    if(list1 -> next == NULL)
    {
        list1 -> next = list2;
        return list1;
    }

    Node* current1 = list1;
    Node* next1 = current1 -> next;
    Node* current2 = list2;
    Node* next2 = current2 -> next;

    while(next1 != NULL && current2 != NULL)
    {
        if( (current1 -> data <= current2 -> data) && 
        (current2 -> data <= next1 -> data))
        {
            // Add Node 
            current1 -> next = current2;
            next2 = current2 -> next;
            current2 -> next = next1;

            // Change Pointers 
            current1 = current2;
            current2 = next2;
        }
        else
        {
            current1 = current1 -> next;
            next1 = next1 -> next;
        }
    }

    if(next1 == NULL)
    {
        current1 -> next = current2;
    }
    return list1;
}

Node* mergeTwoSortedList(Node* list1,Node* list2)
{
    // if first List Is Empty 
    if(list1 == NULL)
    {
        return list2;
    }

    // if Second List Is Empty 
    if(list2 == NULL)
    {
        return list1;
    }

    if(list1 -> data <= list2 -> data)
    {
        return helper(list1,list2);
    }
    else{
        return helper(list2,list1);
    }
}

int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;

    insertAtTail(head1,tail1,1);
    insertAtTail(head1,tail1,3);
    insertAtTail(head1,tail1,5);
    insertAtTail(head1,tail1,7);
    insertAtTail(head1,tail1,9);
    cout<<"List 1 : ";
    printLinkedList(head1);

    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtTail(head2,tail2,2);
    insertAtTail(head2,tail2,4);
    insertAtTail(head2,tail2,6);
    insertAtTail(head2,tail2,8);
    cout<<"List 2 : ";
    printLinkedList(head2);

    cout<<"Merged List : ";
    Node* mergedHead = mergeTwoSortedList(head1,head2);
    printLinkedList(mergedHead);
    return 0;
}
