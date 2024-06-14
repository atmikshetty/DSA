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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Brute force O(2xlength)
        if (head == NULL)
            return head;
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        if (count == n) { // head is to be deleted
            ListNode* newHead = head->next;
            delete (head);
            return newHead;
        }
        int res = count - n;
        temp = head;
        while (temp != NULL) {
            res--;
            if (res == 0) {
                break;
            }
            temp = temp->next;
        }
        ListNode* deleteNode = temp->next;
        temp->next = temp->next->next;
        delete (deleteNode);
        return head;

        // directly select the node to be deleted  O(length)
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0;i<n;i++) fast = fast -> next;
        if(fast == NULL) return head->next;
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow -> next;
        }
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete(deleteNode);
        return head;
    }
};