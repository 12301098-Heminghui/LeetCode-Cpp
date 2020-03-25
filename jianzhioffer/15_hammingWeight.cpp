// 请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。
// 例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            if(n%2 == 1){
                cnt++;
            }
            n = n/2;
        }
        return cnt;
    }
};