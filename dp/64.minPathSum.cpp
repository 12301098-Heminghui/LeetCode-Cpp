// https://leetcode-cn.com/problems/minimum-path-sum/
// 二维矩阵，从左上角到右下角的路径和（每次只能向下或者向右移动）

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=1; i < n; i++){
            grid[0][i] += grid[0][i-1];
        }
        for(int i=1; i < m; i++){
            grid[i][0] += grid[i-1][0];
        }
        for(int i=1; i < m; i++){
            for(int j=1; j < n; j++){
                grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
            }
        }
        return grid[m-1][n-1];
    }
};