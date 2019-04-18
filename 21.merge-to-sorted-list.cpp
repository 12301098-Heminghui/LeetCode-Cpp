
#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1){
            return l2;
        }else if(!l2){
            return l1;
        }else{
            ListNode retNode(INT_MAX);
            ListNode* moveNode = &retNode;
            while(l1 && l2) {
                if (l1->val < l2->val){
                    moveNode->next = l1;
                    l1 = l1->next;
                }else{
                    moveNode->next = l2;
                    l2 = l2->next;
                }
                moveNode = moveNode->next;
            }
            moveNode->next = l1? l1:l2;
            return retNode.next;
        }
    }
};

