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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> v(m,vector<int> (n,-1));
        int top=0, bottom=m-1, left=0, right=n-1;
        while(head) {
            for(int i=left; i<=right && head; i++) {
                v[top][i] = head->val;
                head = head->next;
            }
            top++;
            for(int i=top; i<=bottom && head; i++) {
                v[i][right] = head->val;
                head = head->next;
            }
            right--;
            for(int i=right; i>=left && head; i--) {
                v[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;
            for(int i=bottom; i>=top && head; i--) {
                v[i][left] = head->val;
                head = head->next;
            }
            left++;
        }
        return v;
    }
};