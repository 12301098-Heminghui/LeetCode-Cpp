
//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
// 每段绳子的长度记为 k[0],k[1]...k[m] 。请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？
// 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。


// 动态方程，python版
class Solution(object):
    def cuttingRope(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 定义一个动态方程数据
        dp = [0 for i in range(n+1)] #表示长度为i的绳子最大乘积
        dp[1] = 1
        dp[2] = 1
        for i in range(n+1):
            for j in range(1,i):
                dp[i] = max(dp[i],max(j*(i-j), j*dp[i-j]))
        return dp[n]

// 贪心法
