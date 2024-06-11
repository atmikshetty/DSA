/****************************************************************
 
    Following is the class structure of the Node class:

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

*****************************************************************/

Node *insertTail(Node *head, int val)
{
    if(head == NULL) return new Node(val);
    Node* temp = head;
    if(temp->next != NULL){
        temp = temp ->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}
