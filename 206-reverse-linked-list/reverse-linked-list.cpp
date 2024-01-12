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
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next)) {
            return head;
        }
        ListNode* prevNode = NULL;
        ListNode* nextNode = head->next;
        ListNode* curr = head;
        while(nextNode) {
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
            nextNode = nextNode->next;
        }
        curr->next = prevNode;
        return curr;
    }
};