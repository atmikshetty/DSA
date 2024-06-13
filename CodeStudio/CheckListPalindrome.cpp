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
#include<bits/stdc++.h>

Node* reverseList(Node *head){
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverseList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}


bool isPalindrome(Node *head)
{
    // write your code here
    // // O(2N) O(N)
    //     stack<int> st;
    //     Node* temp = head;
    //     while(temp!=NULL){
    //         st.push(temp->data);
    //         temp = temp->next;
    //     }
    //     temp=head;
    //     while(temp!=NULL){
    //        if(temp->data != st.top()) return false;
    //        temp = temp->next;
    //        st.pop();
    //     }
    //     return true;

    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverseList(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second!=NULL){
        if(first->data != second->data){
        reverseList(newHead);
        return false;
    }
    first = first->next;
    second = second -> next;
    }
    reverseList(newHead);
    return true;
}