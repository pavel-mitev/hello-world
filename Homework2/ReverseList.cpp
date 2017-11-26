/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    if(!head) return NULL;
    
    Node* temp = head;
    Node* newHead = head;
    while(temp != NULL)
    {
        Node* prev = temp->prev;
        temp->prev = temp->next;
        temp->next = prev;
        newHead = temp;
        temp = temp->prev;
    }
    return newHead;
}
