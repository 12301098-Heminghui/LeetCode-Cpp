//原题链接：
// https://leetcode-cn.com/problems/unique-binary-search-trees/

// 题目：给定一个数字n，用1到n的数字构造二叉搜索树。返回这样的树的个数
// 思路：选定一个数作为根节点后，能构造的二叉搜索树等于左子树数*右子树数
// 用F(i,n)表示以i作为根节点，树的节点数为n的二叉搜索树数量
// 用G(n)表示节点数为n的二叉搜索树数量。则G(n) = sum(F(i,n)) for i in [1, n]
// F(i,n)怎么求呢？
// 根据二叉搜索树的性质，以i为根节点的左子树由[1,i-1]区间的数字构建，以i为根节点的右子树由[i+1,n]之间的数组构建
// 即 F(i,n) = G(i-1)*G(n-i) 由于G(n) = sum( G(i-1) * G(n-i) )

#include<vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j=1; j <= i; j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
