// 翻转链表

class Solution {
public:
    bool ishuiwen(ListNode* head) {
        if(!head){
            return true;
        }
        int cnt = 0;
        ListNode* node = head;
        while(node){
            node = node->next;
            cnt ++;
        }
        ListNode* left = NULL;
        ListNode* pre = head;
        int step = 0;
        while(step < cnt/2){
            ListNode* next = pre->next;
            pre->next = left;
            left = pre;
            pre = next;
            step++;
        }
        ListNode* right = NULL;
        if(cnt/2 == 1){
            right = pre->next;
        }else{
            right = pre;
        }
        while(left && right){
            if(left->val == right->val){
                left = left->next;
                right = right->next;
            }else{
                return false;
            }
        }
        if(left || right){
                return false;
        }
        return true;       
    }
};
