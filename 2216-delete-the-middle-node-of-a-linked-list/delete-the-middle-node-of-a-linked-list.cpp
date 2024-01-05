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
        if(!(head->next)) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* curr = head;
        while(fast) {
            fast = fast->next;
            if(!fast) {
                break;
            }
            curr = slow;
            slow = slow->next;
            fast = fast->next;
            if(!fast) {
                break;
            }
        }
        curr->next = slow->next;
        slow->next = NULL;
        delete slow;
        return head;
    }
};