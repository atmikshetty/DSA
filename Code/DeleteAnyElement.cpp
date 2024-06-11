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

Node *deleteElement(Node *head, int el)
{
    if(head == NULL) return NULL;
    if(head->val == el){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    Node* temp = head, prev=NULL;
    while(temp!=NULL){
        if(temp->val == el){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}
