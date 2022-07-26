/*
Time Complexity -> O(n)
Space Complexity -> O(1)

Step1 :- Find Middle Element Of Linked List

Step2 :- Reverse Linked List After the Middle Element of Linked List

Step3 :- Now Compare Head Data and After Middle Element which is now Reverse So Last Node Here.

Step4 :- If Both Elements are Equal then set Node to Next Nodes Otherwise Return False

Step5 :- Not Compulsory if you wants to Maintain Linked List As well as Call in our Main Function that Again Reverse it After the Middle Element 
*/
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

bool isPalindrome(Node* head)
{
    if(head == NULL || head -> next == NULL)
    {
        return true;
    }
    Node* slow = head;
    Node* fast = head -> next;

    while(fast&&fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    Node* prev = NULL;
    Node* current = slow -> next;
    Node* next = NULL;

    while(current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }

    while(prev != NULL)
    {
        if(head -> data != prev -> data)
        {
            return false;
        }
        head = head -> next;
        prev = prev -> next;
    }
    
    return true;
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    // insertAtTail(head,tail,1);
    // insertAtTail(head,tail,1);
    printLinkedList(head);
    
    if(isPalindrome(head))
    {
        cout<<"Linked List Is Palindrome"<<endl;
    }
    else
    {
        cout<<"Linked List Is not Palindrome"<<endl;
    }

    return 0;
}

/*

class Solution {
    private:
    Node* getMiddle(Node* head)
    {
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast&&fast->next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    Node* reverse(Node* head)
    {
        Node* prev = NULL;
        Node* current = head;
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
public:
    bool isPalindrome(Node* head) {
        if(head -> next == NULL)
        {
            return true;
        }
        
		//step1
        Node* mid = getMiddle(head);
        Node* temp = mid -> next;
		
		//step2
        temp = reverse(mid -> next);
        Node* curr = head;
        
        while(temp != NULL)
        {
			//step3
            if(curr -> data != temp -> data)
            {
                return false;
            }
			
			//step4
            temp = temp -> next;
            curr = curr -> next;
        }
		
		//step5 (Optional)
        mid -> next = reverse(mid -> next);
        return true;
    }
};
*/
