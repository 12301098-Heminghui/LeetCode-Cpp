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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(0);
        ListNode* node = newHead;
        while(l1 && l2){
            if(l1->val <= l2->val){
                ListNode* tmp = new ListNode(l1->val);
                newHead->next = tmp;
                l1 = l1->next;
                newHead = newHead->next;
            }else{
                ListNode* tmp = new ListNode(l2->val);
                newHead->next = tmp;
                l2 = l2->next;
                newHead = newHead->next;
            }
        }
        if(l1){
            newHead->next = l1;
        }
        if(l2){
            newHead->next = l2;
        }
        return node->next;
    }
};