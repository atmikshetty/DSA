/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node* insertAtFront(Node *head, int k) {
    // Write your code here.
    if(head==NULL){
        Node* newHead = new Node(k);
        return newHead;
    }
    Node* newHead = new Node(k,nullptr,head);
    head->prev = newHead;
    return newHead;
}

Node* insertAtK(Node *head, int k) {
    // Write your code here.
    // Only when k==1
    if(k==1){
        return insertAtFront(head,k);
    }

    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        if(count==k) break;
        temp = temp -> next;
    }

    Node* prev = temp->prev;
    Node* newNode = new Node(k,prev,temp);
    prev -> next = newNode;
    temp->back = newNode;

    return head;
}