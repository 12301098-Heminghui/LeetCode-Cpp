//原题链接：
// https://leetcode-cn.com/problems/insertion-sort-list/submissions/
//对链表进行插入排序
//注意点：需要设置tail指针，否则经过插入排序会出现环

#include<vector>
using namespace std;
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* tail = head;
        ListNode* curr = head->next;
        while(curr != NULL){
            if(tail->val > curr->val){
                cout << "before curr.val" << curr->val << endl;
                    ListNode* pre = newHead;
                    //从左往右遍历，找到一个合适的插入位置
                    while(pre->next && curr->val > pre->next->val){
                        pre = pre->next;
                        cout << "curr->val:" << curr->val << ", pre->next->val: " << pre->next->val << endl;
                    }
                    tail->next = curr->next;
                    curr->next = pre->next;
                    pre->next = curr;
                    curr = tail->next;
            }else{
                tail = tail->next;
                curr = tail->next;
            }
            
        }
        cout << "newHead->next->val: "<< newHead->next->val; 
        return newHead->next;
    }
};