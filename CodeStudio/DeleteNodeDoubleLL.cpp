/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val) {
            this->data = val;
            next = NULL;
            prev = NULL;
        }
    };

************************************************************/

void deleteNode(Node* node) {
    //Write your code here.
    Node* back = node->prev;
    Node* front = node -> next;

    // Tail
    if(front==NULL){
        back->next = nullptr;
        node->prev = nullptr;
        delete node;
        return;
    }
    // If both prev and front are present
    back->next = front;
    front->prev = back;
    node->next = nullptr;
    node->prev = nullptr;
    free(node);
}