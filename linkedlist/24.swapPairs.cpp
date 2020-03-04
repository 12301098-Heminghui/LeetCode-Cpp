// https://leetcode-cn.com/problems/swap-nodes-in-pairs/
// 给定 1->2->3->4, 你应该返回 2->1->4->3. (两两交换相邻的节点)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 思路：定义两个指针，一个指向奇数位的节点p1，一个指针p2(为p1的Next节点)。p2和p1交换
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newHead = new ListNode(-1);
        
        ListNode* curr = newHead;
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        while(p2){
            ListNode* next = p2->next;
            curr->next = p2;
            p2->next = p1;
            curr = p1;
            p1 = next;
            if(p1){
                p2 = p1->next;
            }else{
                //curr->next = NULL;
                break;
            }
        }
        //此处是一个易忽视的细节
        // 1.(当p1为null时，curr的next需要指向空，否则出现循环)
        // 2.(当p1不为空时，p2可能为空，这是while循环结束后，curr指针需要指向p1)
        curr->next = p1;
        ListNode* tmp = newHead;

        while(tmp){   
            cout << tmp->val << endl;
            tmp = tmp->next;
        }
        return newHead->next;
    }
};