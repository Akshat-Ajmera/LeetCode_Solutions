/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* curr1 = head;
        ListNode* curr2;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
            else return NULL;
            if(slow == fast) {
                curr2 = slow;
                break;
            }
        }
        if(!fast) return NULL;
        while(curr1 != curr2) {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return curr1;
    }
};