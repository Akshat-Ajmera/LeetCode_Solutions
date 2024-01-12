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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode();
        ListNode* ans = curr;
        int a=0, b=0, c=0, s=0;
        while(l1 && l2) {
            a = l1->val, b = l2->val, s = (a+b+c)%10, c = (a+b+c)/10;
            ListNode* temp = new ListNode(s);
            curr->next = temp;
            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }
        while(l1) {
            a = l1->val, s = (a+c)%10, c = (a+c)/10;
            ListNode* temp = new ListNode(s);
            curr->next = temp;
            l1 = l1->next;
            curr = curr->next;
        }
        while(l2) {
            b = l2->val, s = (b+c)%10, c = (b+c)/10;;
            ListNode* temp = new ListNode(s);
            curr->next = temp;
            l2 = l2->next;
            curr = curr->next;
        }
        if(c) {
            ListNode* temp = new ListNode(c);
            curr->next = temp;
        }
        return ans->next;
    }
};