// https://leetcode-cn.com/problems/jump-game/
// 给定一维数组，每个元素代表从该位置能跳跃的最大长度。
// 判断从第0个位置开始，能否跳跃到最后一个位置

// python版

class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        end = 0
        length = len(nums)
        max_pos = 0
        for i in range(length):
            max_pos = max(max_pos, i+nums[i])
            #print max_pos,i+nums[i],end,i
            if i == end:
                end = max_pos
        if end >= length-1:
            return True
        return False