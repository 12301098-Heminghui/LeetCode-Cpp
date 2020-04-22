// https://leetcode-cn.com/problems/find-the-duplicate-number/

// 一个数组有n+1个元素，每个元素值在1到n之间(包括1和n)
// 存在一个重复的整数(重复次数可能不止1次)，找出这个重复的整数

// 二分查找法（抽屉原理：如果抽屉数量小于苹果数量，那一定会出现一个抽屉放多个苹果的情况）
// 在这个题里面，抽屉数量就是1到n的某个数val，苹果数量就是数组中元素值小于等于val的个数

class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 1
        right = len(nums)-1
        # 数组中的所有元素都在1到len(nums)-1之间
        while left < right:
            cnt = 0
            mid = left + (right-left)/2
            # 记录数组中值小于mid的元素个数
            for num in nums:
                if num <= mid:
                    cnt += 1
            if cnt > mid:
                right = mid
            else:
                left = mid+1
        return left
            