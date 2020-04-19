// 200 https://leetcode-cn.com/problems/number-of-islands/

// 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

// 思路：组成的岛屿是陆地连通的。本题本质上是求形成的连通图有多少个。

// 深度优先的思想（python版）
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        def _dfs(i, j, row, col):
            if 0 <= i < row and 0 <= j < col and grid[i][j] == "1":
                #print('i='+str(i)+',j='+str(j)+'\n')
                grid[i][j] = "0"
            else:
                return
            for direction in directions:
                new_i = i + direction[0]
                new_j = j + direction[1]
                _dfs(new_i, new_j, row, col)

        row = len(grid)
        print(row)
        if row <= 0:
            return 0
        col = len(grid[0])
        islandNum = 0
        directions = [(-1,0),(1,0),(0,-1), (0,1)]

        for i in range(row):
            for j in range(col):
                if grid[i][j] == '1':
                    #print('i='+str(i)+',j='+str(j)+'\n')
                    islandNum += 1
                    _dfs(i, j, row, col)
        return islandNum

        
