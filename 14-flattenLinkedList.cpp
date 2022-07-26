// Question Link - > https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
 Node* mergeTwoSortedList(Node* first,Node* second)
    {
        if(first == NULL)
            return second;
            
        if(second == NULL)
            return first;
            
        if(first -> data < second -> data)
        {
            first -> bottom = mergeTwoSortedList(first -> bottom, second);
            return first;
        }
        else
        {
            second -> bottom = mergeTwoSortedList(first, second -> bottom);
            return second;
        }
    }
Node *flatten(Node *root)
{
//   Base Case 
    if(root == NULL || root -> next == NULL)
    {
        return root;
    }
    
    Node* down = root;
    Node* right = flatten(root -> next);
    
    return mergeTwoSortedList(down,right);
}

