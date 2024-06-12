/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev=NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->next= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};
*/

Node * deleteTail(Node *head) {
    // Write your code here.
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* prev = head;
    while(prev->next !=NULL){
        prev = prev->next;
    }
    tail = prev->prev;
    tail->next = nullptr;
    prev->prev = nullptr;

    delete prev;
    return head;
}

