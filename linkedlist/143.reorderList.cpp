
// https://leetcode-cn.com/problems/reorder-list/
// 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
// 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        node_cnt = 0
        tmpHead = head
        while tmpHead:
            node_cnt += 1
            tmpHead = tmpHead.next
        if node_cnt == 0 or node_cnt == 1:
            return head
        half = node_cnt/2
        tmpHead = head
        pre = None
        while half:
            pre = tmpHead
            tmpHead = tmpHead.next
            half -= 1

        if node_cnt%2 == 1:
            pre = tmpHead            
            tmpHead = tmpHead.next
        pre.next = None
        pre = None
        curr = tmpHead
        ## 反转
        while curr:
            next = curr.next
            curr.next = pre
            pre = curr
            curr = next
        print(pre.val)
        # 后半部分反转后的头结点 pre
        newHead = head
        next1 = newHead
        next2 = pre
        while next2:
            print('newHead.val=' + str(newHead.val) + '\n')
            print('pre.val=' + str(pre.val)+'\n')

            next1 = next1.next
            next2 = next2.next
            newHead.next = pre
            pre.next = next1
            pre = next2
            newHead = next1
        #pre.next = next1
        # if node_cnt%2 == 0:
        #     print 'newHead.next.next.val=' + str(newHead.next.next.val)

        #     newHead = None
        # else:
        #     newHead.next = None
        #     print(str(newHead.val) + '\n')
        return head

