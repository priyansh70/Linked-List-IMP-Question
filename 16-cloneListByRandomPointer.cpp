// Time Complexity - O(N)
// Space Complexity - O(1)

#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void print(Node *head)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void printByRandom(Node *head)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->random;
    }
    cout << endl;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (tail == NULL)
    {
        tail = temp;
        head = temp;
    }

    tail->next = temp;
    tail = temp;
}

Node *cloneLinkedList(Node *head)
{
    // step1 - create clone list
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *current = head;
    while (current != NULL)
    {
        insertAtTail(cloneHead, cloneTail, current->data);
        current = current->next;
    }

    // step2 - cloneNodes add in between original Nodes
    Node *cloneNode = cloneHead;
    Node *originalNode = head;

    while (originalNode)
    {
        Node *next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // step3 - random pointer copy

    current = head;
    while (current != NULL)
    {
        if (current->next)
            current->next->random = current->random ? current->random->next : current->random;

        current = current->next;
    }

    // step 4: revert step 2 changes
    cloneNode = cloneHead;
    originalNode = head;
    while (originalNode)
    {
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;

        if(originalNode)
            cloneNode -> next = originalNode -> next;
        cloneNode = cloneNode -> next;
    }

    // step5 - return ans node 
    return cloneHead;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 45);
    insertAtTail(head, tail, 34);
    insertAtTail(head, tail, 48);
    Node *current = head;
    while (current != NULL)
    {
        if (current->next)
            current->random = current->next->next;
        current = current->next;
    }

    cout << "Real Linked List" << endl;
    print(head);
    printByRandom(head);

    cout << "Clone Linked List" << endl;
    Node *cloneHead = cloneLinkedList(head);
    print(cloneHead);
    printByRandom(cloneHead);

    return 0;
}
