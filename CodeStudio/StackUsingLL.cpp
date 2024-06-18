/****************************************************************

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


*****************************************************************/

class Stack
{
    //Write your code here

public:
    Node* top;
    Stack()
    {
        //Write your code here
        top = NULL;
        }

    int getSize()
    {
        //Write your code here
        Node* temp = top;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool isEmpty()
    {
        //Write your code here
        if(top==NULL) return true;
        else return false;
    }

    void push(int data)
    {
        //Write your code here
        Node* temp = new Node(data);
        temp-> data = data;
        temp->next = top; // at first for O(1)
        top = temp;
    }

    void pop()
    {
        //Write your code here
        Node* temp;
        if(top != NULL){
            temp = top;
            top = top -> next;
            delete temp;
        }
    }

    int getTop()
    {
        //Write your code here
        if(top == NULL) return -1;
        else return top->data;
    }
};