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
    ListNode* reverseList(ListNode* curr) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* findKthNode(ListNode* curr, int k) {
        k--;
        while(curr && k > 0) {
            k--;
            curr = curr->next;
        }
        return curr;
    } 
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prevNode = NULL;
        while(curr) {
            ListNode* kthNode = findKthNode(curr, k);
            if(!kthNode) {
                if(prevNode) prevNode->next = curr;
                break;
            }
            else {
                ListNode* nextNode = kthNode->next;
                kthNode->next = NULL;
                reverseList(curr);
                if(curr == head) {
                    head = kthNode;
                }
                else {
                    prevNode->next = kthNode;
                }
                prevNode = curr;
                curr = nextNode;
            }
        }
        return head;
    }
};