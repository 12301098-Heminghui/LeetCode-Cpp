/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//原题链接：
// https://leetcode-cn.com/problems/sort-list/
// 题目要求用O(NlogN)的时间复杂度来实现链接的排序
// 数组通过下标进行访问，而链表与数组不同，只能通过指针移动来遍历
// 所以对于数组排序的7大算法，并不是都适合链表排序。
// 归并和快排都是基于递归的思想的，递归的做法对于链表也是适用的（定义两个指针，一个快一个慢，找到链表的中点，对排好序的左右两边的链表进行合并）
#include<vector>;
using namespace std;
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = NULL;
        //fast指针每次走两步，slow每次走一步，这样slow指针就是链表的中间位置
        while(fast != NULL && fast->next != NULL){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL; //将连接截成两段
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return merge(l1, l2);
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* newHead = new ListNode(0);
        ListNode* tmpHead = newHead;
        while(l1 != NULL && l2 != NULL){
            ListNode* tmp;
            if(l1->val <= l2->val){
                tmp = new ListNode(l1->val);
                l1 = l1->next;
            }else{
                tmp = new ListNode(l2->val);
                l2 = l2->next;
            }
            tmpHead->next = tmp;
            tmpHead = tmpHead->next;
        }
        if(l1 != NULL){
            tmpHead->next = l1;
        }
        if(l2 != NULL){
            tmpHead->next = l2;
        }
        return newHead->next;
    }
};
