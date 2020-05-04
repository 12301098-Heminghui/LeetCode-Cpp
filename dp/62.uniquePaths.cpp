// https://leetcode-cn.com/problems/unique-paths/
// 一个机器人从矩阵左上角走到右下角的路径

// 首先想的是递归的方式，提交超时
class Solution {

void helper(int start_x, int start_y, int &pathSum, int m, int n){
    if(start_x > n || start_y > m){
        return;
    }
    if(start_x == n-1 && start_y == m-1){
        pathSum++;
        return;
    }else{
        // 向右
        if(start_y+1 < m){
            helper(start_x, start_y+1, pathSum, m, n);
        }
        // 向下
        if(start_x+1 < n){
            helper(start_x+1, start_y, pathSum, m, n);
        }
    }
}
public:
    int uniquePaths(int m, int n) {
        int pathSum = 0;
        int start_x = 0;
        int start_y = 0;
        helper(start_x, start_y, pathSum, m, n);
        return pathSum;
    }
};


// 进一步思考这个题目，发现到达i,j位置依赖(i-1,j)和(i,j-1)这两个位置的路径方式
// 动态规划

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(n+1, vector<int>(m+1, 0));
        res[1][1] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                res[i][j] = max(res[i][j], res[i][j-1] + res[i-1][j]);
            }
        }
        return res[n][m];
    }
};

