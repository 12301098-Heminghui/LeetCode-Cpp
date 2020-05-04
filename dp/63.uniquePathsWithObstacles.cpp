// https://leetcode-cn.com/problems/unique-paths-ii/
// 机器人从左上角到达右下角的路径(中间有障碍物)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> res(m, vector<long>(n,0));
        res[0][0] = obstacleGrid[0][0]?0:1;

        for(int i=1; i < n; i++){
            res[0][i] = obstacleGrid[0][i]?0:res[0][i-1];
        }
        for(int i=1; i < m; i++){
            res[i][0] = obstacleGrid[i][0]?0:res[i-1][0];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j]){
                    res[i][j] = 0;
                }else{
                    res[i][j] = res[i-1][j] + res[i][j-1];
                }
            }
        }
        return (int)res[m-1][n-1];
    }
};