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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* z1 = new ListNode();
        vector<long long> v;
        int node_val = 0;
        while(curr) {
            node_val += curr->val;
            if(!(curr->val)) {
                v.push_back(node_val);
                node_val = 0;
            }
            curr = curr->next;
        }
        ListNode* head1 = new ListNode(v[0]);
        ListNode* temp1 = head1;
        for(int i=1; i<v.size(); i++) {
            ListNode* temp = new ListNode(v[i]);
            temp1->next = temp;
            temp1 = temp;
        }
        return head1;
    }
};