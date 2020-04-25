// https://leetcode-cn.com/problems/merge-k-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode* newHead = new ListNode(0);
    ListNode* tmpHead = newHead;
    while(l1 && l2){
        ListNode* node;
        if(l1->val <= l2->val){
            node = new ListNode(l1->val);
            l1 = l1->next;
        }else{
            node = new ListNode(l2->val);
            l2 = l2->next;
        }
        tmpHead->next = node;
        tmpHead = tmpHead->next;
    }
    if(l1){
        tmpHead->next = l1;
    }
    if(l2){
        tmpHead->next = l2;
    }
    return newHead->next;
}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k <=0){
            return NULL;
        }
        if(k == 1){
            return lists[0];
        }
        ListNode* newHead = new ListNode(0);
        int interval = 1;
        // 两两合并
        while(interval < k){
            for(int i = 0; i+interval < k; i=i+interval){
                lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
            }
            interval *= 2;
        }
        
        return lists[0];
    }
};