class Solution {
public:
    int cuttingRope(int n) {
        //优先剪成长度为3的
        if(n <= 3) return n-1;
        long rs = 1;
        while (n > 4) {
            //3最优
            rs *= 3;
            rs %= 1000000007;
            n -= 3;
        }
        //n = 4,5,6,7,8,9,10
        //n = 4,2,3,4,2,3,4
        //只可能2 3 4，2，3不能再分了
        //4 可以分成1 * 3  2 * 2,所以还是4最优
        return (rs * n) % 1000000007;
    }
};