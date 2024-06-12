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

void insertBeforeNode(Node* node, int val){
    Node* back = node->prev;
    Node* newNode = new Node(val,back,node);
    back->next = newNode;
    node->prev  = newNode;
}