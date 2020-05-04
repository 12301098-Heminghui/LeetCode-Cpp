// https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/submissions/

// 单链表转二叉搜索树

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
TreeNode* helper(ListNode* node){
    ListNode* slow = node;;
    ListNode* fast = node;
    ListNode* pre = node;
    if(node == NULL){
        return NULL;
    }
    if(node->next == NULL){
        return new TreeNode(node->val);
    }
    cout << "node="<<node->val<<endl;
    while(fast && fast->next){
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;
    TreeNode* treeNode = new TreeNode(slow->val);
    treeNode->left = helper(node);
    treeNode->right = helper(slow->next);
    return treeNode;
}
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return new TreeNode(head->val);
        }
        ListNode* slow = head;;
        ListNode* fast = head;
        ListNode* pre = head;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        TreeNode* treeNode = new TreeNode(slow->val);
        cout << "head="<<head->val << ",slow="<<slow->val<<endl;

        treeNode->left = helper(head);
        treeNode->right = helper(slow->next);
        return treeNode;
    }
};