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
    private:
        ListNode* divide(vector<ListNode*> lists, int lo, int hi) {
            if(lo > hi) return NULL;
            if(lo == hi) return lists[lo];
            int mid = (lo + ((hi - lo) / 2));
            ListNode* left = divide(lists, lo, mid);
            ListNode* right = divide(lists, mid + 1, hi);
            return conquer(left, right);
        }
        ListNode* conquer(ListNode* list1, ListNode* list2) {
            if(!list1) return list2;
            if(!list2) return list1;
            ListNode *head = new ListNode(), *tail = new ListNode();
            head = (list1 -> val < list2 -> val) ? list1 : list2;
            while (list1 && list2) {
                if (list1 -> val < list2 -> val) {
                    tail -> next = list1;
                    list1 = list1 -> next;
                }
                else {
                    tail -> next = list2;
                    list2 = list2 -> next;
                }
                tail = tail -> next;
            }
            tail -> next = list1 ? list1 : list2;
            return head;
        }
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            return divide(lists, 0, lists.size() - 1);
        }
    };