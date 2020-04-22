// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
// 删除链表的倒数第k个结点

// python版本
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        newHead = ListNode(0);
        newHead.next = head
        pre = newHead
        curr = head
        node_cnt = 0
        while curr:
            node_cnt += 1
            curr = curr.next
        # 考虑删除的是链表第一个元素(倒数第node_cnt个)
        n = node_cnt - n%node_cnt if n%node_cnt != 0 else 0
        curr = head
        while n:
            curr = curr.next
            pre = pre.next
            n -= 1
        pre.next = curr.next
        return newHead.next


// C++版本

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL){
            return head;
        }
        int node_cnt = 0;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* pre = newHead;
        ListNode* curr = head;
        while(curr){
            node_cnt++;
            curr = curr->next;
        }
        curr = head;
        int cnt = 0;
        if (n%node_cnt == 0){
            cnt = 0;
        }else{
            //计算删除节点是正数的第几个
            cnt = node_cnt - n%node_cnt;
        }
        // 找到要被删除的节点curr
        while(cnt){
            curr = curr->next;
            pre = pre->next;
            cnt--;
        }
        pre->next = curr->next;
        return newHead->next;

    }
};