// https://leetcode-cn.com/problems/edit-distance/
// 求两个字符串的编辑距离，字符串中的字符可以进行删除、变更、新增三种操作
// 对问题分析后，会发现编辑距离其实可以拆解为子问题，于是可以采用动态规划来求解。
// 关键点：状态转移方程以及初始状态
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty()){
            return word2.size();
        }
        if(word2.empty()){
            return word1.size();
        }
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> res(n+1, vector<int>(m+1));
        // 初始化 word2为空时
        for(int i=0; i <= m; i++){
            res[0][i] = i;
        } 
        // 初始化 word1为空时
        for(int j=0; j <= n; j++){
            res[j][0] = j;
        }
        
        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                //如果当前两个字符相等，编辑距离就等于前面字符的编辑距离
                if(word2[i-1] == word1[j-1]){
                    res[i][j] = res[i-1][j-1];
                }else{
                    vector<int> tmp_vector = {res[i-1][j-1], res[i][j-1], res[i-1][j]};
                    auto min_pos = min_element(tmp_vector.begin(), tmp_vector.end());
                    res[i][j] = 1 + *min_pos;
                }
            }
        }
        return res[n][m];
    }
};
