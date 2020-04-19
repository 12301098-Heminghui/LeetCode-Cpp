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
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head){
            return head;
        }
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* pre = newHead;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            if(curr->val == val){
                pre->next = next;
                break;
            }
            curr = curr->next;
            pre = pre->next;
        }
        return newHead->next;
    }
};