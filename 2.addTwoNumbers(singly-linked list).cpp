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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *head = new ListNode(0);
        ListNode *pnode = head;
        int val = 0;
        while(l1 != NULL || l2 != NULL){
            if(l1 != NULL){
                val += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                val += l2->val;
                l2 = l2->next;
            }
            ListNode* node = new ListNode(val%10);
            pnode->next = node;
            pnode = node;
            val = val/10;
        }
        if(val >0){
           ListNode* node = new ListNode(val);
           pnode->next = node; 
        }
        return head->next;
    }
};