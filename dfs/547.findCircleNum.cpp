//https://leetcode-cn.com/problems/friend-circles/
// 一个N*N的数组，表示n个同学之间的关系（这个数组是一个对称数组）
// 如果同学间存在连接关系，可看做一个朋友圈。根据这个数组，返回这波同学一共有多少个朋友圈

// python版（dfs）
// 区分这个题目和LeetCode#200求岛屿数量那个题目
// 求岛屿数量是从一个地点出发，上下左右四个方向去连通
// 朋友圈这个题略有不同，连通性构成不同（朋友圈是通过数组的index去连通，岛屿是通过4个方向连通）
class Solution(object):
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        def _dfs(i,visited,n):
            # i能到达的朋友
            for j in range(n):
                if M[i][j] == 1 and visited[j] == 0:
                    visited[j] = 1
                    _dfs(j,visited, n)
            

        n = len(M)
        visited = [0]*n
        circleNum = 0
        for i in range(n):
            if visited[i] == 0:
                circleNum += 1
                _dfs(i, visited, n)
        return circleNum