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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !(head->next)) {
            return head;
        }
        ListNode* e_head = head->next;
        ListNode* o_temp = head;
        ListNode* e_temp = head->next;
        while(e_temp->next) {
            o_temp->next = o_temp->next->next;
            e_temp->next = e_temp->next->next;
            if(o_temp->next) {
                o_temp = o_temp->next;
            }
            if(e_temp->next) {
                e_temp = e_temp->next;
            }
        }
        o_temp->next = e_head;
        return head;
    }
};