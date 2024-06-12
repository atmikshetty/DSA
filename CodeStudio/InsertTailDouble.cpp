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

Node* insertAtTail(Node *head, int k) {
    // Write your code here.
    if(head->next==NULL){
        return insertAtFront(head,k);
    }

    Node* tail = head;
    while(tail->next!=NuLL){
        tail = tail -> next;
    }
    Node* front = tail;
    Node* back = tail->prev;
    Node* newNode = new Node(k,back, front);

    // Insert the node
    back->next = newNode;
    // newNode->prev = back;
    // newNode->next = front;
    front->prev = newNode;

    return head;
}