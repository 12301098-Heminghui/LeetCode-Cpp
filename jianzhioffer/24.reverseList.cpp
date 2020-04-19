/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* curr = NULL;
        ListNode* pre = head;
        while(pre){
            ListNode* next = pre->next;
            pre->next = curr;
            curr = pre;
            pre = next;
        }
        return curr;
    }
};