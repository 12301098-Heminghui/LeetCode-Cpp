// https://leetcode-cn.com/problems/rotate-list/
// 给定一个数k，让链表向右旋转k步

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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* tmp = head;
        while(tmp != NULL){
            tmp = tmp->next;
            len++;
        }
        if(len == 0){
            return head;
        }
        k = k%len;
        if(k == 0){
            return head;
        }
        ListNode* pHead = new ListNode(-1);
        pHead->next = head;
        tmp = head;
        //找到旋转节点(即新头结点的上一个节点)
        int step = len-k;
        while(step > 1){
            tmp = tmp->next;
            step--;
        }
        //找到链表的最后一个节点
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
        }
        pHead->next = tmp->next;
        tmp->next = NULL;
        tail->next = head;
        return pHead->next;
    }
};