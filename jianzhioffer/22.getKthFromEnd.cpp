/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 返回倒数第k个结点(k从1开始计数)
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head){
            return head;
        }
        if(k <= 0){
            return NULL;
        }
        ListNode* first = head;
        ListNode* second = head;
        while(k-1){
            // 如果k大于链表节点个数
            if(first){
                first = first->next;
            }else{
                return NULL;
            }
            k--;
        }
        while(first->next){
            first = first->next;
            second = second->next;
        }
        return second;
    }
};