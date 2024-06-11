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

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
	if(head == NULL) return head;
	if(pos == 0){
		Node* temp = head;
		head = head -> next;
		delete temp;
		return head;
	}
	int count = 0;
	Node* temp=head;
	Node * prev=NULL;
	while(temp!=NULL){
		count++;
		if(count == pos+1){
			prev->next = prev->next->next;
			delete temp;
			break;
		}
		prev = temp;
		temp = temp -> next;
	}
	return head;
}
