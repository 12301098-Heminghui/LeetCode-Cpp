// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
//  每 k 个节点一组进行翻转

// python版本
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        def reverseHelper(curr, k):
            tmpHead = curr
            node_cnt = 0
            while tmpHead:
                tmpHead = tmpHead.next
                node_cnt += 1
            if node_cnt < k:
                return [curr, None, None]
            else:
                node_cnt = k
                tail = curr
                pre = None
                while node_cnt:
                    next = curr.next
                    curr.next = pre
                    pre = curr
                    curr = next
                    node_cnt -= 1
                    # 返回元素：反转后的头结点、反转后的尾节点、下一段待反转的头结点
                #print pre.val, tail.val, curr.val
                return [pre, tail, curr]
        newHead = ListNode(0)
        tmpNewHead = newHead
        tmp = head
        if k <= 1:
            return head
        while tmp:
            res = reverseHelper(tmp, k)
            tmpNewHead.next = res[0]
            tmpNewHead = res[1]
            tmp = res[2]
        return newHead.next