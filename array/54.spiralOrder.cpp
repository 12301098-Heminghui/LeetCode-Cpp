// https://leetcode-cn.com/problems/spiral-matrix/
// 顺时针打印螺旋矩阵

// python版
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        res = list()
        rows = len(matrix)
        if rows <= 0:
            return res
        cols = len(matrix[0])
        left = 0
        right = cols - 1
        up = 0
        down = rows - 1
        while left <= right and up <= down:
            print left,right,up,down
            # 上行
            for i in range(left, right+1):
                res.append(matrix[up][i])
            # 右列
            for i in range(up+1, down+1):
                res.append(matrix[i][right])
            # 下行
            if up < down:
                i = right - 1
                while i >= left:
                    res.append(matrix[down][i])
                    i -= 1
            # 左列
            if left < right:
                i = down - 1
                #print i,left
                #print '\n'
                while i > up:
                    res.append(matrix[i][left])
                    i -= 1
            left += 1
            right -= 1
            up += 1
            down -= 1
        return res
            
