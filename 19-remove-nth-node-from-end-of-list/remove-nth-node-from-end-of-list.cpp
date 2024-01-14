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
        if(!head) {
            return head;
        }
        int cnt=0;
        ListNode* curr = head;
        while(curr) {
            cnt++;
            curr = curr->next;
        }
        cnt -= n;
        if(!cnt) {
            head = head->next;
            return head;
        }
        curr = head;
        cnt--;
        while(cnt--) {
            curr = curr->next;
        }
        if(n==1) {
            curr->next = NULL;
            return head;
        }
        curr->next = curr->next->next;
        return head;
    }
};