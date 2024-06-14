/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    if(head == NULL) return head;
    Node* fast = head;
    Node* slow = head;
    for(int i=0;i<K;i++) fast = fast -> next;
    if(fast == NULL) return head->next;
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete(deleteNode);
    return head;
}
