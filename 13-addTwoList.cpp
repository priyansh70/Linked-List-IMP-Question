// Example 
// LL1 = 1 -> 5 -> 9 -> NULL
// LL2 = 5 -> 2 -> 0 -> NULL

// Result List 
// RL = 6 -> 7 -> 9 -> NULL 

// Approach1 - TC - O(n) |  SC - O(n)
#include<iostream>
#include<vector>
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

Node* reverse(Node* head)
{
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node* addTwoList(Node* first,Node* second)
{
    if (first == NULL)
    {
        return second;
    }

    if (second == NULL)
    {
        return first;
    }

    // step1
    first = reverse(first);
    second = reverse(second);

    // step2 
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;

    while (first != NULL || second != NULL || carry != 0)
    {
        int firstListData = 0;
        if(first)
            firstListData = first -> data;
        
        int secondListData = 0;
        if(second)
            secondListData = second -> data;
        
        int sum = carry + firstListData + secondListData;
        int digit = sum % 10;

        insertAtTail(ansHead,ansTail,digit);

        carry = sum / 10;

        if(first)
            first = first -> next;

        if(second)
            second = second -> next;
    }
    return reverse(ansHead);    
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,8);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,5);
    insertAtTail(head,tail,6);
    cout<<"List 1 -> ";
    printLinkedList(head);

    Node* head1 = NULL;
    Node* tail1 = NULL;
    insertAtTail(head1,tail1,5);
    insertAtTail(head1,tail1,9);
    insertAtTail(head1,tail1,4);
    cout<<"List 2 -> ";
    printLinkedList(head1);

    cout<<"Sum of This Lists is ->  ";
    Node* ans = addTwoList(head,head1);
    printLinkedList(ans);
    return 0;
}
