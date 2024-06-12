/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int val;
 *		Node *next;
 * 		Node *prev;
 *		Node() : val(0), next(nullptr), prev(nullptr){};
 *		Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *		Node(int x, Node *next, Node *prev) : val(x), next(next),
 *prev(prev) {}
 * };
 */

 Node * deleteHead(Node *head) {
    // Write your code here.
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* prev = head;
    head = head->next;

    head->prev = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node * deleteTail(Node *head) {
    // Write your code here.
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* prev = head;
    while(prev->next !=NULL){
        prev = prev->next;
    }
    Node* tail = prev->prev;
    tail->next = nullptr;
    prev->prev = nullptr;

    delete prev;
    return head;
}

Node *deleteNode(Node *head, int k) {
  // Write your code here
  if (head == NULL || head->next == NULL)
    return NULL;
  Node *temp = head;
  int count = 0;
  while (temp != NULL) {
    count++;
    if (count == k)
      break;
    temp = temp->next;
  }

//   Select the back and front nodes
  Node* prev = temp->prev;
  Node* front = temp -> next;

//   if only one element
if(prev == NULL && front == NULL){
    delete temp;
    return NULL;
}
// if at head
else if(prev == NULL) {
    return deleteHead(head);
}
// if at tail
else if (front == NULL){
    return deleteTail(head);
}

prev->next = front;
front->prev = prev;
temp->next = nullptr;
temp->prev = nullptr;
delete temp;
return head;

}