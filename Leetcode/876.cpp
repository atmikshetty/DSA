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
public:
    ListNode* middleNode(ListNode* head) {
        // Brute O(N+N/2)
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        int index = (count/2)+1;
        temp=head;
        while(temp!=NULL){
            index--;
            if(index == 0) break;
            temp = temp -> next;
        }
        return temp;

        // Tortoise and Hare Algorithm 
        // Use SLow, Fast ptr, Odd goes to last, Even goes to null
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!= NULL){
            slow = slow->next; //move by 1
            fast = fast -> next-> next; //move by 2
        }
        return slow;
    }
};