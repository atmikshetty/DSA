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
    ListNode* deleteMiddle(ListNode* head) {
        // // O(N + N/2)
        // if (head == NULL || head->next == NULL)
        //     return NULL;
        // ListNode* temp = head;
        // int count = 0;
        // while (temp != NULL) {
        //     count++;
        //     temp = temp->next;
        // }
        // int middle = count / 2;
        // temp = head;
        // while (temp != NULL) {
        //     middle--;
        //     if (middle == 0) {
        //         ListNode* deleteNode = temp->next;
        //         temp->next = temp->next->next;
        //         delete (deleteNode);
        //         break;
        //     }
        //     temp = temp->next;
        // }
        // return head;

        if (head == NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        fast = head->next->next; // skip one step
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};