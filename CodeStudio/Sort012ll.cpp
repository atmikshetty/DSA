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

Node* sortList(Node *head){
    // Write your code here.
    // // Brute Force(2N)
    // Node* temp = head;
    // vector<int> ans;
    // while(temp!=NULL){
    //     ans.push_back(temp->data);
    //     temp = temp ->next;
    // }
    // sort(ans.begin(), ans.end());
    // temp=head;
    // for(int i=0;i<ans.size();i++){
    //     temp->data = ans[i];
    //     temp = temp -> next;
    // }
    // return head;

    // Optimal
    if(head==NULL || head->next==NULL) return head;

    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    Node* temp = head;

    while(temp!=NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }else{
            two->next = temp;
            two = two->next;
        }
        temp = temp -> next;
    }

    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    one->next = twoHead->next;
    two->next = NULL;

    Node* newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;

}