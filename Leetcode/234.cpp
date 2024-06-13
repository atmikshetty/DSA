/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

ListNode* ReverseList(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* newHead  = ReverseList(head->next);
    ListNode* front = head ->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

public:
    bool isPalindrome(ListNode* head) {
        // // O(2N) O(N)
        // stack<int> st;
        // ListNode* temp = head;
        // while(temp!=NULL){
        //     st.push(temp->val);
        //     temp = temp->next;
        // }
        // temp=head;
        // while(temp!=NULL){
        //    if(temp->val != st.top()) return false;
        //    temp = temp->next;
        //    st.pop();
        // }
        // return true;

        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow will be the first middle element
        ListNode* newHead = ReverseList(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second!=NULL){
            if(first->val!=second->val){
                ReverseList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        ReverseList(newHead);
        return true;
    }
};