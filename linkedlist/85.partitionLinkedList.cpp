// https://leetcode-cn.com/problems/partition-list/
// 给定一个链表和一个目标值，将链表中大于目标值的元素放到后面，小于目标值的元素放到前面

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 下面是我的思路：先创建一个哑结点newHead。
// 定义四个指针：curr指向当前遍历的结点，pre指向修改过curr的前结点，next指向修改前的curr的next结点。
//tmpHead指向较小元素的尾节点.
// 这个思路容易出现死循环的情况。这个bug我在3天里零零碎碎地修，于5月2号晚上7点40分才修好
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return head;
        }
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* tmpHead = newHead;
        ListNode* curr = head;//遍历链表，与x比较大小
        ListNode* pre = newHead;//curr的前一个节点，用来指向next节点
        ListNode* next;//暂存curr的下一个指针
        while(curr){
            next = curr->next;
            if(curr->val < x){
                if(curr != tmpHead->next){
                    if(curr == tmpHead->next->next){
                        tmpHead->next->next = NULL;
                    }
                    curr->next = tmpHead->next;
                }
                // 这个判断是避免pre指向头结点时，改变pre的next指针
                if(pre != newHead){
                    pre->next = next;
                }
                tmpHead->next = curr;
                tmpHead = curr;

            }else{
                pre = curr;
            }
            curr = next;
        }
        return newHead->next;
    }
};

// 官方解答:定义两个哑结点，分别指向链表的较小结点和较大结点。代码整体简洁易读。
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return head;
        }
        ListNode* minHead = new ListNode(0);
        ListNode* maxHead = new ListNode(0);
        ListNode* minNode = minHead;
        ListNode* maxNode = maxHead;
        while(head){
            ListNode* node = new ListNode(head->val);
            if(head->val < x){
                minNode->next = node;
                minNode = minNode->next;
            }else{
                maxNode->next = node;
                maxNode = maxNode->next;
            }
            head = head->next;

        }
        ListNode* minTail = minHead;
        minNode = minHead;
        while(minNode){
            minTail = minNode;
            minNode = minNode->next;
        }
        minTail->next = maxHead->next;
        return minHead->next;
    }
};