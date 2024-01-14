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
        ListNode* fast = head;
        ListNode* slow = head;
        int cnt = n;
        while(cnt--) {
            fast = fast->next;
        }
        if(!fast) {
            return slow->next;
        }
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        if(n==1) {
            slow->next = NULL;
            return head;
        }
        slow->next = slow->next->next;
        return head;
    }
};