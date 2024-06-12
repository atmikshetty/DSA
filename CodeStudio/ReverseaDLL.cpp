/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/
#include<bits/stdc++.h>

Node* reverseDLL(Node* head)
{   
    // Write your code here   
    // Brute O(2N)
    if(head==NULL || head->next == NULL){
        return head;
    }

    Node* temp = head;
    stack<int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp -> next;
    }

    temp = head;
    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;

    // Optimal O(N)
    if(head==NULL || head->next == NULL){
        return head;
    }

    Node* back = NULL;
    Node* curr = head;
    while(curr!=NULL){
        back = curr->prev;
        curr->prev = curr->next;
        curr->next = back;

        curr = curr -> prev;
    }
    return back->prev;
}

