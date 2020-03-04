// https://leetcode-cn.com/problems/rotate-image/
// 题目要求在原数组中旋转（顺时针旋转90度）


// 方法一：先沿水平中线上下翻转（-180° +−180°+ 一次镜像），可以实现顺时针 90度的旋转效果
// 再沿右上 - 左下的对角线翻转（270° +270°+ 一次镜像）
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 先上下翻折
        for(int i=0; i < n/2; i++){
            for(int j = 0; j < n; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-i][j];
                matrix[n-1-i][j] = tmp;
            }
        }
        //把右上角的翻转到左下角，左下角翻转到右上角
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};

// 方法二：