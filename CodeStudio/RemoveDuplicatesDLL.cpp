/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node* temp = head;
    while(temp!=NULL && temp->next !=NULL ){
        Node* nextNode = temp->next;
        while(nextNode!=NULL && nextNode->data == temp->data){
            Node* fake = nextNode;
            nextNode = nextNode -> next;
            delete fake;
        }
        temp -> next = nextNode;
        if(nextNode) nextNode->prev = temp;
        // delete temp;
        temp = temp->next;
    }
    return head;
}
