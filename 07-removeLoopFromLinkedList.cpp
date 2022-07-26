 #include <iostream>
#include <map>
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

void printCLL(Node *tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

// Detect LOOP
bool detectLoop(Node* head)
{
    if(head == NULL || head -> next == NULL)
    {
        return false;
    }

    Node* fast = head;
    Node* slow = head;

    while(fast&& fast-> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}
void removeLoop(Node* head)
{
    // if List is Empty and Single Node
    if(head == NULL || head -> next == NULL)
    {
        return;
    }

    // Detect Loop
    Node* fast = head;
    Node* slow = head;

    while(fast&&fast->next){
        fast = fast -> next -> next;
        slow = slow -> next;

        // Loop detect 
        if(fast == slow)
        {
            // Now Point On First Node Of Loop 
            slow = head;
            while (slow != fast)
            {
                slow = slow -> next;
                fast = fast -> next;
            }
            while (fast -> next != slow)
            {
                fast = fast -> next;
            }
            fast -> next = NULL;
            return;
        }
    }

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

    tail = tail->next->next;
    if (detectLoop(tail))
    {
        cout << "Cycle is present in List" << endl;
    }
    else
    {
        cout << "Cycle is not present in List" << endl;
    }

    // remove Loop 
    removeLoop(tail);
    
    cout<<"Check Whether Loop is Removed Or Not"<<endl;
    if (detectLoop(tail))
    {
        cout << "Cycle is present in List" << endl;
    }
    else
    {
        cout << "Cycle is not present in List" << endl;
    }
    return 0;
}
